/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Component.cpp
 * PURPOSE: Implements the DI component for the editing subsystem.
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

#include <SDF/ModelLayer/DomainObjects/Editing/Component.hpp>

#include <Support/UidGenerator.hpp>

#include <SDF/ModelLayer/DomainObjects/Editing/Factories.hpp>

#include <SDF/ModelLayer/DomainObjects/Editing/Tools/Component.hpp>

namespace SDF::ModelLayer::DomainObjects::Editing {
  Component
  getComponent() {
    return fruit::createComponent()
      .bind<Interfaces::IGenerator<int>, Support::UidGenerator<int>>()
      .bind<Interfaces::IFactory<Services::AbstractDomain::IDeltaEditor,
                                 Services::AbstractDomain::IImage *
                                >,
            DeltaEditorFactory
           >()
      .install(Tools::getComponent);
  }
}
