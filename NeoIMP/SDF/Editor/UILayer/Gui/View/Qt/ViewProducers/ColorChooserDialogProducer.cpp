/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorChooserDialogProducer.cpp
 * PURPOSE: Implements the ColorChooserDialogProducer class.
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

#include "ColorChooserDialogProducer.hpp"

#include "producer_ids.hpp"
#include "ColorChooserAdvancedDialogProducer.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt::ViewProducers {
  ColorChooserDialogProducer::ColorChooserDialogProducer(
    deps_t a_deps,
    Common::Handle a_id,
    AProducerNode *a_parent
  )
    : AProducerNode(a_id, a_parent),
      m_services(a_deps)
  {
    auto colorChooserAdvancedDialogProducer = new ColorChooserAdvancedDialogProducer(m_services,
      COLOR_CHOOSER_CC_ADVANCED_DIALOG_PRODUCER, this);
  }

  QWidget *
  ColorChooserDialogProducer::getViewWidget() {
    return m_colorChooserDialog;
  }

  void
  ColorChooserDialogProducer::produceView() {
    using namespace Controller::ColorChooserDialog;
    using namespace Views;

    if(!m_colorChooserDialog) {
      m_colorChooserDialog = new ColorChooserDialog(getParent()->getViewWidget());
      m_colorChooserDialog->setAttribute(::Qt::WA_DeleteOnClose);

      auto onAdvancedOptionsRequestController = std::make_unique<OnAdvancedOptionsRequest>(
        m_services, findChildById<ColorChooserAdvancedDialogProducer>(
          COLOR_CHOOSER_CC_ADVANCED_DIALOG_PRODUCER));

      m_colorChooserDialog->hookOnAdvancedOptionsRequest(std::move(
        onAdvancedOptionsRequestController))->connect();

      m_colorChooserDialog->exec();
    }
  }
}
