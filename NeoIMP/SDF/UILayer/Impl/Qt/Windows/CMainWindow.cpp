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
#include <SDF/ModelLayer/DocumentModel/include/Spec/SDocumentSpec.hpp>

#include <Impl/Qt/Dialogs/CNewDocumentDialog.hpp>
#include <Impl/Qt/CustomWidgets/CImageEditor.hpp>

#include <iostream>

namespace SDF {
  namespace UILayer {
    namespace Impl::Qt::Windows {
      CMainWindow::CMainWindow(QWidget *parent)
      : QMainWindow(parent),
        m_ui(new Ui::MainWindow),
        m_documentModel(nullptr)
        {
          m_ui->setupUi(this);
        }

      CMainWindow::~CMainWindow() {
        delete m_ui;
      }

      void CMainWindow::injectWith(ModelLayer::DocumentModel::IDocumentModel *documentModel) {
        m_documentModel = documentModel;
      }

      // Private member.
      void CMainWindow::on_action_New_triggered() {
        assert(m_documentModel != nullptr);

        Dialogs::CNewDocumentDialog newDocumentDialog;
        m_documentModel->injectDocumentMeasurementsService(newDocumentDialog);
        newDocumentDialog.exec();

        addDocument("Untitled 1", ModelLayer::DocumentModel::Spec::SDocumentSpec());
      }

      // Private members.
      void CMainWindow::addDocument(std::string fileName, ModelLayer::DocumentModel::Spec::SDocumentSpec spec) {
        int newTabIdx(m_ui->tabWidget->addTab(new CustomWidgets::CImageEditor, QString(fileName.c_str())));
        m_ui->tabWidget->setCurrentIndex(newTabIdx);
      }
    }
  }
}
