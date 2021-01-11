#ifndef SDF_IMPL_UILAYER_IMPL_FRAMEWORK_MESSAGING_BOX_HPP
#define SDF_IMPL_UILAYER_IMPL_FRAMEWORK_MESSAGING_BOX_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Box.hpp
 * PURPOSE: Provides a base for a box, which can contain internal emitting components wired to an external emitter.
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

#include <SDF/Impl/UILayer/Impl/Framework/Messaging/Emitter.hpp>
#include <SDF/Impl/UILayer/Impl/Framework/Messaging/IReceiver.hpp>

#include <string>
#include <memory>

namespace SDF::Impl::UILayer::Impl::Framework::Messaging {
  class Box : public Emitter {
  public:
    Box();
    virtual ~Box() = 0;
  protected:
    class InnerReceiver : public IReceiver {
    public:
      InnerReceiver(Box *box);
      void receiveMessage(std::string message);
    private:
      Box *m_box;
    };

    std::unique_ptr<InnerReceiver> m_innerReceiver;
  };
}

#endif
