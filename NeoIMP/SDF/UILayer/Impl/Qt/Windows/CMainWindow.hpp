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

#include <SDF/ModelLayer/DocumentModel/include/IDocumentModelDependency.hpp>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Spec {
        struct SDocumentSpec;
      }
      
      class IDocumentModel;
    }
  }

  namespace UILayer {
    namespace Impl::Qt::Windows {
      class CMainWindow : public QMainWindow, public ModelLayer::DocumentModel::IDocumentModelDependency {
        Q_OBJECT
      public:
        CMainWindow(QWidget *parent = nullptr);
        ~CMainWindow();

        void injectWith(ModelLayer::DocumentModel::IDocumentModel *documentModel);
      private slots:
        void on_action_New_triggered();
      private:
        Ui::MainWindow *m_ui;
        ModelLayer::DocumentModel::IDocumentModel *m_documentModel;

        void addDocument(std::string fileName, ModelLayer::DocumentModel::Spec::SDocumentSpec spec);
      };
    }
  }
}

#endif
