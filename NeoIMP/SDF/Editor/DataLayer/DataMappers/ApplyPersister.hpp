#ifndef SDF_EDITOR_DATALAYER_DATAMAPPERS_APPLYPERSISTER_HPP
#define SDF_EDITOR_DATALAYER_DATAMAPPERS_APPLYPERSISTER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ApplyPersister.hpp
 * PURPOSE: Defines methods to apply a persister to an image.
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

#include "../../ModelLayer/DomainObjects/Engine/Image.hpp"
#include "../../ModelLayer/DomainObjects/Engine/ImageVariant.hpp"

#include <boost/variant2/variant.hpp>

namespace SDF::Editor::DataLayer::DataMappers {
  template<class Persister, class ImplSpecT>
  void applyPersister(Persister pers, ModelLayer::DomainObjects::Engine::Image<ImplSpecT> &image) {
    pers(image);
  }

  template<class Persister, class ... ImplSpecTs>
  void applyPersister(
    Persister pers,
    ModelLayer::DomainObjects::Engine::ImageVariant<ImplSpecTs...> &image
  ) {
    using namespace ModelLayer::DomainObjects;
    Engine::visitImage([&](auto &&rhs) { pers(rhs); }, image);
  }
}

#endif
