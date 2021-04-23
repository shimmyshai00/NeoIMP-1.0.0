#ifndef SDF_UILAYER_GUI_QT_VIEW_NEWDOCUMENTDIALOG_HPP
#define SDF_UILAYER_GUI_QT_VIEW_NEWDOCUMENTDIALOG_HPP

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

#include <SDF/Interfaces/IEventHandler.hpp>
#include <SDF/UILayer/Gui/IGuiElement.hpp>

#include <SDF/UILayer/Gui/Qt/Events/GuiEvent.hpp>

#include <SDF/UILayer/Gui/Qt/View/LengthSelector.hpp>
#include <SDF/UILayer/Gui/Qt/View/ResolutionSelector.hpp>

#include <SDF/UILayer/AbstractModel/Properties/ColorModel.hpp>
#include <SDF/UILayer/AbstractModel/Properties/BitDepth.hpp>

#include <QWidget>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class NewDocumentDialog; }
QT_END_NAMESPACE

namespace SDF::UILayer::Gui {
  class IGuiController;

  namespace Qt::View {
    // Class:      NewDocumentDialog
    // Purpose:    Provides the main application window.
    // Parameters: None.
    class NewDocumentDialog : public QDialog,
                              public IGuiElement
    {
    public:
      NewDocumentDialog(std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> controller,
                        QWidget *parent = nullptr
                       );
      ~NewDocumentDialog();

      IGuiElement *
      getParent();

      void
      show();

      void
      close();
    private:
      Ui::NewDocumentDialog *m_ui;

      std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> m_controller;

      LengthSelector m_documentWidthSelector;
      LengthSelector m_documentHeightSelector;
      ResolutionSelector m_documentResolutionSelector;

      AbstractModel::Properties::ColorModel m_colorModel;
      AbstractModel::Properties::BitDepth m_bitDepth;
    };
  }
}

#endif
