#ifndef SDF_IMPL_UILAYER_IMPL_FRAMEWORK_MVCVIEWUNIT_HPP
#define SDF_IMPL_UILAYER_IMPL_FRAMEWORK_MVCVIEWUNIT_HPP

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

#include <SDF/Impl/UILayer/Impl/Framework/IMVCMessageEmitter.hpp>
#include <SDF/Impl/UILayer/Impl/Framework/IMVCMessageReceiver.hpp>

#include <vector>
#include <memory>

namespace SDF::Impl::UILayer::Impl::Framework {
  class IMVCView;
  class IMVCController;

  class MVCMessageDispatcher;

  class MVCViewUnit : public IMVCMessageEmitter, public IMVCMessageReceiver {
  public:
    ~MVCViewUnit();

    void activateView();
    void shutdownView();

    void addMessageReceiver(IMVCMessageReceiver *receiver);
    void removeMessageReceiver(IMVCMessageReceiver *receiver);

    void receiveMessage(void *sender, std::string message);
  private:
    std::unique_ptr<IMVCView> m_view;
    std::vector<std::unique_ptr<IMVCController>> m_controllers;

    std::unique_ptr<MVCMessageDispatcher> m_outgoingMessageDispatcher;
    std::unique_ptr<MVCMessageDispatcher> m_internalMessageDispatcher;
    std::unique_ptr<MVCMessageDispatcher> m_incomingMessageDispatcher;

    MVCViewUnit(std::unique_ptr<IMVCView> view);
  public:
    class Builder {
    public:
      Builder(std::unique_ptr<IMVCView> view);
      ~Builder();

      Builder &addController(std::unique_ptr<IMVCController> controller);
      std::unique_ptr<MVCViewUnit> build();
    private:
      std::unique_ptr<MVCViewUnit> m_viewUnit;
    };
  };
}

#endif
