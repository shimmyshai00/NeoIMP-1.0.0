#ifndef SDF_MODELLAYER_DOMAINOBJECTS_EDITING_FACTORIES_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_EDITING_FACTORIES_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Factories.hpp
 * PURPOSE: Defines factories for editing subsystem objects.
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

#include <SDF/Interfaces/IFactory.hpp>
#include <SDF/Interfaces/IGenerator.hpp>

#include <SDF/ModelLayer/Services/AbstractDomain/IDeltaEditor.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/IImage.hpp>

#include <fruit/fruit.h>

#include <memory>

namespace SDF::ModelLayer::DomainObjects::Editing {
  // Class:      DeltaEditorFactory
  // Purpose:    Create delta editors for images.
  // Parameters: None.
  class DeltaEditorFactory : public Interfaces::IFactory<Services::AbstractDomain::IDeltaEditor,
                                                         Services::AbstractDomain::IImage *
                                                        >
  {
  public:
    INJECT(DeltaEditorFactory(Interfaces::IGenerator<int> *uidGenerator));

    std::unique_ptr<Services::AbstractDomain::IDeltaEditor>
    create(Services::AbstractDomain::IImage *image);
  private:
    Interfaces::IGenerator<int> *m_uidGenerator;
  };
}

#endif
