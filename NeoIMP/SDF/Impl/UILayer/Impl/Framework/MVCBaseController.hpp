#ifndef SDF_IMPL_UILAYER_IMPL_FRAMEWORK_MVCBASECONTROLLER_HPP
#define SDF_IMPL_UILAYER_IMPL_FRAMEWORK_MVCBASECONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCBaseController.hpp
 * PURPOSE: Provides a base for MVC controllers to define the message receiver add/remove boilerplate.
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

#include <SDF/Impl/UILayer/Impl/Framework/IMVCController.hpp>

#include <string>
#include <vector>

namespace SDF::Impl::UILayer::Impl::Framework {
  class IMVCMessageReceiver;
  class MVCViewUnit;

  class MVCBaseController : public IMVCController {
  public:
    MVCBaseController();

    void addMessageReceiver(IMVCMessageReceiver *receiver);
    void removeMessageReceiver(IMVCMessageReceiver *receiver);

    virtual void receiveMessage(void *sender, std::string message) = 0;

    void setViewUnit(MVCViewUnit *viewUnit);
  protected:
    MVCViewUnit *m_viewUnit;

    void dispatchMessage(std::string message);
  private:
    std::vector<IMVCMessageReceiver *> m_messageReceivers;
  };
}

#endif
