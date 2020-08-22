#ifndef SDF_UILAYER_VIEWS_IMPL_QT_DIALOGS_CNEWDOCUMENTDIALOG_HPP
#define SDF_UILAYER_VIEWS_IMPL_QT_DIALOGS_CNEWDOCUMENTDIALOG_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CNewDocumentDialog.hpp
 * PURPOSE: The Qt dialog for getting the parameters for a new document.
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

#include <QDialog>
#include <QComboBox>

#include <SDF/ModelLayer/Iface/IDocumentServiceDependency.hpp>
#include <SDF/ModelLayer/Iface/IDocumentMeasurementsServiceDependency.hpp>
#include <SDF/ModelLayer/Iface/Param/SDocumentSpec.hpp>

#include <Impl/Qt/Dialogs/CNewDocumentDimensionCalc.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class NewDocumentDialog; }
QT_END_NAMESPACE

namespace SDF::UILayer {
  namespace Impl {
    namespace Qt::Dialogs {
      class CNewDocumentDialog : public QDialog,
      public SDF::ModelLayer::Iface::IDocumentMeasurementsServiceDependency {
        Q_OBJECT
      public:
        CNewDocumentDialog(QWidget *parent = nullptr);
        ~CNewDocumentDialog();

        void injectWith(SDF::ModelLayer::Iface::IDocumentMeasurementsService *measurementsService);

        SDF::ModelLayer::Iface::Param::SDocumentSpec getDocumentSpec() const;
      private slots:
        void widthChanged();
        void heightChanged();
        void widthUnitChanged();
        void heightUnitChanged();
        void resolutionChanged();
        void resolutionUnitChanged();
        void colorModelChanged();
        void bitDepthChanged();
      private:
        Ui::NewDocumentDialog *m_ui;

        CNewDocumentDimensionCalc m_newDocumentDimensionCalc;
        SDF::ModelLayer::Iface::Param::EColorModel m_colorModel;
        SDF::ModelLayer::Iface::Param::EBitDepth m_bitDepth;

        void populateComboBoxWithDimensionUnits(QComboBox *comboBox);
        void populateComboBoxWithResolutionUnits(QComboBox *comboBox);

        void populateComboBoxWithColorModels(QComboBox *comboBox);
        void populateComboBoxWithBitDepths(QComboBox *comboBox);

        void syncToInternalState(bool syncComboBoxes = false);
      };
    }
  }
}

#endif
