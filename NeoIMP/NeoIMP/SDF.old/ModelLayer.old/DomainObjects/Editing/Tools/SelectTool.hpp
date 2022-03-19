#ifndef SDF_MODELLAYER_DOMAINOBJECTS_EDITING_TOOLS_SELECTTOOL_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_EDITING_TOOLS_SELECTTOOL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SelectTool.hpp
 * PURPOSE: Defines the SelectTool class.
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

#include <SDF/ModelLayer/Services/AbstractDomain/Tools/ISelectTool.hpp>
#include <SDF/UILayer/AbstractModel/ToolConfig/Properties/SelectMode.hpp>
#include <SDF/UILayer/AbstractModel/Properties/Tool.hpp>

#include <SDF/ModelLayer/Math/Coord.hpp>

namespace SDF::ModelLayer {
  namespace Services::AbstractDomain {
    class IImage;
    class IImageDelta;

    class IDecal;
  }

  namespace DomainObjects::Editing::Tools {
    // Class:      SelectTool
    // Purpose:    Defines an editing tool that lets the user select a region of the image.
    // Parameters: None.
    class SelectTool : public Services::AbstractDomain::Tools::ISelectTool {
    public:
      SelectTool(int id);

      int
      getId() const;

      UILayer::AbstractModel::Properties::Tool
      getToolType() const;

      UILayer::AbstractModel::ToolConfig::Properties::SelectMode
      getMode() const;

      void
      setMode(UILayer::AbstractModel::ToolConfig::Properties::SelectMode mode);

      void
      beginApplication(Services::AbstractDomain::IImage *image);

      void
      applyAt(float x, float y);

      std::pair<Services::AbstractDomain::IImage *, std::unique_ptr<Services::AbstractDomain::IImageDelta>>
      commit();
    private:
      int m_id;

      UILayer::AbstractModel::ToolConfig::Properties::SelectMode m_selectMode;

      Services::AbstractDomain::IImage *m_image;

      bool m_isUpperLeftSelected;
      bool m_isLowerRightSelected;

      Math::Coord<float> m_selectUpperLeft;
      Math::Coord<float> m_selectLowerRight;
    };
  }
}

#endif
