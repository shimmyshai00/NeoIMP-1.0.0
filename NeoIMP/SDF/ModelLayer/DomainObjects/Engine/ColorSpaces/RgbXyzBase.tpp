#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_RGBXYZBASE_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_RGBXYZBASE_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RgbXyzBase.hpp
 * PURPOSE: Defines the RgbXyzBase template.
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

namespace SDF::ModelLayer::DomainObjects::Engine::ColorSpaces {
  template<class PixelDataT>
  template<std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  RgbXyzBase<PixelDataT>::RgbXyzBase(const ColorModels::Base<PixelDataT, BitsR, BitsG, BitsB> *
                                      colorModel
                                    )
    : m_colorModel(colorModel)
  {
  }

  template<class PixelDataT>
  const IColorModel<PixelDataT> &
  RgbXyzBase<PixelDataT>::getColorModel() const {
    return *m_colorModel;
  }

  template<class PixelDataT>
  void
  RgbXyzBase<PixelDataT>::pixelToFundamental(PixelDataT pixel,
                                             float *fs
                                            ) const
  {
    float rgb[3] = { 0.0f, 0.0f, 0.0f };
    m_colorModel->decode(pixel, rgb);

    std::tuple<float, float, float> xyz(rgbToXyz(std::make_tuple(rgb[0], rgb[1], rgb[2])));

    fs[0] = std::get<0>(xyz);
    fs[1] = std::get<1>(xyz);
    fs[2] = std::get<2>(xyz);
  }

  template<class PixelDataT>
  PixelDataT
  RgbXyzBase<PixelDataT>::fundamentalToPixel(float *fs) const {
    std::tuple<float, float, float> rgb(xyzToRgb(std::make_tuple(fs[0], fs[1], fs[2])));
    float rgbArr[3] = { std::get<0>(rgb), std::get<1>(rgb), std::get<2>(rgb) };
    return m_colorModel->encode(rgbArr);
  }
}

#endif
