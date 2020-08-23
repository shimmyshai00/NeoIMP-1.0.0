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
#include <SDF/ModelLayer/Iface/IDocumentServiceDependency.hpp>
#include <SDF/ModelLayer/Iface/IDocumentMeasurementsServiceDependency.hpp>
#include <SDF/ModelLayer/Iface/IDocumentService.hpp>
#include <SDF/ModelLayer/Iface/IDocumentMeasurementsService.hpp>
#include <SDF/ModelLayer/Iface/DocumentHandle.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace SDF::UILayer {
  namespace Impl {
    namespace Qt::Windows {
      class CMainWindow : public QMainWindow,
      public SDF::ModelLayer::Iface::IDocumentServiceDependency,
      public SDF::ModelLayer::Iface::IDocumentMeasurementsServiceDependency {
        Q_OBJECT
      public:
        CMainWindow(QWidget *parent = nullptr);
        ~CMainWindow();

        void injectWith(SDF::ModelLayer::Iface::IDocumentService *documentService);
        void injectWith(SDF::ModelLayer::Iface::IDocumentMeasurementsService *service);
      private slots:
        void on_action_New_triggered();
      private:
        Ui::MainWindow *m_ui;

        SDF::ModelLayer::Iface::IDocumentService *m_documentService;
        SDF::ModelLayer::Iface::IDocumentMeasurementsService *m_documentMeasurementsService;

        std::vector<SDF::ModelLayer::Iface::DocumentHandle> m_openDocumentHandles;
      };
    }
  }
}

#endif
