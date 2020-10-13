#ifndef SDF_LAYERS_UILAYER_QT_VIEW_CNEWDOCUMENTDIALOG_HPP
#define SDF_LAYERS_UILAYER_QT_VIEW_CNEWDOCUMENTDIALOG_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CNewDocumentDialog.hpp
 * PURPOSE: Definition of the dialog class for creating a new document.
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
#include <Metrics/CImageDimension.hpp>
#include <Color/EColorModel.hpp>
#include <Color/EBitDepth.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class NewDocumentDialog; }
QT_END_NAMESPACE

namespace SDF::Layers::UILayer::Qt::View {
  class CNewDocumentDialog : public QDialog {
    Q_OBJECT
  public:
    CNewDocumentDialog(QWidget *parent = nullptr, INewDocumentController *controller = nullptr);
    ~CNewDocumentDialog();
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
    INewDocumentController *m_controller;

    Metrics::CImageDimension m_widthDimension;
    Metrics::CImageDimension m_heightDimension;

    Color::EColorModel m_colorModel;
    Color::EBitDepth m_bitDepth;

    void populateOptions();
  };
}

#endif
