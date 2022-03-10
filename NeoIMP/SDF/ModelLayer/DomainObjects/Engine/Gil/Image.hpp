#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMAGE_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMAGE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Image.hpp
 * PURPOSE: Defines the Image template.
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
#include "Layer.hpp"

#include <cstddef>
#include <string>
#include <vector>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  // Class:      Image
  // Purpose:    Defines an image implemented using the Boost.GIL framework.
  // Parameters: GilBkgImageT - The underlying GIL image type (i.e. type of raster representing a
  //                            single layer). This one is for the background layer. This slightly
  //                            heterogeneous format is useful for things like targeting alpha-free
  //                            file types: the user can prevent from accidentally adding
  //                            transparency information to the background layer that would not save
  //                            out correctly.
  //             GilImageT - The underlying GIL image type for all other layers.
  // nb: should implement IMappable - rn we can get away with this
  template<class GilBkgImageT, class GilImageT>
  class Image : public IImage {
  public:
    typedef GilBkgImageT gil_bkg_image_type;
    typedef GilImageT gil_image_type;
    typedef typename GilBkgImageT::view_t gil_bkg_image_view_type;
    typedef typename GilImageT::view_t gil_image_view_type;
    typedef typename GilBkgImageT::value_type gil_bkg_image_value_type;
    typedef typename GilImageT::value_type gil_image_value_type;
  public:
    // Function:   Image
    // Purpose:    Constructs a new GIL-based image.
    // Parameters: name - The name to give to the image.
    //             fileSpec - The file spec this image will save to.
    //             widthPx - The width of this image in pixels.
    //             heightPx - The height of this image in pixels.
    //             resolutionPpi - The resolution of the image in PPI.
    //             baseColor - The initial background color to fill the image with.
    Image(std::string name,
          std::string fileSpec,
          ImageMeasure widthPx,
          ImageMeasure heightPx,
          float resolutionPpi,
          typename GilBkgImageT::value_type baseColor
         );

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

    ImageRect
    getRect() const;

    const IColorModelImpl<typename GilBkgImageT::value_type> &
    getBkgColorModel() const;

    const IColorModelImpl<typename GilImageT::value_type> &
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
    // Parameters: rect - The rectangle to get, for getting a subregion.
    // Returns:    The view onto the background layer.
    typename GilBkgImageT::view_t
    getBkgLayerView();

    typename GilBkgImageT::const_view_t
    getBkgLayerView() const;

    typename GilBkgImageT::view_t
    getBkgLayerView(ImageRect rect);

    typename GilBkgImageT::const_view_t
    getBkgLayerView(ImageRect rect) const;

    // Function:   getLayerView
    // Purpose:    Gets a Boost.GIL view onto the data for a single layer.
    // Parameters: layerNum - The layer number to get the view onto. (Note: this starts at 1, not 0,
    //                        to keep consistency with the other methods. 0 is the background layer,
    //                        but it may have a different Type.)
    //             rect - The rectangle to get, for getting a subregion.
    // Returns:    The view onto this layer.
    typename GilImageT::view_t
    getLayerView(std::size_t layerNum);

    typename GilImageT::const_view_t
    getLayerView(std::size_t layerNum) const;

    typename GilImageT::view_t
    getLayerView(std::size_t layerNum,
                 ImageRect rect
                );

    typename GilImageT::const_view_t
    getLayerView(std::size_t layerNum,
                 ImageRect rect
                ) const;
  private:
    template<class ... GilImageTs>
    friend class AnyImage;

    std::string m_name;
    std::string m_fileSpec;

    ImageMeasure m_widthPx;
    ImageMeasure m_heightPx;
    float m_resolutionPpi;

    Layer<GilBkgImageT> m_backgroundLayer;
    std::vector<Layer<GilImageT>> m_layers;
  };
}

#include "Image.tpp"

#endif
