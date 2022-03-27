#ifndef SDF_EDITOR_MODELLAYER_SERVICES_COLORMODELS_UIREVCOLORMODEL_TPP
#define SDF_EDITOR_MODELLAYER_SERVICES_COLORMODELS_UIREVCOLORMODEL_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiRevColorModel.tpp
 * PURPOSE: Implements the UiRevColorModel template.
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

namespace SDF::Editor::ModelLayer::Services::ColorModels {
  template<class ModelEnumT>
  UiRevColorModel<ModelEnumT>::UiRevColorModel() {
  }

  template<class ModelEnumT>
  std::size_t
  UiRevColorModel<ModelEnumT>::getNumChannels() const {
    return CHANNELS_AUTO;
  }

  template<class ModelEnumT>
  float
  UiRevColorModel<ModelEnumT>::getValueMin(std::size_t channel) const {
    return 0.0f;
  }

  template<class ModelEnumT>
  float
  UiRevColorModel<ModelEnumT>::getValueMax(std::size_t channel) const {
    return 1.0f; // nb: assumes no HDR UIs
  }

  template<class ModelEnumT>
  float
  UiRevColorModel<ModelEnumT>::getQuantizationStep(std::size_t channel) const {
    return 0.0f;
  }

  template<class ModelEnumT>
  void
  UiRevColorModel<ModelEnumT>::valuesToPixel(
    const float *values,
    UILayer::AbstractModel::Defs::Color::IColor<ModelEnumT> &px
  ) const {
    for(std::size_t i(0); i < getNumChannels(); ++i) {
      px.setValueF(values[i]);
    }
  }
}

#endif
