#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Render.hpp
 * PURPOSE: Defines the Render template.
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

#include "../../IImageOperation.hpp"
#include "../../Rendering.hpp"
#include "../Image.hpp"
#include "../AnyImage.hpp"

#include <cstddef>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil::Algorithm {
  // Class:      Render
  // Purpose:    Renders a GIL image view to a rendering buffer.
  // Parameters: GilImageT - The type of GIL image to use.
  //             GilImageTs - The variant types to use.
  template<class GilImageT>
  class Render : public IImageOperation<Image<GilImageT>> {
  public:
    // Function:   Render
    // Purpose:    Construct the renderer.
    // Parameters: outBuffer - The buffer to output the rendering to.
    Render(Rendering *outBuffer);

    bool
    performOperation(Image<GilImageT> &imageImpl,
                     const std::vector<std::size_t> &layerNums,
                     const std::vector<Math::Rect<std::size_t>> &layerRects,
                     IProgressListener *progress
                    );
  private:
    Rendering *m_outBuffer;
  };

  template<class ... GilImageTs>
  class Render<AnyImage<GilImageTs...>> : public IImageOperation<AnyImage<GilImageTs...>> {
  public:
    Render(Rendering *outBuffer);

    bool
    performOperation(AnyImage<GilImageTs...> &imageImpl,
                     const std::vector<std::size_t> &layerNums,
                     const std::vector<Math::Rect<std::size_t>> &layerRects,
                     IProgressListener *progress
                    );
  private:
    Rendering *m_outBuffer;
  };
}

#include "Render.tpp"

#endif
