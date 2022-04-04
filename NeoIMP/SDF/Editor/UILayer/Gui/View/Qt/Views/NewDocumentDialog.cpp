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

#include "../../../../AbstractModel/Defs/bounds.hpp"

#include "../Resources/ui_NewDocumentDialog.h"

namespace SDF::Editor::UILayer::Gui::View::Qt::Impl {
  static const std::string g_bkgPresetNames[AbstractModel::Defs::PRE_BACKGROUND_MAX] = {
    "White",
    "Black",
    "Transparent",
    "Custom"
  };
}

namespace SDF::Editor::UILayer::Gui::View::Qt::Impl {
  static const std::string g_colorModelNames[AbstractModel::Defs::Color::COLOR_MODEL_MAX] = {
    "RGB"
  };

  static const std::string
    g_rgbFamilyNames[AbstractModel::Defs::Color::NUM_RGB_FORMATS] = {
      "8 bpc"
    };
}

namespace SDF::Editor::UILayer::Gui::View::Qt::Views {
  NewDocumentDialog::NewDocumentDialog(deps_t deps, QWidget *parent)
    : QDialog(parent),
      m_ui(new Ui::NewDocumentDialog),
      m_colorPickerLabel(nullptr),
      m_backgroundSwatch(nullptr),
      m_services(deps)
  {
    using namespace AbstractModel::Defs::Bounds;
    using namespace AbstractModel::Defs::Color;
    using namespace AbstractModel::Defs;
    using namespace AbstractModel::Color;
    using namespace AbstractModel;
    using namespace CustomWidgets;

    m_ui->setupUi(this);

    // Inject service into widgets.
    m_ui->widthSelector->setConversionServices(m_services.get<Metrics::IConvertLengthService>(),
      m_services.get<Metrics::IConvertResolutionService>());
    m_ui->heightSelector->setConversionServices(m_services.get<Metrics::IConvertLengthService>(),
      m_services.get<Metrics::IConvertResolutionService>());
    m_ui->resolutionSelector->setConversionService(
      m_services.get<Metrics::IConvertResolutionService>());

    // Set constraints
    m_ui->widthSelector->setMinLimit(1.0f, LENGTH_UNIT_PIXEL);
    m_ui->widthSelector->setMaxLimit(MAX_IMAGE_WIDTH, LENGTH_UNIT_PIXEL);

    m_ui->heightSelector->setMinLimit(1.0f, LENGTH_UNIT_PIXEL);
    m_ui->heightSelector->setMaxLimit(MAX_IMAGE_HEIGHT, LENGTH_UNIT_PIXEL);

    m_ui->resolutionSelector->setMinLimit(1.0f, RESOLUTION_UNIT_PPI);
    m_ui->resolutionSelector->setMaxLimit(1000.0f, RESOLUTION_UNIT_PPI);

    // Connect resolution widget to width/height widgets.
    connect(m_ui->resolutionSelector, &ResolutionQuantityEdit::quantityChanged,
      m_ui->widthSelector, &LengthQuantityEdit::setReferenceResolution);
    connect(m_ui->resolutionSelector,
      QOverload<Defs::ResolutionUnit>::of(&ResolutionQuantityEdit::unitChanged),
      m_ui->widthSelector, &LengthQuantityEdit::setReferenceResolutionUnit);

    connect(m_ui->resolutionSelector, &ResolutionQuantityEdit::quantityChanged,
      m_ui->heightSelector, &LengthQuantityEdit::setReferenceResolution);
    connect(m_ui->resolutionSelector,
      QOverload<Defs::ResolutionUnit>::of(&ResolutionQuantityEdit::unitChanged),
      m_ui->heightSelector, &LengthQuantityEdit::setReferenceResolutionUnit);

    // Populate dropdown boxes.
    for(std::size_t i(0); i < COLOR_MODEL_MAX; ++i) {
      m_ui->colorModelSelector->addItem(QString::fromStdString(
        View::Qt::Impl::g_colorModelNames[i]));
    }

    for(std::size_t i(0); i < NUM_RGB_FORMATS; ++i) {
      m_ui->bitDepthSelector->addItem(QString::fromStdString(View::Qt::Impl::g_rgbFamilyNames[i]));
    }

    for(std::size_t i(0); i < PRE_BACKGROUND_MAX; ++i) {
      m_ui->initialBackgroundSelector->addItem(QString::fromStdString(
        View::Qt::Impl::g_bkgPresetNames[i]));
    }

    // Preset selection.
    std::vector<Common::Handle> prefabHandles(m_services.get<Create::IGetDocumentPrefabService>()->
      getAvailablePrefabs());
    for(const auto &h : prefabHandles) {
      // NB: unsafe cast? e.g. if def'n of SDF::Common::Handle changes
      m_ui->presetSelector->addItem(
        QString::fromStdString(m_services.get<Create::IGetDocumentPrefabService>()->getPrefabName(
          h)), (unsigned int)h);
    }

    // NB: definitely unsafe
    m_ui->presetSelector->addItem("Custom", (unsigned int)Common::HANDLE_INVALID);

    // Connect widgets to either view adjustment or else to controllers.
    connect(m_ui->widthSelector, &LengthQuantityEdit::quantityChangedByUser, [&](float quantity) {
      m_protoSpec.width = quantity;

      onDeviatedFromPreset();
      calculateSizeRequired();
    });
    connect(m_ui->widthSelector, QOverload<LengthUnit>::of(&LengthQuantityEdit::unitChangedByUser),
    [&](LengthUnit unit) {
      m_protoSpec.width = m_ui->widthSelector->quantity();
      m_protoSpec.widthUnit = unit;

      onDeviatedFromPreset();
      calculateSizeRequired();
    });
    connect(m_ui->heightSelector, &LengthQuantityEdit::quantityChangedByUser, [&](float quantity) {
      m_protoSpec.height = quantity;

      onDeviatedFromPreset();
      calculateSizeRequired();
    });
    connect(m_ui->heightSelector, QOverload<LengthUnit>::of(&LengthQuantityEdit::unitChangedByUser),
    [&](LengthUnit unit) {
      m_protoSpec.height = m_ui->heightSelector->quantity();
      m_protoSpec.heightUnit = unit;

      onDeviatedFromPreset();
      calculateSizeRequired();
    });
    connect(m_ui->resolutionSelector, &ResolutionQuantityEdit::quantityChangedByUser,
    [&](float quantity) {
      m_protoSpec.resolution = quantity;

      onDeviatedFromPreset();
      calculateSizeRequired();
    });
    connect(m_ui->resolutionSelector,
      QOverload<ResolutionUnit>::of(&ResolutionQuantityEdit::unitChangedByUser),
      [&](ResolutionUnit unit) {
        m_protoSpec.resolution = m_ui->resolutionSelector->quantity();
        m_protoSpec.resolutionUnit = unit;

        onDeviatedFromPreset();
        calculateSizeRequired();
      });

    connect(m_ui->colorModelSelector, QOverload<int>::of(&QComboBox::activated), this,
      &NewDocumentDialog::setColorSubFormatsShown);
    connect(m_ui->bitDepthSelector, QOverload<int>::of(&QComboBox::activated), this,
      &NewDocumentDialog::getColorFormatFromBoxes);
    connect(m_ui->initialBackgroundSelector, QOverload<int>::of(&QComboBox::activated),
      [&](int index) {
        m_protoSpec.backgroundPreset = static_cast<BackgroundPreset>(index);
        if(index == PRE_BACKGROUND_CUSTOM) {
          showColorSelector();
        } else {
          hideColorSelector();
        }
      }
    );
    connect(m_ui->presetSelector, QOverload<int>::of(&QComboBox::activated), this,
      &NewDocumentDialog::adjustSettingsToPreset);

    connect(m_ui->colorModelSelector, QOverload<int>::of(&QComboBox::activated), this,
      &NewDocumentDialog::onDeviatedFromPreset);
    connect(m_ui->bitDepthSelector, QOverload<int>::of(&QComboBox::activated), this,
      &NewDocumentDialog::onDeviatedFromPreset);
    connect(m_ui->initialBackgroundSelector, QOverload<int>::of(&QComboBox::activated), this,
      &NewDocumentDialog::onDeviatedFromPreset);

    connect(this, &NewDocumentDialog::accepted, [&]() { m_onAcceptEvent.trigger(m_protoSpec); });
    connect(this, &NewDocumentDialog::rejected, [&]() { m_onRejectEvent.trigger(); });

    // Set default values.
    m_ui->presetSelector->setCurrentIndex(0);
    m_ui->presetSelector->activated(0);
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

namespace SDF::Editor::UILayer::Gui::View::Qt::Views {
  int
  NewDocumentDialog::colorIndexIn(
    const AbstractModel::Defs::Color::ColorFormat *a_formats,
    int a_numFormats,
    AbstractModel::Defs::Color::ColorFormat a_format
  ) {
    for(int i(0); i < a_numFormats; ++i) {
      if(a_formats[i] == a_format) {
        return i;
      }
    }

    return a_numFormats;
  }

  void
  NewDocumentDialog::setBoxesFromColorFormat(AbstractModel::Defs::Color::ColorFormat colorFormat) {
    using namespace AbstractModel::Defs::Color;

    if(colorFormat == COLOR_FMT_RGB24_888) { // TBA: || (... == COLOR_FMT_RGB36_121212), etc.
      m_ui->bitDepthSelector->setCurrentIndex(colorIndexIn(g_colorFormatsByModel_Rgb,
        NUM_RGB_FORMATS, colorFormat));
    }
  }
}

namespace SDF::Editor::UILayer::Gui::View::Qt::Views {
  void
  NewDocumentDialog::setColorSubFormatsShown(int familyIndex) {
    using namespace AbstractModel::Defs::Color;
    using namespace Impl;

    if(familyIndex == COLOR_MODEL_RGB) {
      m_ui->bitDepthSelector->clear();
      for(std::size_t i(0); i < NUM_RGB_FORMATS; ++i) {
        m_ui->bitDepthSelector->addItem(QString::fromStdString(g_rgbFamilyNames[i]));
      }
    }
  }

  void
  NewDocumentDialog::getColorFormatFromBoxes() {
    using namespace AbstractModel::Defs::Color;

    int familyIndex = m_ui->colorModelSelector->currentIndex();
    int subFamilyIndex = m_ui->bitDepthSelector->currentIndex();

    if(familyIndex == COLOR_MODEL_RGB) {
      m_protoSpec.colorFormat = g_colorFormatsByModel_Rgb[subFamilyIndex];
    }
  }

  void
  NewDocumentDialog::calculateSizeRequired() {
    using namespace AbstractModel::Create;

    std::size_t memReq = m_services.get<IGetMemoryRequirementsService>()->
      getMemoryRequiredForOneLayer(m_protoSpec);
    double memReqMiB = (0.0 + memReq) / 1048576.0;

    m_ui->memoryReqIndicator->setText(
      QString::number(memReqMiB, 'f', 2) + QString(" ") + QString("MiB"));
  }

  void
  NewDocumentDialog::showColorSelector() {
    using namespace AbstractModel::Color;
    using namespace CustomWidgets;

    m_colorPickerLabel = new QLabel("Color:");
    m_colorPickerLabel->setAlignment(::Qt::AlignCenter);

    m_ui->horizontalLayout_4->insertWidget(1, m_colorPickerLabel);

    m_backgroundSwatch = new Color::ColorSwatch(m_services.get<IUiColorConversionService>());
    m_ui->horizontalLayout_4->insertWidget(2, m_backgroundSwatch);
  }

  void
  NewDocumentDialog::hideColorSelector() {
    if(m_backgroundSwatch != nullptr) {
      m_ui->horizontalLayout_4->removeWidget(m_backgroundSwatch);
      m_ui->horizontalLayout_4->removeWidget(m_colorPickerLabel);

      delete m_backgroundSwatch;
      delete m_colorPickerLabel;

      m_backgroundSwatch = nullptr;
      m_colorPickerLabel = nullptr;
    }
  }

  void
  NewDocumentDialog::onDeviatedFromPreset() {
    // Select "custom" in the preset box.
    m_ui->presetSelector->setCurrentIndex(m_ui->presetSelector->count()-1);
  }

  void
  NewDocumentDialog::adjustSettingsToPreset(int which) {
    using namespace AbstractModel::Create;
    using namespace Common;

    Handle handle(m_ui->presetSelector->itemData(which).toUInt());
    if(handle != HANDLE_INVALID) { // checks for the custom spot, i.e. no prefab
      m_protoSpec = m_services.get<IGetDocumentPrefabService>()->getPrefabSpec(handle);

      m_ui->widthSelector->setReferenceResolutionUnit(m_protoSpec.resolutionUnit);
      m_ui->widthSelector->setReferenceResolution(m_protoSpec.resolution);
      m_ui->heightSelector->setReferenceResolutionUnit(m_protoSpec.resolutionUnit);
      m_ui->heightSelector->setReferenceResolution(m_protoSpec.resolution);

      m_ui->widthSelector->setUnit(m_protoSpec.widthUnit);
      m_ui->widthSelector->setQuantity(m_protoSpec.width);
      m_ui->heightSelector->setUnit(m_protoSpec.heightUnit);
      m_ui->heightSelector->setQuantity(m_protoSpec.height);
      m_ui->resolutionSelector->setUnit(m_protoSpec.resolutionUnit);
      m_ui->resolutionSelector->setQuantity(m_protoSpec.resolution);
      setBoxesFromColorFormat(m_protoSpec.colorFormat);
      m_ui->initialBackgroundSelector->setCurrentIndex(m_protoSpec.backgroundPreset);

      calculateSizeRequired();
    }
  }
}
