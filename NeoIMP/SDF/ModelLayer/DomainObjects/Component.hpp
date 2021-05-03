#ifndef SDF_MODELLAYER_DOMAINOBJECTS_COMPONENT_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_COMPONENT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Component.hpp
 * PURPOSE: Defines the DI component for the domain object subsystem.
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

#include <SDF/ModelLayer/DomainObjects/Algorithms/Component.hpp>
#include <SDF/ModelLayer/DomainObjects/Image/Gil/Component.hpp>

#include <SDF/Interfaces/IFactory.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/Algorithms/Annotations.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/IImage.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/IImageDataVisitor.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/IRenderBuffer.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/IDeltaEditor.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/ITool.hpp>

#include <SDF/Interfaces/IMessageBroker.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/Defs/ImageChanges.hpp>

#include <SDF/ModelLayer/Services/AbstractDomain/DocumentSpec.hpp>
#include <SDF/UILayer/AbstractModel/Properties/Tool.hpp>

#include <SDF/ModelLayer/Services/AbstractDomain/IObjectMap.hpp>
#include <SDF/ModelLayer/AbstractData/IRepository.hpp>

#include <fruit/fruit.h>

namespace SDF::ModelLayer::DomainObjects {
  typedef fruit::Component<fruit::Required<AbstractData::IRepository<Services::AbstractDomain::IDeltaEditor>>,
                           fruit::Annotated<Services::AbstractDomain::Algorithms::RendererAlgorithm,
                                            Interfaces::IFactory<Services::AbstractDomain::IImageDataVisitor,
                                                                 Services::AbstractDomain::IRenderBuffer *
                                                                >
                                           >,
                           fruit::Annotated<Services::AbstractDomain::Algorithms::RGB32Buffer,
                                            Interfaces::IFactory<Services::AbstractDomain::IRenderBuffer,
                                                                 std::size_t,
                                                                 std::size_t
                                                                >
                                           >,
                           Interfaces::IFactory<Services::AbstractDomain::IImage,
                                                Services::AbstractDomain::DocumentSpec
                                               >,
                           Interfaces::IFactory<Services::AbstractDomain::ITool,
                                                UILayer::AbstractModel::Properties::Tool
                                               >,
                           Interfaces::IFactory<Services::AbstractDomain::IDeltaEditor,
                                                Services::AbstractDomain::IImage *
                                               >,
                           Interfaces::IMessageBroker<Services::AbstractDomain::Defs::ImageChange>,
                           Services::AbstractDomain::IObjectMap<Services::AbstractDomain::IImage,
                                                                Services::AbstractDomain::IDeltaEditor
                                                               >
                          >
  Component;

  Component getComponent();
}

#endif
