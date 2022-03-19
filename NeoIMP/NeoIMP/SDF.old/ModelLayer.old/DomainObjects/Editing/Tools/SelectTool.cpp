/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SelectTool.cpp
 * PURPOSE: Implements the SelectTool class.
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

#include <SelectTool.hpp>

#include <Services/AbstractDomain/IImageDelta.hpp>
#include <Services/AbstractDomain/Defs/ImageChanges.hpp>

#include <Decals/RectangularMarquee.hpp>

namespace SDF::ModelLayer::DomainObjects::Editing::Tools {
  // The delta class for changes made by the selection tool.
  class AddSelectionDelta : public Services::AbstractDomain::IImageDelta {
  public:
    AddSelectionDelta(UILayer::AbstractModel::ToolConfig::Properties::SelectMode marqueeType,
                      Math::Coord<float> upperLeft,
                      Math::Coord<float> lowerRight
                     )
      : m_marqueeType(marqueeType),
        m_upperLeft(upperLeft),
        m_lowerRight(lowerRight)
    {
    }

    void
    applyDelta(Services::AbstractDomain::IImage *image,
               Interfaces::IMessageReceiver<Services::AbstractDomain::Defs::ImageChange> *messageReceiver
              )
    {
      std::unique_ptr<Services::AbstractDomain::IDecal> decal;
      decal = std::make_unique<Decals::RectangularMarquee>(Math::Rect<std::size_t>(m_upperLeft, m_lowerRight));
      Services::AbstractDomain::IDecal *decalPtr(decal.get());

      image->addDecal(std::move(decal));

      if(messageReceiver != nullptr) {
        std::shared_ptr<Services::AbstractDomain::Defs::ImageDecalAdded>
          decalAdded(new Services::AbstractDomain::Defs::ImageDecalAdded);
        decalAdded->decal = decalPtr;

        messageReceiver->receiveMessage(decalAdded);
      }
    }
  private:
    UILayer::AbstractModel::ToolConfig::Properties::SelectMode m_marqueeType;
    Math::Coord<float> m_upperLeft;
    Math::Coord<float> m_lowerRight;
  };

  // If the user just clicks the tool without dragging a box, it is supposed to remove the active selection.
  class RemoveSelectionDelta : public Services::AbstractDomain::IImageDelta {
  public:
    void
    applyDelta(Services::AbstractDomain::IImage *image,
               Interfaces::IMessageReceiver<Services::AbstractDomain::Defs::ImageChange> *messageReceiver
              )
    {
      image->removeDecal(Services::AbstractDomain::Defs::DECAL_SELECTION);

      if(messageReceiver != nullptr) {
        std::shared_ptr<Services::AbstractDomain::Defs::ImageDecalRemoved>
          decalRemoved(new Services::AbstractDomain::Defs::ImageDecalRemoved);
        decalRemoved->decalType = Services::AbstractDomain::Defs::DECAL_SELECTION;

        messageReceiver->receiveMessage(decalRemoved);
      }
    }
  };
}

namespace SDF::ModelLayer::DomainObjects::Editing::Tools {
  SelectTool::SelectTool(int id)
    : m_id(id),
      m_selectMode(UILayer::AbstractModel::ToolConfig::Properties::SELECT_RECTANGULAR_MARQUEE),
      m_image(nullptr),
      m_isUpperLeftSelected(false),
      m_isLowerRightSelected(false),
      m_selectUpperLeft(0.0f, 0.0f),
      m_selectLowerRight(0.0f, 0.0f)
  {
  }

  int
  SelectTool::getId() const {
    return m_id;
  }

  UILayer::AbstractModel::Properties::Tool
  SelectTool::getToolType() const {
    return UILayer::AbstractModel::Properties::TOOL_SELECT;
  }

  UILayer::AbstractModel::ToolConfig::Properties::SelectMode
  SelectTool::getMode() const {
    return m_selectMode;
  }

  void
  SelectTool::setMode(UILayer::AbstractModel::ToolConfig::Properties::SelectMode mode) {
    m_selectMode = mode;
  }

  void
  SelectTool::beginApplication(Services::AbstractDomain::IImage *image) {
    m_isUpperLeftSelected = false;
  }

  void
  SelectTool::applyAt(float x, float y) {
    if(!m_isUpperLeftSelected) {
      m_selectUpperLeft = Math::Coord<float>(x, y);
      m_isUpperLeftSelected = true;
    } else {
      m_selectLowerRight = Math::Coord<float>(x, y);

      // make sure at least one pixel big
      if(Math::Coord<std::size_t>(m_selectUpperLeft) != Math::Coord<std::size_t>(m_selectLowerRight)) {
        m_isLowerRightSelected = true;
      }
    }
  }

  std::pair<Services::AbstractDomain::IImage *, std::unique_ptr<Services::AbstractDomain::IImageDelta>>
  SelectTool::commit() {
    if(m_isUpperLeftSelected && m_isLowerRightSelected) {
      return std::make_pair(m_image, std::make_unique<AddSelectionDelta>(m_selectMode,
                                                                         m_selectUpperLeft,
                                                                         m_selectLowerRight
                                                                        ));
    } else {
      return std::make_pair(m_image, std::make_unique<RemoveSelectionDelta>());
    }
  }
}
