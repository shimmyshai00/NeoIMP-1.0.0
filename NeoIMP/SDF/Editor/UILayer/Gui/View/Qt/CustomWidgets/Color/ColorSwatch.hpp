#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_COLOR_COLORSWATCH_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_CUSTOMWIDGETS_COLOR_COLORSWATCH_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorSwatch.hpp
 * PURPOSE: Defines the ColorSwatch class.
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

#include "../../../../../AbstractModel/Defs/Color/IColor.hpp"
#include "../../../../../AbstractModel/Defs/Color/ColorFormat.hpp"
#include "../../../../../AbstractModel/Color/IUiColorConversionService.hpp"

#include <QWidget>
#include <QSize>

#include <memory>

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets::Color {
  // Class:      ColorSwatch
  // Purpose:    Defines a custom widget that displays a single color chosen from a document's color
  //             scheme.
  // Parameters: None.
  class ColorSwatch : public QWidget {
    Q_OBJECT
  public:
    ColorSwatch(
      AbstractModel::Color::IUiColorConversionService *a_uiColorConversionService,
      QWidget *a_parent = nullptr
    );

    QSize
    sizeHint() const;

    // Function:   hasBorder
    // Purpose:    Returns if the color has a border.
    // Parameters: None.
    // Returns:    Whether the button has a border.
    bool
    hasBorder() const;

    // Function:   setHasBorder
    // Purpose:    Sets whether the color has a border.
    // Parameters: has - Wheter it should have a border.
    // Returns:    None.
    void
    setHasBorder(bool a_hasBorder);

    // Function:   color
    // Purpose:    Gets the color that is being displayed. This color is specified in document
    //             space.
    // Parameters: None.
    // Returns:    The color.
    std::shared_ptr<AbstractModel::Defs::Color::IColor<AbstractModel::Defs::Color::ColorFormat>>
    color() const;

    // Function:   setColor
    // Purpose:    Sets the displayed color.
    // Parameters: color - The color value to set.
    // Returns:    None.
    void
    setColor(
      std::shared_ptr<AbstractModel::Defs::Color::IColor<AbstractModel::Defs::Color::ColorFormat>>
        a_color
    );
  signals:
    void
    clicked();
  protected:
    void
    paintEvent(QPaintEvent *a_event) override;

    void
    mouseReleaseEvent(QMouseEvent *a_event) override;
  private:
    AbstractModel::Color::IUiColorConversionService *m_uiColorConversionService;

    bool m_hasBorder;
    std::shared_ptr<AbstractModel::Defs::Color::IColor<AbstractModel::Defs::Color::ColorFormat>>
      m_color;
  };
}

#endif
