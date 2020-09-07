/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CImageEditor.cpp
 * PURPOSE: Implementation of the Qt-based image editor widget.
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

#include <Impl/Qt/CustomWidgets/CImageEditor.hpp>

#include <Impl/Qt/CustomWidgets/CRuler.hpp>
#include <Impl/Qt/CustomWidgets/CImageDisplay.hpp>

#include <QListView>
#include <iostream>

namespace SDF {
  namespace UILayer {
    namespace Impl::Qt::CustomWidgets {
      CImageEditor::CImageEditor(QWidget *parent, int initialImgWidthPx, int initialImgHeightPx)
      : QWidget(parent),
        m_topRuler(nullptr),
        m_leftRuler(nullptr),
        m_imageWidthPx(initialImgWidthPx),
        m_imageHeightPx(initialImgHeightPx),
        m_viewCenterX(m_imageWidthPx / 2),
        m_viewCenterY(m_imageHeightPx / 2)
      {
        m_gridLayout = new QGridLayout(this);

        m_topRuler = new CRuler(this, CRuler::HorizontalOrientation, 20);
        m_leftRuler = new CRuler(this, CRuler::VerticalOrientation, 20);
        m_imageDisplay = new CImageDisplay(this);

        m_gridLayout->addWidget(m_topRuler, 0, 1);
        m_gridLayout->addWidget(m_leftRuler, 1, 0);
        m_gridLayout->addWidget(m_imageDisplay, 1, 1);
      }

      void CImageEditor::paintEvent(QPaintEvent *event) {
        //std::cout << "Painting" << std::endl;
      }
    }
  }
}
