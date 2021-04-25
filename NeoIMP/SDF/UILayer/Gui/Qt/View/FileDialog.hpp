#ifndef SDF_UILAYER_GUI_QT_VIEW_FILEDIALOG_HPP
#define SDF_UILAYER_GUI_QT_VIEW_FILEDIALOG_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FileDialog.hpp
 * PURPOSE: Defines the FileDialog class.
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
#include <SDF/UILayer/Gui/IGuiElement.hpp>

#include <SDF/UILayer/Gui/Qt/Events/GuiEvent.hpp>

#include <QWidget>
#include <QFileDialog>
#include <QString>

namespace SDF::UILayer::Gui::Qt::View {
  // Class:      FileDialog
  // Purpose:    Provides the file open/save dialog window.
  // Parameters: None.
  class FileDialog : public QFileDialog,
                     public IGuiElement
  {
  public:
    FileDialog(std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> controller,
               const QString &caption = QString(),
               QFileDialog::AcceptMode acceptMode = QFileDialog::AcceptSave,
               QWidget *parent = nullptr
              );
    ~FileDialog();

    IGuiElement *
    getParent();

    void
    show();

    void
    close();
  private:
    std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> m_controller;
  };
}

#endif
