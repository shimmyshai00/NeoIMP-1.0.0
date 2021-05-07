#ifndef SDF_MODELLAYER_SERVICES_ZOOMTOOLCFGSERVICE_HPP
#define SDF_MODELLAYER_SERVICES_ZOOMTOOLCFGSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ZoomToolCfgService.hpp
 * PURPOSE: Defines the ZoomToolCfgService class.
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

#include <SDF/UILayer/AbstractModel/ToolConfig/IZoomToolCfgService.hpp>
#include <SDF/UILayer/AbstractModel/ToolConfig/Properties/ZoomMode.hpp>

#include <fruit/fruit.h>

namespace SDF::ModelLayer {
  namespace AbstractData {
    template<class T>
    class IRepository;
  }

  namespace Services {
    namespace AbstractDomain {
      class ITool;
    }

    class ZoomToolCfgService : public UILayer::AbstractModel::ToolConfig::IZoomToolCfgService {
    public:
      INJECT(ZoomToolCfgService(AbstractData::IRepository<AbstractDomain::ITool> *toolRepository));

      void
      setMode(UILayer::AbstractModel::ToolConfig::Properties::ZoomMode mode);

      void
      setZoomStep(float step);

      UILayer::AbstractModel::ToolConfig::Properties::ZoomMode
      getMode() const;

      float
      getZoomStep() const;
    private:
      AbstractData::IRepository<AbstractDomain::ITool> *m_toolRepository;
    };
  }
}

#endif
