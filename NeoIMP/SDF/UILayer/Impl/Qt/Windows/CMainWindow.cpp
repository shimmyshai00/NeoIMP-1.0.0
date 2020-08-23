/*
 * NeoIMP version 1.0.0
 * (C) 2020 The Shining Destiny Foundation. All rights reserved.
 * Licensed under GPLv3 and MPL. See COPYING for details.
 *
 * FILE:    CMainWindow.cpp
 * PURPOSE: The Qt main program window implementation.
 */

#include <Impl/Qt/Windows/CMainWindow.hpp>
#include <Impl/Qt/Dialogs/CNewDocumentDialog.hpp>
#include <ui_MainWindow.h>

#include <iostream>

namespace SDF::UILayer {
  namespace Impl {
    namespace Qt::Windows {
      CMainWindow::CMainWindow(QWidget *parent)
        : QMainWindow(parent),
          m_ui(new Ui::MainWindow),
          m_documentService(nullptr),
          m_documentMeasurementsService(nullptr)
        {
          m_ui->setupUi(this);
        }

      CMainWindow::~CMainWindow() {
        delete m_ui;
      }

      void CMainWindow::injectWith(SDF::ModelLayer::Iface::IDocumentService *documentService) {
        m_documentService = documentService;
      }

      void CMainWindow::injectWith(SDF::ModelLayer::Iface::IDocumentMeasurementsService *service) {
        m_documentMeasurementsService = service;
      }

      // Private members.
      void CMainWindow::on_action_New_triggered() {
        using namespace SDF::ModelLayer::Iface;

        assert(m_documentService != nullptr);
        assert(m_documentMeasurementsService != nullptr);

        Dialogs::CNewDocumentDialog dialog(this);
        dialog.injectWith(m_documentMeasurementsService);
        dialog.exec();

        if(dialog.result() == QDialog::Accepted) {
          DocumentHandle handle(m_documentService->createDocument(dialog.getDocumentSpec()));
          m_openDocumentHandles.push_back(handle);
        }
      }
    }
  }
}
