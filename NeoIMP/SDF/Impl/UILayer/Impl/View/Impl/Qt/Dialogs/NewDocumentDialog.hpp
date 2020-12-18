#ifndef SDF_UILAYER_QT_VIEW_NEWDOCUMENTDIALOG_HPP
#define SDF_UILAYER_QT_VIEW_NEWDOCUMENTDIALOG_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentDialog.hpp
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

#include <SDF/Impl/UILayer/AbstractModel/Properties/ColorModels.hpp>
#include <SDF/Impl/UILayer/AbstractModel/Properties/BitDepths.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class NewDocumentDialog; }
QT_END_NAMESPACE

namespace SDF::Impl::UILayer::Impl::View {
  class INewDocumentParamsReceiver;

  namespace Impl::Qt::Dialogs {
    class NewDocumentDialog : public QDialog {
      Q_OBJECT
    public:
      NewDocumentDialog(QWidget *parent = nullptr);
      ~NewDocumentDialog();

      int getDocumentWidthPx();
      int getDocumentHeightPx();
      float getDocumentResolutionPpi();

      AbstractModel::Properties::ColorModel getDocumentColorModel();
      AbstractModel::Properties::BitDepth getDocumentBitDepth();
    private slots:
    /*
      void widthChanged();
      void heightChanged();
      void widthUnitChanged();
      void heightUnitChanged();
      void resolutionChanged();
      void resolutionUnitChanged();
      void colorModelChanged();
      void bitDepthChanged();
    */
    private:
      Ui::NewDocumentDialog *m_ui;
    };
  }
}

#endif
