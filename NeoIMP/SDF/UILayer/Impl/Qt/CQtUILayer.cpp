/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CQtUILayer.cpp
 * PURPOSE: Implementation of the Qt-based UI layer class.
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

#include <Impl/Qt/CQtUILayer.hpp>

namespace SDF::UILayer {
  namespace Impl {
    namespace Qt {
      CQtUILayer::CQtUILayer() {

      }

      void CQtUILayer::prepareApplication(int argc, char *argv[]) {
        m_application = std::make_unique<CApplication>(argc, argv);
      }

      int CQtUILayer::runMainLoop() {
        assert(m_application);

        return m_application->start();
      }
    }
  }

  namespace Iface {
    // Singleton access.
    IUILayer *IUILayer::getInstance() {
      static std::unique_ptr<Impl::Qt::CQtUILayer> instance(std::make_unique<Impl::Qt::CQtUILayer>());
      return instance.get();
    }
  }
}
