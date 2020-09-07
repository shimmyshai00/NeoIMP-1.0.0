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

#include <Error/IErrorReporter.hpp>

#include <SDF/ModelLayer/DocumentModel/include/IDocumentModelDependency.hpp>
#include <SDF/ModelLayer/DocumentModel/include/Services/IDocumentServiceDependency.hpp>
#include <SDF/ModelLayer/DocumentModel/include/Services/IDocumentImageDataServiceDependency.hpp>
#include <SDF/ModelLayer/DocumentModel/include/DocumentHandle.hpp>

#include <Impl/Qt/Windows/CDocument.hpp>

#include <QMainWindow>
#include <QString>

#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Spec {
        struct SDocumentSpec;
      }

      namespace Services {
        class IDocumentService;
        class IDocumentImageDataService;
      }

      class IDocumentModel;
    }
  }

  namespace UILayer {
    namespace Error {
      class IErrorReporter;
    }

    namespace Impl::Qt::Windows {
      class CDocument;

      class CMainWindow : public QMainWindow, public ModelLayer::DocumentModel::IDocumentModelDependency,
      private ModelLayer::DocumentModel::Services::IDocumentServiceDependency,
      private ModelLayer::DocumentModel::Services::IDocumentImageDataServiceDependency {
        Q_OBJECT
      public:
        CMainWindow(QWidget *parent = nullptr, UILayer::Error::IErrorReporter *errorReporter = nullptr);
        ~CMainWindow();

        void injectWith(ModelLayer::DocumentModel::IDocumentModel *documentModel);
      private:
        void injectWith(ModelLayer::DocumentModel::Services::IDocumentService *service);
        void injectWith(ModelLayer::DocumentModel::Services::IDocumentImageDataService *service);
      private slots:
        void on_action_New_triggered();
      private:
        Ui::MainWindow *m_ui;

        UILayer::Error::IErrorReporter *m_errorReporter;

        ModelLayer::DocumentModel::IDocumentModel *m_documentModel;
        ModelLayer::DocumentModel::Services::IDocumentService *m_documentService;
        ModelLayer::DocumentModel::Services::IDocumentImageDataService *m_documentImageDataService;

        int m_newDocumentCounter;
        std::vector<std::unique_ptr<CDocument>> m_openDocuments;

        void addNewDocument(ModelLayer::DocumentModel::Spec::SDocumentSpec spec);
      };
    }
  }
}

#endif
