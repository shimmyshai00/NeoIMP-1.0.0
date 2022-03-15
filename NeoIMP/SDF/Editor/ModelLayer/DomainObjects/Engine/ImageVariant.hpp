#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_IMAGEVARIANT_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_IMAGEVARIANT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageVariant.hpp
 * PURPOSE: Defines the ImageVariant template.
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

#include "Image.hpp"
#include "Dimensions.hpp"

#include <boost/variant2/variant.hpp>
#include <cstddef>
#include <string>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine {
  // Class:      ImageVariant
  // Purpose:    Defines a variant type which can hold a variety of different kinds of images.
  //             This is useful for storing images in repositories as a homogenized collection. In
  //             order to use the variant, it must be visited with std::visit. This is like
  //             Boost.GIL's any_image; but we cannot use that here as we have too much elaboration
  //             on top and so must roll our own.
  // Parameters: ImplSpecTs - The implementation spec types going into the variant.
  template<class ... ImplSpecTs>
  class ImageVariant : public boost::variant2::variant<Image<ImplSpecTs>...>
  {
  public:
    // Function:   ImageVariant
    // Purpose:    Constructs a new variant.
    // Parameters: image - The specific-type image going into the variant. Note: so far only
    //                     consumptive move implementation is provided. We need a component clone
    //                     method for non-consumptive variant creation.
    template<class ImplSpecT>
    ImageVariant(Image<ImplSpecT> &&image);

    // Function:   getName
    // Purpose:    Gets the name of the image.
    // Parameters: None.
    // Returns:    The image name.
    std::string
    getName() const;

    // Function:   getFileSpec
    // Purpose:    Gets the file spec of the image.
    // Parameters: None.
    // Returns:    The image file spec.
    std::string
    getFileSpec() const;

    // Function:   getWidthPx
    // Purpose:    Gets the width of the image in pixels.
    // Parameters: None.
    // Returns:    The width of the image in pixels.
    ImageMeasure
    getWidthPx() const;

    // Function:   getHeightPx
    // Purpose:    Gets the height of the image in pixels.
    // Parameters: None.
    // Returns:    The height of the image in pixels.
    ImageMeasure
    getHeightPx() const;

    // Function:   getRect
    // Purpose:    Get the image's total bounding rectangle.
    // Parameters: None.
    // Returns:    The total bounding rectangle.
    ImageRect
    getRect() const;

    // Function:   getResolutionPpi
    // Purpose:    Gets the resolution of the image in PPI.
    // Parameters: None.
    // Returns:    The resolution of the image in PPI.
    float
    getResolutionPpi() const;

    // Function:   getNumLayers
    // Purpose:    Gets the number of image layers.
    // Parameters: None.
    // Returns:    The number of layers in the image.
    std::size_t
    getNumLayers() const;
  };
}

namespace SDF::Editor::ModelLayer::DomainObjects::Engine {
  // Helper method.
  template<typename V, class Variant>
  auto visitImage(V&& visitor, Variant &&variant) {
    // nb: this weird construct seems sus; may need to rethink this.
    return boost::variant2::visit(std::forward<V>(visitor), std::forward<Variant>(variant));
  }
}

#include "ImageVariant.tpp"

#endif
