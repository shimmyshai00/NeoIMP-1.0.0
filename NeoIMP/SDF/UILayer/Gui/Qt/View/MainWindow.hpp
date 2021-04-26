#ifndef SDF_UILAYER_GUI_QT_VIEW_MAINWINDOW_HPP
#define SDF_UILAYER_GUI_QT_VIEW_MAINWINDOW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainWindow.hpp
 * PURPOSE: Defines the MainWindow class.
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <SDF/Interfaces/IEventHandler.hpp>
#include <SDF/Interfaces/IBorrowedFactory.hpp>

#include <SDF/UILayer/Gui/IGuiElement.hpp>

#include <SDF/UILayer/Gui/Qt/Events/GuiEvent.hpp>
#include <SDF/UILayer/AbstractModel/Events/UiStateChangeEvent.hpp>
#include <SDF/UILayer/AbstractModel/Events/DocumentEvent.hpp>

#include <QWidget>
#include <QMainWindow>
#include <QDockWidget>
#include <QTabWidget>

#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace SDF::UILayer {
  namespace AbstractModel {
    class IDocumentAccessService;

    template<class StateT>
    class IUiStateModelService;
  }

  namespace Gui {
    class IGuiController;

    namespace Qt::View {
      // Class:      MainWindow
      // Purpose:    Provides the main application window.
      // Parameters: None.
      class MainWindow : public QMainWindow,
                         public IGuiElement,
                         public Interfaces::IEventHandler<AbstractModel::Events::UiStateChangeEvent<bool>>,
                         public Interfaces::IEventHandler<AbstractModel::Events::DocumentEvent>
      {
      public:
        MainWindow(AbstractModel::IDocumentAccessService *documentAccessService,
                   AbstractModel::IUiStateModelService<bool> *boolStateModelService,
                   std::unique_ptr<Interfaces::IBorrowedFactory<IGuiElement, IGuiElement *, std::string>>
                    dockablesFactory,
                   std::unique_ptr<Interfaces::IBorrowedFactory<IGuiElement, IGuiElement *, AbstractModel::Handle>>
                    documentViewFactory,
                   std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> controller,
                   QWidget *parent = nullptr
                  );
        ~MainWindow();

        IGuiElement *
        getParent();

        void
        show();

        void
        close();

        void
        handleEvent(std::shared_ptr<AbstractModel::Events::UiStateChangeEvent<bool>> event);

        void
        handleEvent(std::shared_ptr<AbstractModel::Events::DocumentEvent> event);
      private:
        Ui::MainWindow *m_ui;

        std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> m_controller;

        AbstractModel::IDocumentAccessService *m_documentAccessService;
        AbstractModel::IUiStateModelService<bool> *m_boolStateModelService;

        std::unique_ptr<Interfaces::IBorrowedFactory<IGuiElement, IGuiElement *, std::string>>
         m_dockablesFactory;
        std::unique_ptr<Interfaces::IBorrowedFactory<IGuiElement, IGuiElement *, AbstractModel::Handle>>
          m_documentViewFactory;

        QDockWidget *m_toolchest;
        QTabWidget *m_tabs;

        void
        showToolchest();

        void
        hideToolchest();

        void
        addDocumentTab(AbstractModel::Handle handle);

        void
        handleDocumentCreated(AbstractModel::Events::DocumentCreated *event);

        void
        handleDocumentOpened(AbstractModel::Events::DocumentOpened *event);
      };
    }
  }
}

#endif
