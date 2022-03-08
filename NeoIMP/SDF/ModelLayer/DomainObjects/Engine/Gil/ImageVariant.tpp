#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMAGEVARIANT_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMAGEVARIANT_TPP

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

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  template<class ... ImageTs>
  template<typename T>
  ImageVariant<ImageTs...>::ImageVariant(const T& image)
    : boost::variant2::variant<ImageTs...>(image)
  {
  }

  template<class ... ImageTs>
  template<typename T>
  ImageVariant<ImageTs...>::ImageVariant(T&& image)
    : boost::variant2::variant<ImageTs...>(std::move(image))
  {
  }

  template<class ... ImageTs>
  std::string
  ImageVariant<ImageTs...>::getName() const {
    return boost::variant2::visit([](IImage const &v) { return v.getName(); }, *this);
  }

  template<class ... ImageTs>
  std::string
  ImageVariant<ImageTs...>::getFileSpec() const {
    return boost::variant2::visit([](IImage const &v) { return v.getFileSpec(); }, *this);
  }

  template<class ... ImageTs>
  ImageMeasure
  ImageVariant<ImageTs...>::getWidthPx() const {
    return boost::variant2::visit([](IImage const &v) { return v.getWidthPx(); }, *this);
  }

  template<class ... ImageTs>
  ImageMeasure
  ImageVariant<ImageTs...>::getHeightPx() const {
    return boost::variant2::visit([](IImage const &v) { return v.getHeightPx(); }, *this);
  }

  template<class ... ImageTs>
  float
  ImageVariant<ImageTs...>::getResolutionPpi() const {
    return boost::variant2::visit([](IImage const &v) { return v.getResolutionPpi(); }, *this);
  }

  template<class ... ImageTs>
  const IColorModel &
  ImageVariant<ImageTs...>::getBkgColorModel() const {
    return boost::variant2::visit([](IImage const &v) -> const IColorModel & {
      return v.getBkgColorModel();
    }, *this);
  }

  template<class ... ImageTs>
  const IColorModel &
  ImageVariant<ImageTs...>::getColorModel() const {
    return boost::variant2::visit([](IImage const &v) -> const IColorModel & {
      return v.getColorModel();
    }, *this);
  }

  template<class ... ImageTs>
  std::size_t
  ImageVariant<ImageTs...>::getNumLayers() const {
    return boost::variant2::visit([](IImage const &v) { return v.getNumLayers(); }, *this);
  }

  template<class ... ImageTs>
  ImageMeasure
  ImageVariant<ImageTs...>::getLayerWidthPx(std::size_t which) const {
    return boost::variant2::visit([=](IImage const &v) { return v.getLayerWidthPx(which); }, *this);
  }

  template<class ... ImageTs>
  ImageMeasure
  ImageVariant<ImageTs...>::getLayerHeightPx(std::size_t which) const {
    return boost::variant2::visit([=](IImage const &v) { return v.getLayerHeightPx(which); },
      *this);
  }

  template<class ... ImageTs>
  ImageRect
  ImageVariant<ImageTs...>::getLayerRect(std::size_t which) const {
    return boost::variant2::visit([=](IImage const &v) { return v.getLayerRect(which); }, *this);
  }
}

#endif
