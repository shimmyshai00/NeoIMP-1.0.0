#ifndef SDF_UILAYER_BASEHOOK_HPP
#define SDF_UILAYER_BASEHOOK_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    BaseHook.hpp
 * PURPOSE: Defines the BaseHook template.
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

#include "../Patterns/IMvcController.hpp"
#include "../Patterns/IConnection.hpp"

#include <list>

namespace SDF::UILayer {
  namespace Impl {
    template<class ... Args>
    class BaseHookConnection;
  }

  // Class:      BaseHook
  // Purpose:    Provides a base MVC controller hook that can be triggered on
  //             its own. Used for providing cross-widget system functionality
  //             (e.g. show, hide, destroy).
  // Parameters: Args - The hook arguments. No conversion is required because no
  //                    widget system must be mated.
  template<class ... Args>
  class BaseHook {
  public:
    BaseHook();

    // Function:   hook
    // Purpose:    Adds a controller to the hook.
    // Parameters: controller - The controller to add.
    // Returns:    A connection object for the added controller.
    Patterns::PIConnection
    hook(std::unique_ptr<Patterns::IMvcController<Args...>> controller);

    // Function:   trigger
    // Purpose:    Trigger an event.
    // Parameters: args - The trigger arguments.
    // Returns:    None.
    void
    trigger(Args... args);
  private:
    friend class Impl::BaseHookConnection<Args...>;

    std::list<std::unique_ptr<Patterns::IMvcController<Args...>>>
      m_controllers;
  };
}

#include "BaseHook.tpp"

#endif
