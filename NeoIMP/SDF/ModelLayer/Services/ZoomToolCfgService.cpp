/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ZoomToolCfgService.cpp
 * PURPOSE: Implements the ZoomToolCfgService class.
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

#include "ZoomToolCfgService.hpp"

#include <AbstractData/IRepository.hpp>
#include <AbstractDomain/Tools/IZoomTool.hpp>

namespace SDF::ModelLayer::Services {
  ZoomToolCfgService::ZoomToolCfgService(AbstractData::IRepository<AbstractDomain::Tools::IZoomTool> *
                                          zoomToolRepository,
                                         int zoomToolId
                                        )
    : m_zoomToolRepository(zoomToolRepository),
      m_zoomToolId(zoomToolId)
  {
  }

  void
  ZoomToolCfgService::setMode(UILayer::AbstractModel::ToolConfig::Properties::ZoomMode mode) {
    AbstractDomain::Tools::IZoomTool *zoomTool(m_zoomToolRepository->retrieve(m_zoomToolId));
    zoomTool->setMode(mode);
    m_zoomToolRepository->update(zoomTool);
  }

  void
  ZoomToolCfgService::setZoomStep(float step) {
    AbstractDomain::Tools::IZoomTool *zoomTool(m_zoomToolRepository->retrieve(m_zoomToolId));
    zoomTool->setStep(step);
    m_zoomToolRepository->update(zoomTool);
  }

  UILayer::AbstractModel::ToolConfig::Properties::ZoomMode
  ZoomToolCfgService::getMode() const {
    return m_zoomToolRepository->retrieve(m_zoomToolId)->getMode();
  }

  float
  ZoomToolCfgService::getZoomStep() const {
    return m_zoomToolRepository->retrieve(m_zoomToolId)->getStep();
  }
}
