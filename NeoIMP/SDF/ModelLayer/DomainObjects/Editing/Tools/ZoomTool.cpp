/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ZoomTool.cpp
 * PURPOSE: Defines the ZoomTool class.
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

#include <SDF/ModelLayer/DomainObjects/Editing/Tools/ZoomTool.hpp>

#include <Services/AbstractDomain/IImageDelta.hpp>
#include <Services/AbstractDomain/Defs/ImageChanges.hpp>

#include <algorithm>

namespace SDF::ModelLayer::DomainObjects::Editing::Tools {
  // The delta class for the changes made by the zoom tool.
  class ZoomDelta : public Services::AbstractDomain::IImageDelta {
  public:
    ZoomDelta(Math::Coord<float> newCenter,
              float newMagnification
             )
      : m_newCenter(newCenter),
        m_newMagnification(newMagnification)
    {
    }

    void
    applyDelta(Services::AbstractDomain::IImage *image,
               Interfaces::IMessageReceiver<Services::AbstractDomain::Defs::ImageChange> *messageReceiver
              )
    {
      image->setViewCenter(m_newCenter);
      image->setViewMagnification(m_newMagnification);

      if(messageReceiver != nullptr) {
        std::shared_ptr<Services::AbstractDomain::Defs::ImageViewportCenterChanged>
          centerChanged(new Services::AbstractDomain::Defs::ImageViewportCenterChanged);
        centerChanged->imageId = image->getId();
        centerChanged->newCenter = m_newCenter;

        std::shared_ptr<Services::AbstractDomain::Defs::ImageViewportMagnificationChanged>
          magnifChanged(new Services::AbstractDomain::Defs::ImageViewportMagnificationChanged);
        magnifChanged->imageId = image->getId();
        magnifChanged->newMagnif = m_newMagnification;

        messageReceiver->receiveMessage(centerChanged);
        messageReceiver->receiveMessage(magnifChanged);
      }
    }
  private:
    Math::Coord<float> m_newCenter;
    float m_newMagnification;
  };
}

namespace SDF::ModelLayer::DomainObjects::Editing::Tools {
  ZoomTool::ZoomTool(int id)
    : m_id(id),
      m_zoomMode(UILayer::AbstractModel::ToolConfig::Properties::ZOOM_IN),
      m_zoomFactor(2.0f),
      m_image(nullptr),
      m_applicationPoint(0.0f, 0.0f)
  {
  }

  int
  ZoomTool::getId() const {
    return m_id;
  }

  UILayer::AbstractModel::ToolConfig::Properties::ZoomMode
  ZoomTool::getMode() const {
    return m_zoomMode;
  }

  float
  ZoomTool::getStep() const {
    return m_zoomFactor;
  }

  void
  ZoomTool::setMode(UILayer::AbstractModel::ToolConfig::Properties::ZoomMode mode) {
    m_zoomMode = mode;
  }

  void
  ZoomTool::setStep(float step) {
    m_zoomFactor = step;
  }

  void
  ZoomTool::beginApplication(Services::AbstractDomain::IImage *image) {
    m_image = image;
  }

  void
  ZoomTool::applyAt(float x, float y) {
    m_applicationPoint = Math::Coord<float>(x, y);
  }

  std::pair<Services::AbstractDomain::IImage *, std::unique_ptr<Services::AbstractDomain::IImageDelta>>
  ZoomTool::commit() {
    using namespace UILayer::AbstractModel::ToolConfig::Properties;

    // Zoom into the given application point.
    float curMagnif(m_image->getViewMagnification());
    float newMagnif;
    switch(m_zoomMode) {
      case ZOOM_IN: newMagnif = std::clamp(curMagnif * m_zoomFactor, 0.25f, 128.0f); break;
      case ZOOM_OUT: newMagnif = std::clamp(curMagnif / m_zoomFactor, 0.25f, 128.0f); break;
      case ZOOM_EQUAL: newMagnif = 1.0f; break;
      default: break;
    }

    return std::make_pair(m_image, std::make_unique<ZoomDelta>(m_applicationPoint, newMagnif));
  }
}
