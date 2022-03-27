/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentDialog.cpp
 * PURPOSE: Implements the NewDocumentDialog class.
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

#include "NewDocumentDialog.hpp"

#include "Resources/ui_NewDocumentDialog.h"

#include "../../../AbstractModel/Defs/Bounds.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt::Impl {
  static const std::string g_bkgPresetNames[AbstractModel::Defs::PRE_BACKGROUND_MAX] = {
    "White",
    "Black",
    "Transparent",
    "Custom"
  };
}

namespace SDF::Editor::UILayer::Gui::View::Qt::Impl {
  static const std::string g_colorModelNames[AbstractModel::Defs::Color::CM_FAMILY_MAX] = {
    "RGB"
  };

  static const std::string
    g_rgbFamilyNames[AbstractModel::Defs::Color::NUM_RGB_FORMATS] = {
      "8 bpc"
    };
}

namespace SDF::Editor::UILayer::Gui::View::Qt {
  NewDocumentDialog::NewDocumentDialog(
    AbstractModel::Metrics::IConvertLengthService *convertLengthService,
    AbstractModel::Metrics::IConvertResolutionService *convertResolutionService,
    AbstractModel::Create::IGetDocumentPrefabService *getDocumentPrefabService,
    AbstractModel::Create::IGetMemoryRequirementsService *getMemoryRequirementsService,
    QWidget *parent
  )
    : QDialog(parent),
      m_ui(new Ui::NewDocumentDialog),
      m_convertLengthService(convertLengthService),
      m_convertResolutionService(convertResolutionService),
      m_getDocumentPrefabService(getDocumentPrefabService),
      m_getMemoryRequirementsService(getMemoryRequirementsService)
  {
    using namespace AbstractModel;
    using namespace CustomWidgets;

    m_ui->setupUi(this);

    // Inject service into widgets.
    m_ui->widthSelector->setConversionServices(m_convertLengthService, m_convertResolutionService);
    m_ui->heightSelector->setConversionServices(m_convertLengthService, m_convertResolutionService);
    m_ui->resolutionSelector->setConversionService(m_convertResolutionService);

    // Set constraints
    m_ui->widthSelector->setMinLimit(1.0f, Defs::LENGTH_UNIT_PIXEL);
    m_ui->widthSelector->setMaxLimit(Defs::Bounds::MAX_IMAGE_WIDTH, Defs::LENGTH_UNIT_PIXEL);

    m_ui->heightSelector->setMinLimit(1.0f, Defs::LENGTH_UNIT_PIXEL);
    m_ui->heightSelector->setMaxLimit(Defs::Bounds::MAX_IMAGE_HEIGHT, Defs::LENGTH_UNIT_PIXEL);

    m_ui->resolutionSelector->setMinLimit(1.0f, Defs::RESOLUTION_UNIT_PPI);
    m_ui->resolutionSelector->setMaxLimit(1000.0f, Defs::RESOLUTION_UNIT_PPI);

    // Connect resolution widget to width/height widgets.
    connect(m_ui->resolutionSelector, &ResolutionQuantityEdit::quantityChanged,
      m_ui->widthSelector, &LengthQuantityEdit::setReferenceResolution);
    connect(m_ui->resolutionSelector,
      QOverload<Defs::EResolutionUnit>::of(&ResolutionQuantityEdit::unitChanged),
      m_ui->widthSelector, &LengthQuantityEdit::setReferenceResolutionUnit);

    connect(m_ui->resolutionSelector, &ResolutionQuantityEdit::quantityChanged,
      m_ui->heightSelector, &LengthQuantityEdit::setReferenceResolution);
    connect(m_ui->resolutionSelector,
      QOverload<Defs::EResolutionUnit>::of(&ResolutionQuantityEdit::unitChanged),
      m_ui->heightSelector, &LengthQuantityEdit::setReferenceResolutionUnit);

    // Populate dropdown boxes.
    for(std::size_t i(0); i < AbstractModel::Defs::Color::COLOR_MODEL_MAX; ++i) {
      m_ui->colorModelSelector->addItem(QString::fromStdString(
        View::Qt::Impl::g_colorModelNames[i]));
    }

    // NB: STUB for this newfangled flexibility
    for(std::size_t i(0); i < AbstractModel::Defs::Color::NUM_RGB_FORMATS; ++i) {
      m_ui->bitDepthSelector->addItem(QString::fromStdString(View::Qt::Impl::g_rgbFamilyNames[i]));
    }

    for(std::size_t i(0); i < AbstractModel::Defs::PRE_BACKGROUND_MAX; ++i) {
      m_ui->initialBackgroundSelector->addItem(QString::fromStdString(
        View::Qt::Impl::g_bkgPresetNames[i]));
    }

    // Color model selection.
    auto showSubFormats = [&](int familyIndex) {
      if(familyIndex == Defs::Color::CM_FAMILY_RGB) {
        m_ui->bitDepthSelector->clear();
        for(std::size_t i(0); i < AbstractModel::Defs::Color::NUM_RGB_FORMATS; ++i) {
          m_ui->bitDepthSelector->addItem(QString::fromStdString(
            View::Qt::Impl::g_rgbFamilyNames[i]));
        }
      }
    };

    connect(m_ui->colorModelSelector, QOverload<int>::of(&QComboBox::activated), showSubFormats);

    // Preset selection.
    std::vector<Common::Handle> prefabHandles(m_getDocumentPrefabService->getAvailablePrefabs());
    for(const auto &h : prefabHandles) {
      // NB: unsafe cast? e.g. if def'n of SDF::Common::Handle changes
      m_ui->presetSelector->addItem(
        QString::fromStdString(m_getDocumentPrefabService->getPrefabName(h)), (unsigned int)h);
    }

    // NB: definitely unsafe
    m_ui->presetSelector->addItem("Custom", (unsigned int)Common::HANDLE_INVALID);

    // Output synthesis.
    auto createSpec = [&]() {
      Defs::ImageSpec spec;
      spec.width = m_ui->widthSelector->quantity();
      spec.widthUnit = m_ui->widthSelector->unit();
      spec.height = m_ui->heightSelector->quantity();
      spec.heightUnit = m_ui->heightSelector->unit();
      spec.resolution = m_ui->resolutionSelector->quantity();
      spec.resolutionUnit = m_ui->resolutionSelector->unit();
      spec.colorModel = static_cast<Defs::Color::EColorModel>(
        m_ui->colorModelSelector->currentIndex()); // NB: BAD STUB
      spec.backgroundPreset =
        static_cast<Defs::EBackgroundPreset>(m_ui->initialBackgroundSelector->currentIndex());
      spec.backgroundColor = std::make_shared<Defs::Color::RGB24_888>(255, 255, 255);

      return spec;
    };

    // Size calculator.
    auto recalculateSize = [&, createSpec]() {
      std::size_t memReq = m_getMemoryRequirementsService->getMemoryRequiredForOneLayer(
        createSpec());
      double memReqMiB = (0.0 + memReq) / 1048576.0;

      m_ui->memoryReqIndicator->setText(
        QString::number(memReqMiB, 'f', 2) + QString(" ") + QString("MiB"));
    };

    connect(m_ui->widthSelector, &LengthQuantityEdit::quantityChanged, recalculateSize);
    connect(m_ui->heightSelector, &LengthQuantityEdit::quantityChanged, recalculateSize);
    connect(m_ui->resolutionSelector, &ResolutionQuantityEdit::quantityChanged, recalculateSize);

    // Preset selection responder.
    auto presetSelHandler = [&, recalculateSize](int index) {
      Common::Handle handle(m_ui->presetSelector->itemData(index).toUInt());
      if(handle != Common::HANDLE_INVALID) { // checks for the custom spot, i.e. no prefab
        AbstractModel::Defs::ImageSpec presetSpec(m_getDocumentPrefabService->getPrefabSpec(
          handle));

        m_ui->widthSelector->setReferenceResolutionUnit(presetSpec.resolutionUnit);
        m_ui->widthSelector->setReferenceResolution(presetSpec.resolution);
        m_ui->heightSelector->setReferenceResolutionUnit(presetSpec.resolutionUnit);
        m_ui->heightSelector->setReferenceResolution(presetSpec.resolution);

        m_ui->widthSelector->setUnit(presetSpec.widthUnit);
        m_ui->widthSelector->setQuantity(presetSpec.width);
        m_ui->heightSelector->setUnit(presetSpec.heightUnit);
        m_ui->heightSelector->setQuantity(presetSpec.height);
        m_ui->resolutionSelector->setUnit(presetSpec.resolutionUnit);
        m_ui->resolutionSelector->setQuantity(presetSpec.resolution);
        m_ui->colorModelSelector->setCurrentIndex(presetSpec.colorModel); // NB: BAD STUB
        m_ui->initialBackgroundSelector->setCurrentIndex(presetSpec.backgroundPreset);

        recalculateSize();
      }
    };

    connect(m_ui->presetSelector, QOverload<int>::of(&QComboBox::activated), presetSelHandler);

    // Preset deselectors.
    auto toCustom = [&]() {
      m_ui->presetSelector->setCurrentIndex(m_ui->presetSelector->count()-1);
    };

    connect(m_ui->widthSelector, &LengthQuantityEdit::quantityChangedByUser, toCustom);
    connect(m_ui->heightSelector, &LengthQuantityEdit::quantityChangedByUser, toCustom);
    connect(m_ui->resolutionSelector, &ResolutionQuantityEdit::quantityChangedByUser, toCustom);
    connect(m_ui->colorModelSelector, QOverload<int>::of(&QComboBox::activated), toCustom);
    connect(m_ui->bitDepthSelector, QOverload<int>::of(&QComboBox::activated), toCustom);

    // Output command
    connect(this, &NewDocumentDialog::accepted, [&, createSpec]() {
      m_onAcceptEvent.trigger(createSpec());
    });

    connect(this, &NewDocumentDialog::rejected, [&]() { m_onRejectEvent.trigger(); });

    // Set default values.
    m_ui->presetSelector->setCurrentIndex(0);
    presetSelHandler(0);
  }

  NewDocumentDialog::~NewDocumentDialog() {
    delete m_ui;
  }

  Common::PIConnection
  NewDocumentDialog::hookOnAccept(
    std::unique_ptr<IController<AbstractModel::Defs::ImageSpec>> controller
  ) {
    return m_onAcceptEvent.hook(std::move(controller));
  }

  Common::PIConnection
  NewDocumentDialog::hookOnReject(std::unique_ptr<IController<>> controller) {
    return m_onRejectEvent.hook(std::move(controller));
  }
}
