#ifndef SDF_COMMON_FUNCTIONLISTENER_HPP
#define SDF_COMMON_FUNCTIONLISTENER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FunctionListener.hpp
 * PURPOSE: Defines the FunctionListener template.
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

#include "IListener.hpp"

#include <functional>

namespace SDF::Common {
  // Class:      FunctionListener
  // Purpose:    Adapt a function to a listener object.
  // Parameters: args - The listener arguments.
  template<class ... Args>
  class FunctionListener : public IListener<Args...> {
  public:
    // Function:   FunctionListener
    // Purpose:    Construct the listener with a given function.
    // Parameters: func - The function to wrap.
    FunctionListener(std::function<void (Args...)> func);

    void
    notify(Args... args);
  private:
    std::function<void (Args...)> m_func;
  };
}

#include "FunctionListener.tpp"

#endif
