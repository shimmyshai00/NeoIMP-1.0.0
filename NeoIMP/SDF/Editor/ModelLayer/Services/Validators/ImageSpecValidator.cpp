/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageSpecValidator.cpp
 * PURPOSE: Implements the ImageSpecValidator class.
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

#include "ImageSpecValidator.hpp"

#include "Exceptions.hpp"

namespace SDF::Editor::ModelLayer::Services::Validators {
  namespace Impl {
    class ImageSpecValidatorResult : public Common::IValidationResult {
    public:
      ImageSpecValidatorResult()
        : m_isWidthValid(false),
          m_isWidthUnitValid(false),
          m_isHeightValid(false),
          m_isHeightUnitValid(false),
          m_isResolutionValid(false),
          m_isResolutionUnitValid(false),
          m_isColorModelValid(false)
      {
      }

      bool
      isValid() const {
        return m_isWidthValid &&
          m_isWidthUnitValid &&
          m_isHeightValid &&
          m_isHeightUnitValid &&
          m_isResolutionValid &&
          m_isResolutionUnitValid &&
          m_isColorModelValid;
      }

      void
      throwFrom() {
        if(!m_isWidthValid) throw WidthInvalidException();
        if(!m_isWidthUnitValid) throw WidthUnitInvalidException();
        if(!m_isHeightValid) throw HeightInvalidException();
        if(!m_isHeightUnitValid) throw HeightUnitInvalidException();
        if(!m_isResolutionValid) throw ResolutionInvalidException();
        if(!m_isResolutionUnitValid) throw ResolutionUnitInvalidException();
        if(!m_isColorModelValid) throw ColorModelInvalidException();
      }

      void
      onWidthValidated() {
        m_isWidthValid = true;
      }

      void
      onWidthUnitValidated() {
        m_isWidthUnitValid = true;
      }

      void
      onHeightValidated() {
        m_isHeightValid = true;
      }

      void
      onHeightUnitValidated() {
        m_isHeightUnitValid = true;
      }

      void
      onResolutionValidated() {
        m_isResolutionValid = true;
      }

      void
      onResolutionUnitValidated() {
        m_isResolutionUnitValid = true;
      }

      void
      onColorModelValidated() {
        m_isColorModelValid = true;
      }
    private:
      bool m_isWidthValid;
      bool m_isWidthUnitValid;
      bool m_isHeightValid;
      bool m_isHeightUnitValid;
      bool m_isResolutionValid;
      bool m_isResolutionUnitValid;
      bool m_isColorModelValid;
    };
  }

  std::shared_ptr<Common::IValidationResult>
  ImageSpecValidator::validate(const UILayer::AbstractModel::Defs::ImageSpec &obj) const {
    using namespace UILayer::AbstractModel::Defs;

    auto p = std::make_shared<Impl::ImageSpecValidatorResult>();

    unsigned int failCodeAccumulator = 0;

    if(obj.width > 0.0f) p->onWidthValidated();
    if(obj.widthUnit < LENGTH_UNIT_MAX) p->onWidthUnitValidated();
    if(obj.height > 0.0f) p->onHeightValidated();
    if(obj.heightUnit < LENGTH_UNIT_MAX) p->onHeightUnitValidated();
    if(obj.resolution > 0.0f) p->onResolutionValidated();
    if(obj.resolutionUnit < RESOLUTION_UNIT_MAX) p->onResolutionUnitValidated();
    if(obj.colorModel < Color::COLOR_MODEL_MAX) p->onColorModelValidated();

    return p;
  }
}
