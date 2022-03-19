#ifndef SDF_UILAYER_QTAPPLICATION_VIEW_NEWDOCUMENTDIALOG_HPP
#define SDF_UILAYER_QTAPPLICATION_VIEW_NEWDOCUMENTDIALOG_HPP

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

#include "../Controller/IController.hpp"
#include "Events/DialogEvent.hpp"
#include "IView.hpp"

#include <QDialog>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class NewDocumentDialog; }
QT_END_NAMESPACE

namespace SDF::UILayer::QtApplication::View {
  // Class:      NewDocumentDialog
  // Purpose:    Provides the new-document dialog.
  // Parameters: None.
  class NewDocumentDialog : public QDialog,
                            public IView<QDialog>
  {
    Q_OBJECT
  public:
    NewDocumentDialog(std::unique_ptr<Controller::IController<QDialog, Events::DialogEvent>> controller,
                      QWidget *parent = nullptr
                     );

    QDialog *
    getQWidget();
  private:
    Ui::NewDocumentDialog *m_ui;

    std::unique_ptr<Controller::IController<QDialog, Events::DialogEvent>> m_controller;
  };
}


#endif
