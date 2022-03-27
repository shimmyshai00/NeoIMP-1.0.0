#ifndef SDF_EDITOR_MODELLAYER_SERVICES_COLORMODELS_UIREVCOLORMODEL_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_COLORMODELS_UIREVCOLORMODEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiRevColorModel.hpp
 * PURPOSE: Defines the UiRevColorModel template.
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

#include "../../../UILayer/AbstractModel/Defs/Color/IColor.hpp"
#include "../../DomainObjects/Engine/IRevColorModel.hpp"

namespace SDF::Editor::ModelLayer::Services::ColorModels {
  // Class:      UiRevColorModel
  // Purpose:    Builds a dynamically adaptable color model type capable of operating on UI-layer
  //             abstract IColors.
  // Parameters: ModelEnumT - The enumeration of color types that IColor requires.
  template<class ModelEnumT>
  class UiRevColorModel : public DomainObjects::Engine::IRevColorModel<
                            UILayer::AbstractModel::Defs::Color::IColor<ModelEnumT>
                          >
  {
  public:
    UiRevColorModel();

    std::size_t
    getNumChannels() const;

    float
    getValueMin(std::size_t channel) const;

    float
    getValueMax(std::size_t channel) const;

    float
    getQuantizationStep(std::size_t channel) const;

    void
    valuesToPixel(const float *values, UILayer::AbstractModel::Defs::Color::IColor<ModelEnumT> &px)
      const;
  };
}

#include "UiRevColorModel.tpp"

#endif
