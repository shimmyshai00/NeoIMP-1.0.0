/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FileDialogProducer.cpp
 * PURPOSE: Implements the FileDialogProducer class.
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

#include "FileDialogProducer.hpp"

#include "../../../Controller/FileChooserDialog/OnAccept_Open.hpp"
#include "../../../Controller/FileChooserDialog/OnAccept_Save.hpp"

#include "../Views/FileChooserDialog.hpp"

#include "makeFileFilterList.hpp"
#include "file_format_names.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt::ViewProducers {
  FileDialogProducer::FileDialogProducer(
    deps_t a_deps,
    Common::Handle a_id,
    AProducerNode *a_parent,
    FileMode a_mode
  )
    : AProducerNode(a_id, a_parent),
      m_services(a_deps),
      m_mode(a_mode)
  {
  }

  QWidget *
  FileDialogProducer::getViewWidget() {
    return m_fileChooserDialog;
  }

  void
  FileDialogProducer::produceView() {
    using namespace AbstractModel::Defs;
    using namespace Controller::FileChooserDialog;
    using namespace Views;

    if(!m_fileChooserDialog) {
      m_fileChooserDialog = new FileChooserDialog(getParent()->getViewWidget());
      m_fileChooserDialog->setAttribute(::Qt::WA_DeleteOnClose);
      if(m_mode == MODE_OPEN) {
        m_fileChooserDialog->setAcceptMode(QFileDialog::AcceptOpen);
      } else {
        m_fileChooserDialog->setAcceptMode(QFileDialog::AcceptSave);
      }
      m_fileChooserDialog->setNameFilters(makeFileFilterList(g_fileFormatNames,
        g_fileExtensionFilters, FILE_FORMAT_MAX));

      auto onAcceptOpenController = std::make_unique<OnAccept_Open>(m_services);
      auto onAcceptSaveController = std::make_unique<OnAccept_Save>(m_services);

      if(m_mode == MODE_OPEN) {
        m_fileChooserDialog->hookOnAccept(std::move(onAcceptOpenController))->connect();
      } else {
        m_fileChooserDialog->hookOnAccept(std::move(onAcceptSaveController))->connect();
      }

      m_fileChooserDialog->exec();
    }
  }
}
