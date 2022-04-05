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

#include "../../../../../../Common/Model/ServicePack.hpp"
#include "../../../../../../Common/IConnection.hpp"
#include "../../IController.hpp"

#include "../../../../AbstractModel/Defs/Color/ColorFormat.hpp"
#include "../../../../AbstractModel/Defs/ImageSpec.hpp"
#include "../../../../AbstractModel/Metrics/IConvertLengthService.hpp"
#include "../../../../AbstractModel/Metrics/IConvertResolutionService.hpp"
#include "../../../../AbstractModel/Create/IGetDocumentPrefabService.hpp"
#include "../../../../AbstractModel/Create/IGetMemoryRequirementsService.hpp"
#include "../../../../AbstractModel/Color/IUiColorConversionService.hpp"
//#include "../../Controller/NewDocumentDialog/Accept.hpp"
#include "../QtEvent.hpp"

#include "../CustomWidgets/Color/ColorSwatch.hpp"

#include <QDialog>
#include <QLabel>

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
    typedef Common::Model::ServicePack<
      AbstractModel::Metrics::IConvertLengthService,
      AbstractModel::Metrics::IConvertResolutionService,
      AbstractModel::Create::IGetDocumentPrefabService,
      AbstractModel::Create::IGetMemoryRequirementsService,
      AbstractModel::Color::IUiColorConversionService
    > deps_t;
  public:
    NewDocumentDialog(deps_t deps, QWidget *parent = nullptr);
    ~NewDocumentDialog();

    Common::PIConnection
    hookOnAccept(std::unique_ptr<IController<AbstractModel::Defs::ImageSpec>> controller);

    Common::PIConnection
    hookOnReject(std::unique_ptr<IController<>> controller);

    Common::PIConnection
    hookOnColorRequest(std::unique_ptr<IController<>> controller);
  private:
    Ui::NewDocumentDialog *m_ui;

    QLabel *m_colorPickerLabel;
    CustomWidgets::Color::ColorSwatch *m_backgroundSwatch;

    QtEvent<AbstractModel::Defs::ImageSpec> m_onAcceptEvent;
    QtEvent<> m_onRejectEvent;
    QtEvent<> m_onColorRequestEvent;

    deps_t m_services;
    AbstractModel::Defs::ImageSpec m_protoSpec;

  private:
    int
    colorIndexIn(
      const AbstractModel::Defs::Color::ColorFormat *a_formats,
      int a_numFormats,
      AbstractModel::Defs::Color::ColorFormat a_format
    );

    void
    setBoxesFromColorFormat(AbstractModel::Defs::Color::ColorFormat colorFormat);
  private slots:
    void
    setColorSubFormatsShown(int familyIndex);

    void
    getColorFormatFromBoxes();

    void
    calculateSizeRequired();

    void
    showColorSelector();

    void
    hideColorSelector();

    void
    onDeviatedFromPreset();

    void
    adjustSettingsToPreset(int which);
  };
}

#endif
