#ifndef SDF_MODELLAYER_DOMAINOBJECTS_EDITING_TOOLS_FACTORY_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_EDITING_TOOLS_FACTORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Factory.hpp
 * PURPOSE: Defines the Factory class.
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

#include <SDF/UILayer/AbstractModel/Properties/Tool.hpp>

#include <fruit/fruit.h>

#include <memory>

namespace SDF::ModelLayer {
  namespace Services::AbstractDomain {
    class ITool;
  }

  namespace DomainObjects::Editing::Tools {
    // Class:      Factory
    // Purpose:    Create new editing tool intances.
    // Parameters: None.
    class Factory : public Interfaces::IFactory<Services::AbstractDomain::ITool,
                                                UILayer::AbstractModel::Properties::Tool
                                               >
    {
    public:
      INJECT(Factory(Interfaces::IGenerator<int> *uidGenerator));

      std::unique_ptr<Services::AbstractDomain::ITool>
      create(UILayer::AbstractModel::Properties::Tool toolEnum);
    private:
      Interfaces::IGenerator<int> *m_uidGenerator;
    };
  }
}

#endif
