#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDER_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_ALGORITHM_RENDER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Render.hpp
 * PURPOSE: Defines the Render algorithm.
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

#include "../../Buffers/GridRendering.hpp"
#include "../../Image.hpp"
#include "../../Dimensions.hpp"

#include <memory>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil::Algorithm {
  // The algorithm for rendering an image. This is a good prototype for all the ingredients for a
  // Boost.GIL-based algorithm implementation (since it is the first algorithm this author
  // implemented). In order to make the generic interface as clean as possible, we cannot use a
  // usual interface to enforce a contract here because one method here must be a template, and
  // there are no virtual templates in C++. Instead we have to rely somewhat more on programmer
  // good faith and the programmer is expected to supply a template operator() that applies the
  // algorithm to an image.
  struct Render {
    Render(std::unique_ptr<Buffers::GridRendering> *resultRecvPtr);

    template<class GilSpecT>
    void
    operator()(const Image<GilSpecT> &image);
  private:
    std::unique_ptr<Buffers::GridRendering> *m_resultRecvPtr;
  };
}

#include "Render.tpp"

#endif
