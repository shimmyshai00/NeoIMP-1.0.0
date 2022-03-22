#ifndef SDF_EDITOR_MODELLAYER_SERVICES_COLORSPACES_UIAUTOSPACE_TPP
#define SDF_EDITOR_MODELLAYER_SERVICES_COLORSPACES_UIAUTOSPACE_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiAutoSpace.tpp
 * PURPOSE: Implements the UiAutoSpace template.
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

#include <array>

namespace SDF::Editor::ModelLayer::Services::ColorSpaces {
  template<class FundamentalTraitsT, class MapT>
  UiAutoSpace<FundamentalTraitsT, MapT>::UiAutoSpace(const UiAutoColor &autoColorModel)
    : m_autoColorModel(autoColorModel)
  {
  }

  template<class FundamentalTraitsT, class MapT>
  const DomainObjects::Engine::IColorModel<
    std::shared_ptr<UILayer::AbstractModel::Data::Color::IColor>
  > &
  UiAutoSpace<FundamentalTraitsT, MapT>::getColorModel() const {
    return m_autoColorModel;
  }

  template<class FundamentalTraitsT, class MapT>
  void
  UiAutoSpace<FundamentalTraitsT, MapT>::pixelToFundamental(
    std::shared_ptr<UILayer::AbstractModel::Data::Color::IColor> pixel,
    float *fs
  ) const {
    // Normalize the channels.
    std::array<float, 5> m_nrml;
    m_autoColorModel.convertPixelTo(pixel, m_nrml);

    for(std::size_t i(0); i < pixel->getNumChannels(); ++i) {
      float channelWidth = pixel->getChannelMax(i) - pixel->getChannelMin(i);
      m_nrml.at(i) = (pixel->get(i) - pixel->getChannelMin(i)) / channelWidth;
    }

    // Convert to the fundamental space.
    MapT().nrmlToFundamental(m_nrml, fs);
  }

  template<class FundamentalTraitsT, class MapT>
  std::shared_ptr<UILayer::AbstractModel::Data::Color::IColor>
  UiAutoSpace<FundamentalTraitsT, MapT>::fundamentalToPixel(float *fs) const {
    // Convert to the normal space.
    std::array<float, 5> m_nrml;
    MapT().fundamentalToNrml(fs, m_nrml);

    // Unnormalize the channels.
    for(std::size_t i(0); i < m_autoColorModel.getNumChannels(); ++i) {
      float channelWidth = m_autoColorModel.getChannelMax(i) - m_autoColorModel.getChannelMin(i);
      m_nrml.at(i) = (m_nrml.at(i) * channelWidth) + m_autoColorModel.getChannelMin(i);
    }

    return m_autoColorModel.convertToPixel(m_nrml);
  }
}

#endif
