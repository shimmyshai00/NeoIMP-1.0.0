#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_EXCEPTIONS_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: Defines exceptions for the domain-object subsystem.
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

#include "../../../Error/Exception.hpp"
#include "../../../Error/ModelException.hpp"
#include "../../../Error/SafeString.hpp"

#include "Engine/Dimensions.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects {
  struct InvalidDimensionsException : public Error::LikelyBug<Error::ModelException> {
    Engine::ImageMeasure m_width, m_height;
    InvalidDimensionsException(Engine::ImageMeasure width, Engine::ImageMeasure height)
      : m_width(width), m_height(height)
    {}

    const char *what() const noexcept {
      Error::SafeString ret;
      ret.sPrintf("The image dimensions %d x %d are not valid.", m_width, m_height);

      return ret.get();
    }
  };

  struct ComponentExistsException : public Error::LikelyBug<Error::ModelException> {
    Error::SafeString m_id;
    ComponentExistsException(const char *id) : m_id(id) {}

    const char *what() const noexcept {
      Error::SafeString ret;
      ret.sPrintf("Tried to add a component to an entity under an id '%s' already taken by "
      "another.", m_id);

      return ret.get();
    }
  };

  struct ComponentNotFoundException : public Error::LikelyBug<Error::ModelException> {
    Error::SafeString m_id;
    ComponentNotFoundException(const char *id) : m_id(id) {}

    const char *what() const noexcept {
      Error::SafeString ret;
      ret.sPrintf("Component '%s' not found in image layer entity.", m_id);

      return ret.get();
    }
  };

  struct BadComponentCastException : public Error::LikelyBug<Error::ModelException> {
    const char *what() const noexcept {
      return "Tried to cast a component to the wrong type.";
    }
  };
}

#endif
