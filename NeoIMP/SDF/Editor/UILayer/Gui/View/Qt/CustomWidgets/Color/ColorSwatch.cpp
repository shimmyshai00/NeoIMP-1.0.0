/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorSwatch.cpp
 * PURPOSE: Implements the ColorSwatch class.
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

#include "ColorSwatch.hpp"

#include "../../../../../AbstractModel/Defs/Color/types.hpp"

#include "AdaptedQColor.hpp"

#include <QFont>
#include <QFontMetrics>
#include <QRect>
#include <QPaintEvent>
#include <QPainter>
#include <QBrush>

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets::Color {
  ColorSwatch::ColorSwatch(
    AbstractModel::Color::IUiColorConversionService *a_uiColorConversionService,
    QWidget *a_parent
  )
    : QWidget(a_parent),
      m_uiColorConversionService(a_uiColorConversionService),
      m_hasBorder(true),
      m_color(std::make_shared<AbstractModel::Defs::Color::RGB24_888>(255, 255, 255))
  {
  }

  QSize
  ColorSwatch::sizeHint() const {
    // The default size is meant to mimick the height of a text field, so it can be neatly placed
    // next to one. Actually, we are mimicking the default size of a QPushButton which, in turn,
    // provides a presumably "standardized" mimicking height. This algo is adopted from the
    // implementation of QPushButton.
    QFont font;
    QFontMetrics fontMetrics(font);
    QRect widgetRect = fontMetrics.boundingRect(QString::fromLatin1("XXXX"));
    return widgetRect.size();
  }

  bool
  ColorSwatch::hasBorder() const {
    return m_hasBorder;
  }

  void
  ColorSwatch::setHasBorder(bool a_hasBorder) {
    m_hasBorder = a_hasBorder;
  }

  std::shared_ptr<AbstractModel::Defs::Color::IColor<AbstractModel::Defs::Color::ColorFormat>>
  ColorSwatch::color() const {
    return m_color;
  }

  void
  ColorSwatch::setColor(
    std::shared_ptr<AbstractModel::Defs::Color::IColor<AbstractModel::Defs::Color::ColorFormat>>
      a_color
  ) {
    m_color = a_color;
  }
}

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets::Color {
  void
  ColorSwatch::paintEvent(QPaintEvent *a_event) {
    QPainter painter(this);

    // Pass the stored color through the model layer to get it in UI space.
    AdaptedQColor qRecvColor(::Qt::gray);
    if(m_uiColorConversionService != nullptr) {
      m_uiColorConversionService->convertColor(*m_color, qRecvColor);
    }

    // Set up the drawing.
    QPen markingsPen(QColor(0, 0, 0));
    QBrush fillBrush(qRecvColor);
    painter.setPen(markingsPen);
    painter.setBrush(fillBrush);

    // This part ripped from the ruler, since the ruler also has borders.
    // Draw the fill color.
    QRect totalRect = rect();
    QRect updateRect = a_event->rect();

    painter.setPen(::Qt::NoPen);
    painter.drawRect(updateRect);
    painter.setPen(markingsPen);

    // Check if the requested rectangle contains borders, if they are desired.
    if(m_hasBorder) {
      if(updateRect.top() == totalRect.top()) {
        // Has upper border.
        painter.drawLine(updateRect.left(), updateRect.top(), updateRect.right(),
          updateRect.top());
      }

      if(updateRect.bottom() == totalRect.bottom()) {
        // Has lower border.
        painter.drawLine(updateRect.left(), updateRect.bottom(),
          updateRect.right(), updateRect.bottom());
      }

      if(updateRect.left() == totalRect.left()) {
        // Has left-hand border.
        painter.drawLine(updateRect.left(), updateRect.top(), updateRect.left(),
          updateRect.bottom());
      }

      if(updateRect.right() == totalRect.right()) {
        // Has right-hand border.
        painter.drawLine(updateRect.right(), updateRect.top(),
          updateRect.right(), updateRect.bottom());
      }
    }
  }
}
