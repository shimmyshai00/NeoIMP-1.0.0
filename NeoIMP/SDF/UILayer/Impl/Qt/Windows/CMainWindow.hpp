#ifndef SDF_UILAYER_VIEWS_IMPL_QT_WINDOWS_CMAINWINDOW_HPP
#define SDF_UILAYER_VIEWS_IMPL_QT_WINDOWS_CMAINWINDOW_HPP

/*
 * NeoIMP version 1.0.0
 * (C) 2020 The Shining Destiny Foundation. All rights reserved.
 * Licensed under GPLv3 and MPL. See COPYING for details.
 *
 * FILE:    CMainWindow.hpp
 * PURPOSE: The Qt main program window.
 */

#include <QMainWindow>
#include <SDF/ModelLayer/Iface/IDocumentModelDependency.hpp>
#include <SDF/ModelLayer/Iface/IDocumentModel.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace SDF::UILayer {
  namespace Impl {
    namespace Qt::Windows {
      class CMainWindow : public QMainWindow, public SDF::ModelLayer::Iface::IDocumentModelDependency {
        Q_OBJECT
      public:
        CMainWindow(QWidget *parent = nullptr);
        ~CMainWindow();

        void injectWith(SDF::ModelLayer::Iface::IDocumentModel *documentModel);
      private slots:
        void on_action_New_triggered();
      private:
        Ui::MainWindow *m_ui;
        SDF::ModelLayer::Iface::IDocumentModel *m_documentModel;
      };
    }
  }
}

#endif
