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
          m_documentModel(nullptr)
        {
          m_ui->setupUi(this);
        }

      CMainWindow::~CMainWindow() {
        delete m_ui;
      }

      void CMainWindow::injectWith(SDF::ModelLayer::Iface::IDocumentModel *documentModel) {
        m_documentModel = documentModel;
      }

      // Private members.
      void CMainWindow::on_action_New_triggered() {
        assert(m_documentModel != nullptr);

        Impl::Qt::Dialogs::CNewDocumentDialog dialog(this);
        m_documentModel->injectDocumentMeasurementsService(&dialog);
        dialog.exec();
      }
    }
  }
}
