#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_FOREGROUNDLAYER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_FOREGROUNDLAYER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ForegroundLayer.hpp
 * PURPOSE: Defines the ForegroundLayer template.
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

#include "Components/IContent.hpp"
#include "Dimensions.hpp"
#include "Layer.hpp"

#include <memory>

namespace SDF::ModelLayer::DomainObjects::Engine {
  // Class:      ForegroundLayer
  // Purpose:    Defines a foreground layer, with switchable content.
  // Parameters: ImplSpecT - A traits struct defining the implementation parameters for this image.
  template<class ImplSpecT>
  class ForegroundLayer : public Layer<ImplSpecT> {
  public:
    // Function:   ForegroundLayer
    // Purpose:    Constructs a new layer to the specified parameters.
    // Parameters: widthPx - The width of the layer in pixels.
    //             heightPx - The height of the layer in pixels.
    ForegroundLayer(ImageMeasure widthPx,
                     ImageMeasure heightPx
                    );

    // Function:   setContentComponent
    // Purpose:    Inserts a content component into this layer.
    // Parameters: content - The content to add.
    // Returns:    None.
    void
    setContentComponent(std::unique_ptr<Components::IContent<ImplSpecT>> content);

    Components::IContent<ImplSpecT> *
    getContentComponent();

    const Components::IContent<ImplSpecT> *
    getContentComponent() const;
  private:
    std::unique_ptr<Components::IContent<ImplSpecT>> m_content;
  };
}

#include "ForegroundLayer.tpp"

#endif
