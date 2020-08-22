#ifndef SDF_UILAYER_IMPL_QT_CAPPLICATION_HPP
#define SDF_UILAYER_IMPL_QT_CAPPLICATION_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CApplication.hpp
 * PURPOSE: The Qt-based application implementation.
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

#include <Impl/Qt/Windows/CMainWindow.hpp>
#include <QApplication>
#include <memory>

namespace SDF::UILayer {
  namespace Impl {
    namespace Qt {
      class CApplication {
      public:
        CApplication(int argc, char *argv[]);
        CApplication(const CApplication &) = delete;
        CApplication(CApplication &&) = delete;
        ~CApplication();

        CApplication &operator=(const CApplication &) = delete;
        CApplication &operator=(CApplication &&) = delete;

        int start();
      private:
        // ugly, but to appease QT ...
        int m_argc;
        char **m_argv;

        std::unique_ptr<QApplication> m_q; // need to take care of the lifetime of this ...
        std::unique_ptr<Windows::CMainWindow> m_mainWindow; // here, too!

        bool m_isStarted;
      };
    }
  }
}

#endif
