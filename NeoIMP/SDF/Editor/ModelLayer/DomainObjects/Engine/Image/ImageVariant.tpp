#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_IMAGEVARIANT_TPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_IMAGEVARIANT_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageVariant.tpp
 * PURPOSE: Implements the ImageVariant template.
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

namespace SDF::Editor::ModelLayer::DomainObjects::Engine {
  template<class ... ImplSpecTs>
  ImageVariant<ImplSpecTs...>::ImageVariant()
    : boost::variant2::variant<Image<ImplSpecTs>...>()
  {
  }
  
  template<class ... ImplSpecTs>
  template<class ImplSpecT>
  ImageVariant<ImplSpecTs...>::ImageVariant(Image<ImplSpecT> &&image)
    : boost::variant2::variant<Image<ImplSpecTs>...>(std::move(image))
  {
  }

  template<class ... ImplSpecTs>
  std::string
  ImageVariant<ImplSpecTs...>::getName() const {
    return visitImage([](auto &&arg) { return arg.getName(); }, *this);
  }

  template<class ... ImplSpecTs>
  std::string
  ImageVariant<ImplSpecTs...>::getFileSpec() const {
    return visitImage([](auto &&arg) { return arg.getFileSpec(); }, *this);
  }

  template<class ... ImplSpecTs>
  ImageMeasure
  ImageVariant<ImplSpecTs...>::getWidthPx() const {
    return visitImage([](auto &&arg) { return arg.getWidthPx(); }, *this);
  }

  template<class ... ImplSpecTs>
  ImageMeasure
  ImageVariant<ImplSpecTs...>::getHeightPx() const {
    return visitImage([](auto &&arg) { return arg.getHeightPx(); }, *this);
  }

  template<class ... ImplSpecTs>
  ImageRect
  ImageVariant<ImplSpecTs...>::getRect() const {
    return visitImage([](auto &&arg) { return arg.getRect(); }, *this);
  }

  template<class ... ImplSpecTs>
  float
  ImageVariant<ImplSpecTs...>::getResolutionPpi() const {
    return visitImage([](auto &&arg) { return arg.getResolutionPpi(); }, *this);
  }

  template<class ... ImplSpecTs>
  void
  ImageVariant<ImplSpecTs...>::setName(std::string name) {
    visitImage([=](auto &&arg) { arg.setName(name); }, *this);
  }

  template<class ... ImplSpecTs>
  void
  ImageVariant<ImplSpecTs...>::setResolutionPpi(float resolutionPpi) {
    visitImage([=](auto &&arg) { arg.setResolutionPpi(resolutionPpi); }, *this);
  }

  template<class ... ImplSpecTs>
  std::size_t
  ImageVariant<ImplSpecTs...>::getNumLayers() const {
    return visitImage([](auto &&arg) { return arg.getNumLayers(); }, *this);
  }
}

#endif
