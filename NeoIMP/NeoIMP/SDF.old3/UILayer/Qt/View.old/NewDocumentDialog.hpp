#ifndef SDF_UILAYER_QT_VIEW_NEWDOCUMENTDIALOG_HPP
#define SDF_UILAYER_QT_VIEW_NEWDOCUMENTDIALOG_HPP

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

#include "../../AbstractModel/IMetricsService.hpp"
#include "IController.hpp"
#include "Hook.hpp"

#include <QDialog>
#include <QAction>

#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class NewDocumentDialog; }
QT_END_NAMESPACE

namespace SDF::UILayer::Qt::View {
  // Class:      NewDocumentDialog
  // Purpose:    Defines the new-document dialog.
  // Parameters: None.
  class NewDocumentDialog : public QDialog {
    Q_OBJECT
  public:
    NewDocumentDialog(AbstractModel::IMetricsService *metricsService,
                      QObject *parent = nullptr
                     );

    // Controller hooks.
  private:
    Ui::NewDocumentDialog *m_ui;
  };
}

#endif
