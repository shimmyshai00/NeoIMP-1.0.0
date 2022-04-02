#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWS_NEWDOCUMENTDIALOG_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWS_NEWDOCUMENTDIALOG_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentDialog.hpp
 * PURPOSE: Defines the NewDocumentDialog class.
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

#include "../../../../../../Common/IConnection.hpp"
#include "../../IController.hpp"

#include "../../../../AbstractModel/Defs/ImageSpec.hpp"
#include "../../../../AbstractModel/Metrics/IConvertLengthService.hpp"
#include "../../../../AbstractModel/Metrics/IConvertResolutionService.hpp"
#include "../../../../AbstractModel/Create/IGetDocumentPrefabService.hpp"
#include "../../../../AbstractModel/Create/IGetMemoryRequirementsService.hpp"
//#include "../../Controller/NewDocumentDialog/Accept.hpp"
#include "../QtEvent.hpp"

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class NewDocumentDialog; }
QT_END_NAMESPACE

namespace SDF::Editor::UILayer::Gui::View::Qt::Views {
  // Class:      NewDocumentDialog
  // Purpose:    Implements the new-document dialog using Qt.
  // Parameters: None.
  class NewDocumentDialog : public QDialog {
    Q_OBJECT
  public:
    NewDocumentDialog(
      AbstractModel::Metrics::IConvertLengthService *convertLengthService,
      AbstractModel::Metrics::IConvertResolutionService *convertResolutionService,
      AbstractModel::Create::IGetDocumentPrefabService *getDocumentPrefabService,
      AbstractModel::Create::IGetMemoryRequirementsService *getMemoryRequirementsService,
      QWidget *parent = nullptr
    );
    ~NewDocumentDialog();

    Common::PIConnection
    hookOnAccept(std::unique_ptr<IController<AbstractModel::Defs::ImageSpec>> controller);

    Common::PIConnection
    hookOnReject(std::unique_ptr<IController<>> controller);
  private:
    Ui::NewDocumentDialog *m_ui;

    QtEvent<AbstractModel::Defs::ImageSpec> m_onAcceptEvent;
    QtEvent<> m_onRejectEvent;

    AbstractModel::Metrics::IConvertLengthService *m_convertLengthService;
    AbstractModel::Metrics::IConvertResolutionService *m_convertResolutionService;
    AbstractModel::Create::IGetDocumentPrefabService *m_getDocumentPrefabService;
    AbstractModel::Create::IGetMemoryRequirementsService *m_getMemoryRequirementsService;
  };
}

#endif
