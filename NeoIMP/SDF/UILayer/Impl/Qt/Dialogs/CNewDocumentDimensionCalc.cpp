/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CNewDocumentDimensionCalc.cpp
 * PURPOSE: Implementation of the dimension calculator.
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

#include <Impl/Qt/Dialogs/CNewDocumentDimensionCalc.hpp>

#include <cassert>
#include <cmath>
#include <iostream>

namespace SDF {
  namespace UILayer {
    namespace Impl::Qt::Dialogs {
      CNewDocumentDimensionCalc::CNewDocumentDimensionCalc()
      : m_documentMeasurementsService(nullptr),
        m_currentPixelWidth(720),
        m_currentPixelHeight(480),
        m_currentInchWidth(6.00f),
        m_currentInchHeight(4.00f),
        m_currentPpi(120),
        m_widthUnit(ModelLayer::DocumentModel::Spec::UNIT_PIXEL),
        m_heightUnit(ModelLayer::DocumentModel::Spec::UNIT_PIXEL),
        m_resolutionUnit(ModelLayer::DocumentModel::Spec::UNIT_PIXELS_PER_INCH)
        {
        }

      void CNewDocumentDimensionCalc::injectWith(
        ModelLayer::DocumentModel::Services::IDocumentMeasurementsService *measurementsService) {
        assert(measurementsService != nullptr);

        m_documentMeasurementsService = measurementsService;
      }

      int CNewDocumentDimensionCalc::getCurrentPixelWidth() const {
        assert(m_documentMeasurementsService != nullptr);

        return m_currentPixelWidth;
      }

      int CNewDocumentDimensionCalc::getCurrentPixelHeight() const {
        assert(m_documentMeasurementsService != nullptr);

        return m_currentPixelHeight;
      }

      float CNewDocumentDimensionCalc::getCurrentInchWidth() const {
        assert(m_documentMeasurementsService != nullptr);

        return m_currentInchWidth;
      }

      float CNewDocumentDimensionCalc::getCurrentInchHeight() const {
        assert(m_documentMeasurementsService != nullptr);

        return m_currentInchHeight;
      }

      int CNewDocumentDimensionCalc::getCurrentPpi() const {
        assert(m_documentMeasurementsService != nullptr);

        return m_currentPpi;
      }

      float CNewDocumentDimensionCalc::getWidthInCurrentUnits() const {
        using namespace SDF::ModelLayer::DocumentModel::Spec;

        assert(m_documentMeasurementsService != nullptr);

        if(m_widthUnit != UNIT_PIXEL) {
          return m_documentMeasurementsService->convertDimensionUnits(m_currentInchWidth, UNIT_INCH, m_widthUnit);
        } else {
          return m_currentPixelWidth;
        }
      }

      float CNewDocumentDimensionCalc::getHeightInCurrentUnits() const {
        using namespace SDF::ModelLayer::DocumentModel::Spec;

        assert(m_documentMeasurementsService != nullptr);

        if(m_heightUnit != UNIT_PIXEL) {
          return m_documentMeasurementsService->convertDimensionUnits(m_currentInchHeight, UNIT_INCH, m_heightUnit);
        } else {
          return m_currentPixelHeight;
        }
      }

      float CNewDocumentDimensionCalc::getResolutionInCurrentUnits() const {
        using namespace SDF::ModelLayer::DocumentModel::Spec;

        assert(m_documentMeasurementsService != nullptr);

        return m_documentMeasurementsService->convertResolutionUnits(m_currentPpi, UNIT_PIXELS_PER_INCH,
          m_resolutionUnit);
      }

      SDF::ModelLayer::DocumentModel::Spec::EDimensionUnit CNewDocumentDimensionCalc::getWidthUnit() const {
        assert(m_documentMeasurementsService != nullptr);

        return m_widthUnit;
      }

      SDF::ModelLayer::DocumentModel::Spec::EDimensionUnit CNewDocumentDimensionCalc::getHeightUnit() const {
        assert(m_documentMeasurementsService != nullptr);

        return m_heightUnit;
      }

      SDF::ModelLayer::DocumentModel::Spec::EResolutionUnit CNewDocumentDimensionCalc::getResolutionUnit() const {
        assert(m_documentMeasurementsService != nullptr);

        return m_resolutionUnit;
      }

      void CNewDocumentDimensionCalc::updatePixelWidth(int newPixelWidth) {
        assert(m_documentMeasurementsService != nullptr);

        if(newPixelWidth > 1) {
          m_currentPixelWidth = newPixelWidth;
        } else {
          m_currentPixelWidth = 1;
        }

        m_currentInchWidth = static_cast<float>(m_currentPixelWidth) / m_currentPpi;
      }

      void CNewDocumentDimensionCalc::updatePixelHeight(int newPixelHeight) {
        assert(m_documentMeasurementsService != nullptr);

        if(newPixelHeight >= 1) {
          m_currentPixelHeight = newPixelHeight;
        } else {
          m_currentPixelHeight = 1;
        }

        m_currentInchHeight = static_cast<float>(m_currentPixelHeight) / m_currentPpi;
      }

      void CNewDocumentDimensionCalc::updateInchWidth(float newInchWidth) {
        assert(m_documentMeasurementsService != nullptr);

        if(newInchWidth >= 0.0f) {
          m_currentInchWidth = newInchWidth;
        } else {
          m_currentInchWidth = 1.0f;
        }

        m_currentPixelWidth = static_cast<int>(floor(m_currentInchWidth * m_currentPpi + 0.5f));
      }

      void CNewDocumentDimensionCalc::updateInchHeight(float newInchHeight) {
        assert(m_documentMeasurementsService != nullptr);

        if(newInchHeight > 0.0f) {
          m_currentInchHeight = newInchHeight;
        } else {
          m_currentInchHeight = 1.0f;
        }

        m_currentPixelHeight = static_cast<int>(floor(m_currentInchHeight * m_currentPpi + 0.5f));
      }

      void CNewDocumentDimensionCalc::updatePpi(int newPpi) {
        assert(m_documentMeasurementsService != nullptr);

        m_currentPpi = newPpi;
        m_currentPixelWidth = static_cast<int>(floor(m_currentInchWidth * m_currentPpi + 0.5f));
        m_currentPixelHeight = static_cast<int>(floor(m_currentInchHeight * m_currentPpi + 0.5f));
      }

      void CNewDocumentDimensionCalc::updateWidthInCurrentUnits(float newUnitWidth) {
        using namespace SDF::ModelLayer::DocumentModel::Spec;

        assert(m_documentMeasurementsService != nullptr);

        if(m_widthUnit != UNIT_PIXEL) {
          if(newUnitWidth > 0.0f) {
            updateInchWidth(m_documentMeasurementsService->convertDimensionUnits(newUnitWidth, m_widthUnit, UNIT_INCH));
          } else {
            updateInchWidth(m_documentMeasurementsService->convertDimensionUnits(1.0f, m_widthUnit, UNIT_INCH));
          }
        } else {
          updatePixelWidth(newUnitWidth);
        }
      }

      void CNewDocumentDimensionCalc::updateHeightInCurrentUnits(float newUnitHeight) {
        using namespace SDF::ModelLayer::DocumentModel::Spec;

        assert(m_documentMeasurementsService != nullptr);

        if(m_heightUnit != UNIT_PIXEL) {
          if(newUnitHeight > 0.0f) {
            updateInchHeight(m_documentMeasurementsService->convertDimensionUnits(newUnitHeight,
              m_heightUnit, UNIT_INCH));
          } else {
            updateInchHeight(m_documentMeasurementsService->convertDimensionUnits(1.0f, m_heightUnit, UNIT_INCH));
          }
        } else {
          updatePixelHeight(newUnitHeight);
        }
      }

      void CNewDocumentDimensionCalc::updateResolutionInCurrentUnits(float newUnitResolution) {
        using namespace SDF::ModelLayer::DocumentModel::Spec;

        assert(m_documentMeasurementsService != nullptr);

        if(newUnitResolution >= 0.0f) {
          updatePpi(m_documentMeasurementsService->convertResolutionUnits(newUnitResolution, m_resolutionUnit,
            UNIT_PIXELS_PER_INCH));
        } else {
          updatePpi(m_documentMeasurementsService->convertResolutionUnits(0, m_resolutionUnit, UNIT_PIXELS_PER_INCH));
        }
      }

      void CNewDocumentDimensionCalc::updateWidthUnit(SDF::ModelLayer::DocumentModel::Spec::EDimensionUnit newWidthUnit) {
        assert(m_documentMeasurementsService != nullptr);

        m_widthUnit = newWidthUnit;
      }

      void CNewDocumentDimensionCalc::updateHeightUnit(SDF::ModelLayer::DocumentModel::Spec::EDimensionUnit newHeightUnit) {
        assert(m_documentMeasurementsService != nullptr);

        m_heightUnit = newHeightUnit;
      }

      void CNewDocumentDimensionCalc::updateResolutionUnit(
        SDF::ModelLayer::DocumentModel::Spec::EResolutionUnit newResolutionUnit) {
          assert(m_documentMeasurementsService != nullptr);

          m_resolutionUnit = newResolutionUnit;
        }
    }
  }
}
