#ifndef SDF_UILAYER_GUI_VIEW_QT_NEWDOCUMENTDIALOG_HPP
#define SDF_UILAYER_GUI_VIEW_QT_NEWDOCUMENTDIALOG_HPP

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

#include "../../../../Patterns/IConnection.hpp"
#include "../../Controller/IGuiController.hpp"
#include "../IDialog.hpp"
#include "IQtView.hpp"

#include "../../../AbstractModel/Defs/ImageSpec.hpp"
#include "../../../AbstractModel/IMetricsService.hpp"
//#include "../../Controller/NewDocumentDialog/Accept.hpp"
#include "QtView.hpp"
#include "QtEvent.hpp"

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class NewDocumentDialog; }
QT_END_NAMESPACE

namespace SDF::UILayer::Gui::View::Qt {
  // Class:      NewDocumentDialog
  // Purpose:    Implements the new-document dialog using Qt.
  // Parameters: None.
  class NewDocumentDialog : public QtView<QDialog>,
                            public IDialog<AbstractModel::Defs::ImageSpec>
  {
    Q_OBJECT
  public:
    NewDocumentDialog(AbstractModel::IMetricsService *metricsService,
                      IQtView *parent = nullptr
                     );
    ~NewDocumentDialog();

    std::string
    getViewId() const { return "NewDocumentDialog"; }

    Patterns::PIConnection
    hookOnAccept(std::unique_ptr<Mvc::IController<AbstractModel::Defs::ImageSpec>> controller);

    Patterns::PIConnection
    hookOnReject(std::unique_ptr<Mvc::IController<>> controller);
  private:
    Ui::NewDocumentDialog *m_ui;

    QtEvent<AbstractModel::Defs::ImageSpec> m_onAcceptEvent;
    QtEvent<> m_onRejectEvent;
  };
}

#endif
