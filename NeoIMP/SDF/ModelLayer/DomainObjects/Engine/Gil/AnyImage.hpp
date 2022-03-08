#ifndef SDF_MODELLAYER_DOMAINOBJECTS_GIL_ANYIMAGE_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_GIL_ANYIMAGE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AnyImage.hpp
 * PURPOSE: Defines the AnyImage template.
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

#include "../../IMappable.hpp"
#include "../Dimensions.hpp"
#include "../IImage.hpp"
#include "ColorModels/Defs.hpp"
#include "AnyLayer.hpp"

#include <boost/gil/extension/dynamic_image/any_image.hpp>
#include <boost/gil/extension/dynamic_image/any_image_view.hpp>

#include <cstddef>
#include <string>
#include <vector>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  // Class:      AnyImage
  // Purpose:    Defines a variant image implemented using the Boost.GIL framework.
  // Parameters: GilImageTs - The types going into the variant.
  template<class ... GilImageTs>
  class AnyImage : public IImage { // nb: should implement IMappable - rn we can get away with this
  public:
    // Function:   AnyImage
    // Purpose:    Constructs a new variant from an image.
    // Parameters: image - The image to construct from.
    template<class GilBkgImageT, class GilImageT>
    AnyImage(const Image<GilBkgImageT, GilImageT> &image);

    template<class GilBkgImageT, class GilImageT>
    AnyImage(Image<GilBkgImageT, GilImageT> &&image);

    std::string
    getName() const;

    std::string
    getFileSpec() const;

    ImageMeasure
    getWidthPx() const;

    ImageMeasure
    getHeightPx() const;

    float
    getResolutionPpi() const;

    IColorModel &
    getBkgColorModel() const;

    IColorModel &
    getColorModel() const;

    std::size_t
    getNumLayers() const;

    ImageMeasure
    getLayerWidthPx(std::size_t which) const;

    ImageMeasure
    getLayerHeightPx(std::size_t which) const;

    ImageRect
    getLayerRect(std::size_t which) const;

    // Function:   getBkgLayerView
    // Purpose:    Gets a Boost.GIL view onto the data for the background layer.
    // Parameters: None.
    // Returns:    The view onto the background layer.
    typename boost::gil::any_image<GilImageTs...>::view_t
    getBkgLayerView();

    typename boost::gil::any_image<GilImageTs...>::const_view_t
    getBkgLayerView() const;

    // Function:   getLayerView
    // Purpose:    Gets a Boost.GIL view onto the data for a single layer.
    // Parameters: layerNum - The layer number to get the view onto. (still begins at 1)
    // Returns:    The view onto this layer.
    typename boost::gil::any_image<GilImageTs...>::view_t
    getLayerView(std::size_t layerNum);

    typename boost::gil::any_image<GilImageTs...>::const_view_t
    getLayerView(std::size_t layerNum) const;
  private:
    std::string m_name;
    std::string m_fileSpec;

    ImageMeasure m_widthPx;
    ImageMeasure m_heightPx;
    float m_resolutionPpi;

    IColorModel *m_bkgColorModel;
    IColorModel *m_colorModel;

    AnyLayer<GilImageTs...> m_backgroundLayer;
    std::vector<AnyLayer<GilImageTs...>> m_layers;
  };
}

#include "AnyImage.tpp"

#endif
