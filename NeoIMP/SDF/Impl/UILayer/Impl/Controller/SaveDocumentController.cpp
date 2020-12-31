/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SaveDocumentController.cpp
 * PURPOSE: The MVC controller for the save-document view.
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

 #include <SaveDocumentController.hpp>

 #include <AbstractModel/Services/IDocumentStorageService.hpp>
 #include <AbstractModel/Handle.hpp>
 #include <AbstractModel/Properties/FileFormat.hpp>

 #include <IUIDetail.hpp>
 #include <View/IViewGenerator.hpp>
 #include <View/ISaveDocumentView.hpp>

 #include <iostream>

 namespace SDF::Impl::UILayer::Impl::Controller {
   SaveDocumentController::SaveDocumentController(
     AbstractModel::Services::IDocumentStorageService *documentStorageService,
     View::ISaveDocumentView *saveDocumentView
   )
    : m_documentStorageService(documentStorageService),
      m_saveDocumentView(saveDocumentView)
   {
     m_saveDocumentView->addGotParamsObserver([=](
       std::string fileSpec, AbstractModel::Properties::FileFormat fileFormat
     ) {
       onAcceptCommand(fileSpec, fileFormat);
     });
   }

   // Private members.
   void SaveDocumentController::onAcceptCommand(
     std::string fileSpec, AbstractModel::Properties::FileFormat fileFormat
   ) {
     // TBA
   }
 }
