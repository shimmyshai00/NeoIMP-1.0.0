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
    InvalidDimensionsException(Engine::ImageMeasure a_width, Engine::ImageMeasure a_height)
      : m_width(a_width), m_height(a_height)
    {
      whatPrintf("The image dimensions %d x %d are not valid.", m_width, m_height);
    }
  };

  struct ComponentExistsException : public Error::LikelyBug<Error::ModelException> {
    Error::SafeString m_id;
    ComponentExistsException(const char *a_id) : m_id(a_id) {
      whatPrintf("Tried to add a component to an entity under an id '%s' already taken by "
      "another.", m_id);
    }
  };

  struct ComponentNotFoundException : public Error::LikelyBug<Error::ModelException> {
    Error::SafeString m_id;
    ComponentNotFoundException(const char *a_id) : m_id(a_id) {
      whatPrintf("Component '%s' not found in image layer entity.", m_id);
    }
  };

  struct BadComponentCastException : public Error::LikelyBug<Error::ModelException> {
    BadComponentCastException() {
      whatPrintf("Tried to cast a component to the wrong type.");
    }
  };

  struct BrokenPipelineException : public Error::LikelyBug<Error::ModelException> {
    BrokenPipelineException() {
      whatPrintf("Encountered a break in the render pipeline.");
    }
  };
}

#endif
