/*
 * NeoIMP version 1.0.0
 * (C) 2020 The Shining Destiny Foundation. All rights reserved.
 * Licensed under GPLv3 and MPL. See COPYING for details.
 *
 * FILE:    CMainWindow.cpp
 * PURPOSE: The Qt main program window implementation.
 */

#include <Impl/Qt/Windows/CMainWindow.hpp>
#include <ui_MainWindow.h>

#include <SDF/ModelLayer/DocumentModel/include/IDocumentModel.hpp>
#include <SDF/ModelLayer/DocumentModel/include/Services/IDocumentService.hpp>
#include <SDF/ModelLayer/DocumentModel/include/Services/IDocumentImageDataService.hpp>
#include <SDF/ModelLayer/DocumentModel/include/Spec/SDocumentSpec.hpp>

#include <Impl/Qt/Dialogs/CNewDocumentDialog.hpp>
#include <Impl/Qt/CustomWidgets/CImageEditor.hpp>

#include <iostream>

namespace SDF {
  namespace UILayer {
    namespace Impl::Qt::Windows {
      CMainWindow::CMainWindow(QWidget *parent, UILayer::Error::IErrorReporter *errorReporter)
      : QMainWindow(parent),
        m_ui(new Ui::MainWindow),
        m_errorReporter(errorReporter),
        m_documentModel(nullptr),
        m_documentService(nullptr),
        m_documentImageDataService(nullptr),
        m_newDocumentCounter(1)
        {
          m_ui->setupUi(this);
        }

      CMainWindow::~CMainWindow() {
        delete m_ui;
      }

      void CMainWindow::injectWith(ModelLayer::DocumentModel::IDocumentModel *documentModel) {
        m_documentModel = documentModel;

        m_documentModel->injectDocumentService(*this);
        m_documentModel->injectDocumentImageDataService(*this);
      }

      // Private members.
      void CMainWindow::injectWith(ModelLayer::DocumentModel::Services::IDocumentService *service) {
        m_documentService = service;
      }

      void CMainWindow::injectWith(ModelLayer::DocumentModel::Services::IDocumentImageDataService *service) {
        m_documentImageDataService = service;
      }

      // Private member.
      void CMainWindow::on_action_New_triggered() {
        using namespace ModelLayer::DocumentModel;

        assert(m_documentModel != nullptr);

        Dialogs::CNewDocumentDialog newDocumentDialog;
        m_documentModel->injectDocumentMeasurementsService(newDocumentDialog);
        newDocumentDialog.exec();

        addNewDocument(newDocumentDialog.getDocumentSpec());
      }

      // Private members.
      void CMainWindow::addNewDocument(ModelLayer::DocumentModel::Spec::SDocumentSpec spec) {
        using namespace ModelLayer::DocumentModel;

        assert(m_documentService != nullptr);
        assert(m_documentImageDataService != nullptr);

        try {
          // Call the model methods to create the new document.
          DocumentHandle handle(m_documentService->createDocument(spec));

          // Put it into the window.
          std::string newDocumentFileName("Untitled " + std::to_string(m_newDocumentCounter++));
          m_openDocuments.push_back(std::make_unique<CDocument>(newDocumentFileName, handle));
          m_openDocuments.back()->injectWith(m_documentImageDataService);
          m_openDocuments.back()->addTabTo(m_ui->tabWidget);
        } catch(Services::IDocumentService::DocumentSizeTooBigException &e) {
          if(m_errorReporter != nullptr) m_errorReporter->reportError(e.what());
        } catch(Services::IDocumentService::BadDocumentSizeException &e) {
          if(m_errorReporter != nullptr) m_errorReporter->reportError(e.what());
        } catch(Services::IDocumentService::BadDocumentResolutionException &e) {
          if(m_errorReporter != nullptr) m_errorReporter->reportError(e.what());
        }
      }
    }
  }
}
