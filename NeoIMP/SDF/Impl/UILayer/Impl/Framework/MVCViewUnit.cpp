/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCViewUnit.hpp
 * PURPOSE: Provides a way to bundle a view together with its associated controllers under a uniform interface to help
 *          facilitate dynamic creation and destruction thereof.
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

#include <MVCViewUnit.hpp>

#include <IMVCView.hpp>
#include <IMVCController.hpp>

#include <MVCMessageDispatcher.hpp>

#include <UILayer/Exceptions/Exceptions.hpp>

namespace SDF::Impl::UILayer::Impl::Framework {
  MVCViewUnit::MVCViewUnit(std::unique_ptr<IMVCView> view)
    : m_view(std::move(view)),
      m_outgoingMessageDispatcher(new MVCMessageDispatcher),
      m_incomingMessageDispatcher(new MVCMessageDispatcher)
  {}

  MVCViewUnit::~MVCViewUnit() {}

  void MVCViewUnit::activateView() {
    m_view->activate();
  }

  void MVCViewUnit::shutdownView() {
    m_view->shutdown();
  }

  void MVCViewUnit::addMessageReceiver(IMVCMessageReceiver *receiver) {
    m_outgoingMessageDispatcher->addMessageReceiver(receiver);
  }

  void MVCViewUnit::removeMessageReceiver(IMVCMessageReceiver *receiver) {
    m_outgoingMessageDispatcher->removeMessageReceiver(receiver);
  }

  void MVCViewUnit::receiveMessage(void *sender, std::string message) {
    m_incomingMessageDispatcher->receiveMessage(sender, message);
  }
}

namespace SDF::Impl::UILayer::Impl::Framework {
  MVCViewUnit::Builder::Builder(std::unique_ptr<IMVCView> view) : m_viewUnit(new MVCViewUnit(std::move(view))) {}
  MVCViewUnit::Builder::~Builder() {}

  MVCViewUnit::Builder &MVCViewUnit::Builder::addController(std::unique_ptr<IMVCController> controller) {
    controller->addMessageReceiver(m_viewUnit->m_outgoingMessageDispatcher.get());
    m_viewUnit->m_incomingMessageDispatcher->addMessageReceiver(controller.get());

    m_viewUnit->m_controllers.push_back(std::move(controller));

    return *this;
  }

  std::unique_ptr<MVCViewUnit> MVCViewUnit::Builder::build() {
    return std::move(m_viewUnit);
  }
}
