#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ANYIMAGE_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ANYIMAGE_HPP

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

#include "../../Uid.hpp"
#include "../IImage.hpp"

#include "Image.hpp"
#include "AnyLayer.hpp"

#include <cstddef>
#include <string>
#include <vector>
#include <memory>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  // Class:      AnyImage
  // Purpose:    Defines a Boost.GIL-based image variant-like type.
  // Parameters: GilImageTs - The Boost.GIL image types, implementing RandomAccess2DImageConcept, that we desire to
  //                          store with this type of variant.
  template<class ... GilImageTs>
  class AnyImage : public IImage<AnyImage<GilImageTs...>> {
  public:
    // Function:   AnyImage
    // Purpose:    Construct a new variant from a particular concrete image type. The passed image MUST be of one of
    //             the types in GilImageTs!
    // Parameters: img - The image to construct to.
    //             doSwap - Whether to swap the image data or copy it. Swapping is faster and memory-efficient but will
    //                      RUIN the original Image object.
    template<class T>
    AnyImage(const Image<T> &img);

    template<class T>
    AnyImage(Image<T> &&img);

    // Function:   specifize
    // Purpose:    Converts this variant back into a concrete image type. Note: this MUST be supplied with the correct
    //             type or it will throw!
    // Parameters: doSwap - Whether to do the conversion by swap. If true, THIS OBJECT WILL NO LONGER BE VALID upon
    //                      successful completion!
    //template<class T>
    //Image<T> *specifize(bool doSwap);

    Uid
    getUid() const;

    AnyImage<GilImageTs...> &
    getObject();

    std::string
    getName() const;

    std::string
    getFileSpec() const;

    std::size_t
    getWidthPx() const;

    std::size_t
    getHeightPx() const;

    float
    getResolutionPpi() const;

    UILayer::AbstractModel::Defs::EColorModel
    getColorModel() const;

    std::size_t
    getNumChannels() const;

    UILayer::AbstractModel::Defs::EBitDepth
    getChannelBitDepth() const;

    std::size_t
    getNumLayers() const;

    std::size_t
    getLayerWidthPx(std::size_t which) const;

    std::size_t
    getLayerHeightPx(std::size_t which) const;

    // Function:   getLayerView
    // Purpose:    Gets a Boost.GIL view of a region of an image layer.
    // Parameters: layerNum - The layer number to get the pixel from.
    //             rect - The rectangle to get the view for.
    //             x1 - The upper-left x-coordinate of the rectangle.
    //             y1 - The upper-left y-coordinate of the rectangle.
    //             x2 - The lower-right x-coordinate of the rectangle.
    //             y2 - The lower-right y-coordinate of the rectangle.
    typename boost::gil::any_image<GilImageTs...>::view_t
    getLayerView(std::size_t layerNum);

    typename boost::gil::any_image<GilImageTs...>::const_view_t
    getLayerView(std::size_t layerNum) const;

    typename boost::gil::any_image<GilImageTs...>::view_t
    getLayerView(std::size_t layerNum,
                 Math::Rect<std::size_t> rect
                );

    typename boost::gil::any_image<GilImageTs...>::const_view_t
    getLayerView(std::size_t layerNum,
                 Math::Rect<std::size_t> rect
                ) const;

    typename boost::gil::any_image<GilImageTs...>::view_t
    getLayerView(std::size_t layerNum,
                 std::size_t x1,
                 std::size_t y1,
                 std::size_t x2,
                 std::size_t y2
                );

    typename boost::gil::any_image<GilImageTs...>::const_view_t
    getLayerView(std::size_t layerNum,
                 std::size_t x1,
                 std::size_t y1,
                 std::size_t x2,
                 std::size_t y2
                ) const;
  private:
    Uid m_uid;

    std::string m_name;
    std::string m_fileSpec;

    std::size_t m_widthPx;
    std::size_t m_heightPx;
    float m_resolutionPpi;

    UILayer::AbstractModel::Defs::EColorModel m_colorModel;
    std::size_t m_numChannels;
    UILayer::AbstractModel::Defs::EBitDepth m_bitDepth;

    std::vector<AnyLayer<GilImageTs...>> m_layers;
  };
}

#include "AnyImage.tpp"

#endif
