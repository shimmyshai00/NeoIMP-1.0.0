#ifndef SDF_UILAYER_GUI_QT_CONTROLLER_OPENDIALOGCONTROLLER_HPP
#define SDF_UILAYER_GUI_QT_CONTROLLER_OPENDIALOGCONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OpenDialogController.hpp
 * PURPOSE: Defines the OpenDialogController class.
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

#include <SDF/UILayer/Gui/Qt/Events/GuiEvent.hpp>
#include <SDF/UILayer/Gui/Qt/Events/DialogEvent.hpp>

#include <SDF/UILayer/Gui/Qt/View/FileIndicator.hpp>

#include <SDF/UILayer/AbstractModel/Handle.hpp>

#include <fruit/fruit.h>
#include <memory>

namespace SDF::UILayer {
  namespace AbstractModel {
    class IDocumentStorageService;

    template<class T>
    class IUiStateModelService;
  }

  namespace Gui::Qt::Controller {
    // Class:      OpenDialogController
    // Purpose:    Handles events from the open-document dialog.
    // Parameters: None.
    class OpenDialogController : public Interfaces::IEventHandler<Events::GuiEvent> {
    public:
      OpenDialogController(AbstractModel::IDocumentStorageService *documentStorageService,
                           AbstractModel::IUiStateModelService<AbstractModel::Handle> *uiStateModelService
                          );

      void
      handleEvent(std::shared_ptr<Events::GuiEvent> event);
    private:
      AbstractModel::IDocumentStorageService *m_documentStorageService;
      AbstractModel::IUiStateModelService<AbstractModel::Handle> *m_uiStateModelService;

      void
      handleAcceptEvent(Events::AcceptEvent<View::FileIndicator> *event);

      void
      handleRejectEvent(Events::RejectEvent<View::FileIndicator> *event);
    };
  }
}

#endif
