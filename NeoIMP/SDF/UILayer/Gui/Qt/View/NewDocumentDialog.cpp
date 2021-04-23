/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentDialog.cpp
 * PURPOSE: Defines the NewDocumentDialog class.
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

#include <NewDocumentDialog.hpp>

#include <Events/DialogEvent.hpp>

#include <Strings/UnitNames.hpp>
#include <Strings/UnitSymbols.hpp>
#include <Strings/ColorModels.hpp>
#include <Strings/BitDepths.hpp>

#include <safeConnect.hpp>

#include <DocumentSpec.hpp>

#include "QtResources/ui_NewDocumentDialog.h"

namespace SDF::UILayer::Gui::Qt::View {
  NewDocumentDialog::NewDocumentDialog(std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> controller,
                                       QWidget *parent
                                      )
    : QDialog(parent),
      m_ui(new Ui::NewDocumentDialog),
      m_controller(std::move(controller)),
      m_documentWidthSelector(1280.0f, Metrics::LENGTH_UNIT_PIXEL, 120.0f),
      m_documentHeightSelector(720.0f, Metrics::LENGTH_UNIT_PIXEL, 120.0f),
      m_documentResolutionSelector(120.0f, Metrics::RESOLUTION_UNIT_PPI),
      m_colorModel(AbstractModel::Properties::COLOR_MODEL_RGB),
      m_bitDepth(AbstractModel::Properties::BIT_DEPTH_8)
  {
    m_ui->setupUi(this);

    // Populate the combo boxes.
    for(int i(0); i < Metrics::LENGTH_UNIT_MAX; ++i) {
      m_ui->imageWidthUnitComboBox->addItem(Strings::c_lengthUnitSymbols[i].c_str());
      m_ui->imageHeightUnitComboBox->addItem(Strings::c_lengthUnitSymbols[i].c_str());
    }

    for(int i(0); i < Metrics::RESOLUTION_UNIT_MAX; ++i) {
      m_ui->imageResolutionUnitComboBox->addItem(Strings::c_resolutionUnitSymbols[i].c_str());
    }

    for(int i(0); i < AbstractModel::Properties::COLOR_MODEL_MAX; ++i) {
      m_ui->colorModelComboBox->addItem(Strings::c_colorModelNames[i].c_str());
    }

    for(int i(0); i < AbstractModel::Properties::BIT_DEPTH_MAX; ++i) {
      m_ui->bitsPerChannelComboBox->addItem(Strings::c_bitDepthNames[i].c_str());
    }

    // Set initial field values.
    m_ui->imageWidthEdit->setText(QString::number(m_documentWidthSelector.getQuantity()));
    m_ui->imageWidthUnitComboBox->setCurrentIndex(m_documentWidthSelector.getUnit());
    m_ui->imageHeightEdit->setText(QString::number(m_documentHeightSelector.getQuantity()));
    m_ui->imageHeightUnitComboBox->setCurrentIndex(m_documentHeightSelector.getUnit());
    m_ui->imageResolutionEdit->setText(QString::number(m_documentResolutionSelector.getQuantity()));
    m_ui->imageResolutionUnitComboBox->setCurrentIndex(m_documentResolutionSelector.getUnit());

    // Hook events.
    safeConnect(m_ui->imageWidthEdit, &QLineEdit::textEdited, [=](const QString &str) {
      bool ok(false); float width(str.toFloat(&ok));
      if(ok) { m_documentWidthSelector.setQuantity(width); }
    });
    safeConnect(m_ui->imageHeightEdit, &QLineEdit::textEdited, [=](const QString &str) {
      bool ok(false); float height(str.toFloat(&ok));
      if(ok) { m_documentHeightSelector.setQuantity(height); }
    });
    safeConnect(m_ui->imageResolutionEdit, &QLineEdit::textEdited, [=](const QString &str) {
      bool ok(false); float resolution(str.toFloat(&ok));
      if(ok) {
        m_documentResolutionSelector.setQuantity(resolution);
        m_documentWidthSelector.setResolutionPpi(
          m_documentResolutionSelector.getQuantityIn(Metrics::RESOLUTION_UNIT_PPI)
        );
        m_documentHeightSelector.setResolutionPpi(
          m_documentResolutionSelector.getQuantityIn(Metrics::RESOLUTION_UNIT_PPI)
        );
      }
    });

    safeConnect(m_ui->imageWidthUnitComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
      m_documentWidthSelector.setUnit(static_cast<Metrics::LengthUnit>(index));
      m_ui->imageWidthEdit->setText(QString::number(m_documentWidthSelector.getQuantity()));
    });
    safeConnect(m_ui->imageHeightUnitComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
      m_documentHeightSelector.setUnit(static_cast<Metrics::LengthUnit>(index));
      m_ui->imageHeightEdit->setText(QString::number(m_documentHeightSelector.getQuantity()));
    });
    safeConnect(m_ui->imageResolutionUnitComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
      m_documentResolutionSelector.setUnit(static_cast<Metrics::ResolutionUnit>(index));
      m_ui->imageResolutionEdit->setText(QString::number(m_documentResolutionSelector.getQuantity()));
    });

    safeConnect<QDialog>(this, &QDialog::accepted, [=]() {
      m_controller->handleEvent(std::make_shared<Events::AcceptEvent<DocumentSpec>>(DocumentSpec {
        m_documentWidthSelector.getQuantityIn(Metrics::LENGTH_UNIT_PIXEL),
        m_documentHeightSelector.getQuantityIn(Metrics::LENGTH_UNIT_PIXEL),
        m_documentResolutionSelector.getQuantityIn(Metrics::RESOLUTION_UNIT_PPI),
        m_colorModel,
        m_bitDepth
      }));
    });

    safeConnect<QDialog>(this, &QDialog::rejected, [=]() {
      m_controller->handleEvent(std::make_shared<Events::RejectEvent<DocumentSpec>>());
    });
  }

  NewDocumentDialog::~NewDocumentDialog() {
    delete m_ui;
  }

  IGuiElement *
  NewDocumentDialog::getParent() {
    if(auto p = dynamic_cast<IGuiElement *>(parentWidget())) {
      return p;
    } else {
      return nullptr;
    }
  }

  void
  NewDocumentDialog::show() {
    QDialog::show();
  }

  void
  NewDocumentDialog::close() {
    QDialog::close();
  }
}
