/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Component.cpp
 * PURPOSE: Defines the DI component for the whole GUI.
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

#include <SDF/DataLayer/Repositories/Component.hpp>

#include <SDF/DataLayer/Repositories/ImageRepository.hpp>
#include <SDF/DataLayer/Repositories/MemoryOnlyRepository.hpp>
#include <SDF/DataLayer/Repositories/FilterRepository.hpp>

#include <SDF/DataLayer/Persistence/Component.hpp>

namespace SDF::DataLayer::Repositories {
  Component
  getComponent() {
    return fruit::createComponent()
      .bind<ModelLayer::AbstractData::IRepository<ModelLayer::Services::AbstractDomain::IImage>, ImageRepository>()
      .bind<ModelLayer::AbstractData::IRepository<ModelLayer::Services::AbstractDomain::IRenderBuffer>,
            MemoryOnlyRepository<ModelLayer::Services::AbstractDomain::IRenderBuffer>
           >()
      .bind<ModelLayer::AbstractData::IFileSystemPersistenceController<ModelLayer::Services::AbstractDomain::IImage,
                                                                       ModelLayer::AbstractData::ImageFileFormat
                                                                      >,
            ImageRepository
           >()
      .bind<ModelLayer::AbstractData::IRepository<ModelLayer::Services::AbstractDomain::ITool>,
            MemoryOnlyRepository<ModelLayer::Services::AbstractDomain::ITool>
           >()
      .bind<ModelLayer::AbstractData::IRepository<ModelLayer::Services::AbstractDomain::IDeltaEditor>,
            MemoryOnlyRepository<ModelLayer::Services::AbstractDomain::IDeltaEditor>
           >()
      .bind<ModelLayer::AbstractData::IRepository<ModelLayer::Services::AbstractDomain::Tools::IZoomTool>,
            FilterRepository<ModelLayer::Services::AbstractDomain::ITool,
                             ModelLayer::Services::AbstractDomain::Tools::IZoomTool
                            >
           >()
      .install(Persistence::getComponent);
  }
}
