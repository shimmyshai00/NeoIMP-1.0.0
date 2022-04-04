#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWPRODUCERS_FILEDIALOGPRODUCER_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWPRODUCERS_FILEDIALOGPRODUCER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FileDialogProducer.hpp
 * PURPOSE: Defines the FileDialogProducer class.
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

#include "../../../../../../Common/Model/ServicePack.hpp"

#include "../../../../../../Common/Handle.hpp"

#include "../../../../AbstractModel/Editing/IGetActiveDocumentService.hpp"
#include "../../../../AbstractModel/Storage/ILoadDocumentService.hpp"
#include "../../../../AbstractModel/Storage/ISaveDocumentService.hpp"

#include "../../../Controller/IViewProducer.hpp"
#include "../Views/FileChooserDialog.hpp"

#include "AProducerNode.hpp"

#include <QPointer>
#include <QWidget>

#include <memory>

namespace SDF::Editor::UILayer::Gui::View::Qt::ViewProducers {
  // Class:      FileDialogProducer
  // Purpose:    Produces a file dialog.
  // Parameters: None.
  class FileDialogProducer : public AProducerNode,
                             public Controller::IViewProducer<>
  {
  public:
    typedef Common::Model::ServicePack<
      AbstractModel::Editing::IGetActiveDocumentService,
      AbstractModel::Storage::ILoadDocumentService,
      AbstractModel::Storage::ISaveDocumentService
    > deps_t;
  public:
    enum FileMode {
      MODE_OPEN,
      MODE_SAVE
    };

    FileDialogProducer(
      deps_t a_deps,
      Common::Handle a_id,
      AProducerNode *a_parent,
      FileMode a_mode
    );

    QWidget *
    getViewWidget();

    void
    produceView();
  private:
    deps_t m_services;

    FileMode m_mode;
    QPointer<Views::FileChooserDialog> m_fileChooserDialog;
  };
}

#endif
