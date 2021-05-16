/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ZoomToolConfigPane.cpp
 * PURPOSE: Implements the ZoomToolConfigPane class.
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

#include "ZoomToolConfigPane.hpp"

#include <AbstractModel/ToolConfig/IZoomToolCfgService.hpp>
#include <Events/ZoomToolConfigEvent.hpp>

#include "safeConnect.hpp"

namespace SDF::UILayer::Gui::Qt::View {
  ZoomToolConfigPane::ZoomToolConfigPane(AbstractModel::ToolConfig::IZoomToolCfgService *zoomToolCfgService,
                                         std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> controller,
                                         QWidget *parent
                                        )
    : QtGuiElement<QWidget>(parent),
      m_controller(std::move(controller)),
      m_zoomToolCfgService(zoomToolCfgService),
      m_gridLayout(nullptr),
      m_zoomPowerLabel(nullptr),
      m_zoomPowerSlider(nullptr)
  {
    // Create the widget layout.
    m_gridLayout = new QGridLayout(this);
    m_zoomDirectionLabel = new QLabel("Zoom Mode:", nullptr);
    m_zoomDirectionIndicatorLabel = new QLabel("IN");

    m_zoomPowerLabel = new QLabel("Zoom Power:", nullptr);
    m_zoomPowerSlider = new CustomWidgets::EditableSlider(10, 100, 1, ::Qt::Horizontal, nullptr);
    m_zoomPowerSlider->setDenom(10);

    m_spacer = new QLabel("", nullptr);

    m_gridLayout->addWidget(m_zoomDirectionLabel, 0, 0, ::Qt::AlignTop);
    m_gridLayout->addWidget(m_zoomDirectionIndicatorLabel, 0, 1, ::Qt::AlignTop);
    m_gridLayout->addWidget(m_zoomPowerLabel, 1, 0);
    m_gridLayout->addWidget(m_zoomPowerSlider, 1, 1);
    m_gridLayout->addWidget(m_spacer, 2, 0);

    // Set according to the model state.
    m_zoomPowerSlider->setValueF(zoomToolCfgService->getZoomStep());

    // Connect to controller.
    safeConnect(m_zoomPowerSlider, &CustomWidgets::EditableSlider::denomValueChanged, [=](float value) {
      std::shared_ptr<Events::ZoomStepChangedEvent> event(new Events::ZoomStepChangedEvent);
      event->newZoomStep = value;
      m_controller->handleEvent(event);
    });

    updateZoomMode();

    m_zoomToolCfgService->attachObserver(this);
  }

  ZoomToolConfigPane::~ZoomToolConfigPane() {
    m_zoomToolCfgService->removeObserver(this);
  }

  // Private members.
  void
  ZoomToolConfigPane::updateZoomMode() {
    using namespace AbstractModel::ToolConfig::Properties;

    switch(m_zoomToolCfgService->getMode()) {
      case ZOOM_IN: m_zoomDirectionIndicatorLabel->setText("IN"); break;
      case ZOOM_OUT: m_zoomDirectionIndicatorLabel->setText("OUT"); break;
      case ZOOM_EQUAL: m_zoomDirectionIndicatorLabel->setText("TO 100%"); break;
      default: m_zoomDirectionIndicatorLabel->setText("*** ERROR ***"); break;
    }

    if(m_zoomToolCfgService->getMode() == ZOOM_EQUAL) {
      // zoom power should not be enabled in equal mode
      m_zoomPowerSlider->setEnabled(false);
    } else {
      m_zoomPowerSlider->setEnabled(true);
    }
  }

  void
  ZoomToolConfigPane::handleEvent(std::shared_ptr<AbstractModel::Events::ZoomToolEvent> event) {
    if(auto p = dynamic_cast<AbstractModel::Events::ZoomToolModeChangedEvent *>(event.get())) {
      updateZoomMode();
    }
  }
}
