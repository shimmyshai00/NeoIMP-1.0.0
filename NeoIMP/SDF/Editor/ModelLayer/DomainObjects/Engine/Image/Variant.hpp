#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_IMAGE_VARIANT_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_IMAGE_VARIANT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Variant.hpp
 * PURPOSE: Defines the Variant template.
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

#include "../Dimensions.hpp"
#include "Image.hpp"

#include <boost/variant2/variant.hpp>
#include <cstddef>
#include <string>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Image {
  // Class:      Variant
  // Purpose:    Defines a variant type which can hold a variety of different kinds of images.
  //             This is useful for storing images in repositories as a homogenized collection. In
  //             order to use the variant, it must be visited with std::visit. This is like
  //             Boost.GIL's any_image; but we cannot use that here as we have too much elaboration
  //             on top and so must roll our own.
  // Parameters: ImplSpecTs - The implementation spec types going into the variant.
  template<class ... ImplSpecTs>
  class Variant : public boost::variant2::variant<Image<ImplSpecTs>...> {
  public:
    // Function:   Variant
    // Purpose:    Constructs a new variant.
    // Parameters: image - The specific-type image going into the variant. Note: so far only
    //                     consumptive move implementation is provided. We need a component clone
    //                     method for non-consumptive variant creation.
    Variant();

    template<class ImplSpecT>
    Variant(Image<ImplSpecT> &&a_image);

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

    // Function:   setName
    // Purpose:    Sets the name of the image.
    // Parameters: name - The new name to set.
    // Returns:    None.
    void
    setName(std::string a_name);

    // Function:   setResolutionPpi
    // Purpose:    Sets the image resolution (the conversion factor between pixels and physical
    //             units).
    // Parameters: resolutionPpi - The new resolution in PPI.
    // Returns:    None.
    void
    setResolutionPpi(float a_resolutionPpi);

    // Function:   getNumLayers
    // Purpose:    Gets the number of image layers.
    // Parameters: None.
    // Returns:    The number of layers in the image.
    std::size_t
    getNumLayers() const;
  };
}

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Image {
  // Helper method.
  template<typename VT, class VariantT>
  auto visit(VT&& a_visitor, VariantT &&a_variant) {
    // nb: this weird construct seems sus; may need to rethink this.
    return boost::variant2::visit(std::forward<VT>(a_visitor), std::forward<VariantT>(a_variant));
  }

  template<typename VT, class VariantT>
  auto constVisit(VT&& a_visitor, const VariantT &&a_variant) {
    // nb: this weird construct seems sus; may need to rethink this.
    return boost::variant2::visit(std::forward<VT>(a_visitor), std::forward<const VariantT>(
      a_variant));
  }
}

#include "Variant.tpp"

#endif
