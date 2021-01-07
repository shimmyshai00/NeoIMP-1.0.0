#ifndef SDF_IMPL_UILAYER_IMPL_FRAMEWORK_MVCOBJECT_HPP
#define SDF_IMPL_UILAYER_IMPL_FRAMEWORK_MVCOBJECT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCObject.hpp
 * PURPOSE: Provides a dynamic, hierarchical container base for ownership of MVC views and controllers.
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

#include <memory>

namespace SDF::Impl::UILayer::Impl::Framework {
  class MVCObject {
  public:
    MVCObject();
    virtual ~MVCObject() = 0;

    // Hierarchy methods.
    MVCObject *getParent();
    MVCObject *getFirstChild();
    MVCObject *getNextSibling();

    void addChild(std::unique_ptr<MVCObject> child);
    std::unique_ptr<MVCObject> unlink();
  private:
    MVCObject *m_parent;
    std::unique_ptr<MVCObject> m_firstChild;
    std::unique_ptr<MVCObject> m_nextSibling;
  };
}

#endif
