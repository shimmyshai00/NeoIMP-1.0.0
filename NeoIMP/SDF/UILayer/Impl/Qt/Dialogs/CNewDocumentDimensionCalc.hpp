#ifndef SDF_UILAYER_VIEWS_IMPL_QT_DIALOGS_CNEWDOCUMENTDIMENSIONCALC_HPP
#define SDF_UILAYER_VIEWS_IMPL_QT_DIALOGS_CNEWDOCUMENTDIMENSIONCALC_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CNewDocumentDimensionCalc.hpp
 * PURPOSE: Maintains and calculates the document size through the user's switching of unit settings and dimension
 *          values.
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

#include <SDF/ModelLayer/Iface/IDocumentMeasurementsServiceDependency.hpp>
#include <SDF/ModelLayer/Iface/IDocumentMeasurementsService.hpp>
#include <SDF/ModelLayer/Iface/Param/EDimensionUnit.hpp>
#include <SDF/ModelLayer/Iface/Param/EResolutionUnit.hpp>

namespace SDF::UILayer {
  namespace Impl {
    namespace Qt::Dialogs {
      class CNewDocumentDimensionCalc : public SDF::ModelLayer::Iface::IDocumentMeasurementsServiceDependency {
      public: // NB: enforce pixel/unit-value separation throughout program? (i.e. separate dimensionalities)
        CNewDocumentDimensionCalc();

        void injectWith(SDF::ModelLayer::Iface::IDocumentMeasurementsService *measurementsService);

        int getCurrentPixelWidth() const;
        int getCurrentPixelHeight() const;

        float getCurrentInchWidth() const;
        float getCurrentInchHeight() const;

        int getCurrentPpi() const;

        float getWidthInCurrentUnits() const;
        float getHeightInCurrentUnits() const;
        float getResolutionInCurrentUnits() const;

        SDF::ModelLayer::Iface::Param::EDimensionUnit getWidthUnit() const;
        SDF::ModelLayer::Iface::Param::EDimensionUnit getHeightUnit() const;
        SDF::ModelLayer::Iface::Param::EResolutionUnit getResolutionUnit() const;

        void updatePixelWidth(int newPixelWidth);
        void updatePixelHeight(int newPixelHeight);

        void updateInchWidth(float newInchWidth);
        void updateInchHeight(float newInchHeight);

        void updatePpi(int newPpi);

        void updateWidthInCurrentUnits(float newUnitWidth);
        void updateHeightInCurrentUnits(float newUnitHeight);
        void updateResolutionInCurrentUnits(float newUnitResolution);

        void updateWidthUnit(SDF::ModelLayer::Iface::Param::EDimensionUnit newWidthUnit);
        void updateHeightUnit(SDF::ModelLayer::Iface::Param::EDimensionUnit newHeightUnit);
        void updateResolutionUnit(SDF::ModelLayer::Iface::Param::EResolutionUnit newResolutionUnit);
      private:
        SDF::ModelLayer::Iface::IDocumentMeasurementsService *m_documentMeasurementsService;

        int m_currentPixelWidth;
        int m_currentPixelHeight;

        float m_currentInchWidth;
        float m_currentInchHeight;

        int m_currentPpi;

        SDF::ModelLayer::Iface::Param::EDimensionUnit m_widthUnit;
        SDF::ModelLayer::Iface::Param::EDimensionUnit m_heightUnit;
        SDF::ModelLayer::Iface::Param::EResolutionUnit m_resolutionUnit;
      };
    }
  }
}

#endif
