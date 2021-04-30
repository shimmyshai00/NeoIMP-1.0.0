/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ToolBasedEditingService.cpp
 * PURPOSE: Implements the ToolBasedEditingService class.
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

#include <ToolBasedEditingService.hpp>

#include <ModelLayer/Exceptions/Exceptions.hpp>
#include <DataLayer/Exceptions/Exceptions.hpp>

#include <AbstractData/IRepository.hpp>

#include <AbstractDomain/IImage.hpp>
#include <AbstractDomain/ITool.hpp>

namespace SDF::ModelLayer::Services {
  ToolBasedEditingService::ToolBasedEditingService(AbstractData::IRepository<AbstractDomain::IImage> *imageRepository,
                                                   AbstractData::IRepository<AbstractDomain::ITool> *toolRepository,
                                                   Interfaces::IFactory<AbstractDomain::ITool,
                                                                        UILayer::AbstractModel::Properties::Tool
                                                                       > *toolFactory
                                                  )
    : m_imageRepository(imageRepository),
      m_toolRepository(toolRepository),
      m_activeTool(UILayer::AbstractModel::Properties::TOOL_MAX)
  {
    using namespace UILayer::AbstractModel::Properties;

    addTool(TOOL_ZOOM, toolFactory->create(TOOL_ZOOM));
  }

  void
  ToolBasedEditingService::setActiveTool(UILayer::AbstractModel::Properties::Tool tool) {
    m_activeTool = tool;
  }

  void
  ToolBasedEditingService::beginToolApplication(UILayer::AbstractModel::Handle handle) {
    try {
      if(m_toolIdMap.find(m_activeTool) != m_toolIdMap.end()) { // for unadded tools
        int toolId(m_toolIdMap[m_activeTool]);
        AbstractDomain::IImage *imageDocument(m_imageRepository->retrieve(handle));

        m_toolRepository->retrieve(toolId)->beginApplication(imageDocument);
      }
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  void
  ToolBasedEditingService::applyToolAtPoint(float x, float y) {
    if(m_toolIdMap.find(m_activeTool) != m_toolIdMap.end()) { // for unadded tools
      int toolId(m_toolIdMap[m_activeTool]);
      m_toolRepository->retrieve(toolId)->applyAt(x, y);
    }
  }

  void
  ToolBasedEditingService::finishToolApplication() {
    if(m_toolIdMap.find(m_activeTool) != m_toolIdMap.end()) { // for unadded tools
      int toolId(m_toolIdMap[m_activeTool]);
      m_toolRepository->retrieve(toolId)->commit();
    }
  }

  // Private member.
  void
  ToolBasedEditingService::addTool(UILayer::AbstractModel::Properties::Tool toolLabel,
                                   std::unique_ptr<AbstractDomain::ITool> tool
                                  )
  {
    int toolId(tool->getId());

    m_toolRepository->create(std::move(tool));
    m_toolIdMap[toolLabel] = toolId;
  }
}
