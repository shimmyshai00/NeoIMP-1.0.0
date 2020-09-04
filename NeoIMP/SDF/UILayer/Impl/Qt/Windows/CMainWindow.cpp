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
#include <Impl/Qt/Dialogs/CNewDocumentDialog.hpp>

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
      }
    }
  }
}
