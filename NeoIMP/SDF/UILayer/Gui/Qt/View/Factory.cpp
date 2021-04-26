/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Factory.cpp
 * PURPOSE: Implements the Factory class.
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

#include <SDF/UILayer/Gui/Qt/View/Factory.hpp>

#include <SDF/UILayer/Exceptions/Exceptions.hpp>

#include <SDF/UILayer/AbstractModel/IDocumentAccessService.hpp>
#include <SDF/UILayer/AbstractModel/IDocumentRenderService.hpp>
#include <SDF/UILayer/AbstractModel/IUiStateModelService.hpp>

#include <MainWindow.hpp>
#include <NewDocumentDialog.hpp>
#include <FileDialog.hpp>
#include <DocumentView.hpp>
#include <Toolbox.hpp>

namespace SDF::UILayer::Gui::Qt::View {
  Factory::Factory(
    std::unique_ptr<Interfaces::IFactory<Interfaces::IEventHandler<Events::GuiEvent>, std::string>> controllerFactory,
    AbstractModel::IDocumentAccessService *documentAccessService,
    AbstractModel::IDocumentRenderService *documentRenderService,
    AbstractModel::IUiStateModelService<bool> *boolStateModelService
  )
    : m_controllerFactory(std::move(controllerFactory)),
      m_documentAccessService(documentAccessService),
      m_documentRenderService(documentRenderService),
      m_boolStateModelService(boolStateModelService)
  {}

  IGuiElement *
  Factory::create(IGuiElement *parent, std::string elementType) {
    std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> controller(m_controllerFactory->create(elementType));

    if(elementType == "MainWindow") {
      MainWindow *rv(new MainWindow(m_documentAccessService,
                                    m_boolStateModelService,
                                    std::make_unique<DockablesFactory>(),
                                    std::make_unique<DocumentViewFactory>(m_documentAccessService,
                                                                          m_documentRenderService
                                                                        ),
                                    std::move(controller),
                                    dynamic_cast<QWidget *>(parent)
                                   ));
      m_documentAccessService->attachObserver(rv); // NB: need some safe way to disconnect this on destruction in
                                                   //     general cases
      m_boolStateModelService->attachObserver(rv); // NB: same
      return rv;
    } else if(elementType == "NewDocumentDialog") {
      return new NewDocumentDialog(std::move(controller), dynamic_cast<QWidget *>(parent));
    } else if(elementType == "SaveAsDialog") {
      return new FileDialog(std::move(controller), "Save As", QFileDialog::AcceptSave, dynamic_cast<QWidget *>(parent));
    } else if(elementType == "OpenDialog") {
      return new FileDialog(std::move(controller), "Open", QFileDialog::AcceptOpen, dynamic_cast<QWidget *>(parent));
    } else {
      //throw UILayer::Exceptions::NonexistentGuiElementTypeException(elementType);
    }
  }
}

namespace SDF::UILayer::Gui::Qt::View {
  DockablesFactory::DockablesFactory() {}

  IGuiElement *
  DockablesFactory::create(IGuiElement *parent, std::string elementType) {
    if(elementType == "Toolchest") {
      return new Toolbox(dynamic_cast<QWidget *>(parent));
    } else {
      // TBA
    }
  }
}

namespace SDF::UILayer::Gui::Qt::View {
  DocumentViewFactory::DocumentViewFactory(AbstractModel::IDocumentAccessService *documentAccessService,
                                           AbstractModel::IDocumentRenderService *documentRenderService
                                          )
    : m_documentAccessService(documentAccessService),
      m_documentRenderService(documentRenderService)
  {
  }

  IGuiElement *
  DocumentViewFactory::create(IGuiElement *parent,
                              AbstractModel::Handle documentHandle
                             )
  {
    return new DocumentView(m_documentAccessService,
                            m_documentRenderService,
                            documentHandle,
                            dynamic_cast<QWidget *>(parent)
                           );
  }
}
