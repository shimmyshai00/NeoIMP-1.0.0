/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CApplication.cpp
 * PURPOSE: Implementation of the CApplication class.
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

#include <Impl/Qt/CApplication.hpp>

#include <Impl/Qt/Windows/CMainWindow.hpp>
#include <SDF/ModelLayer/include/IModelLayer.hpp>

#include <Impl/Qt/Error/CErrorReporter.hpp>

namespace SDF {
  namespace UILayer {
    namespace Impl::Qt {
      CApplication::CApplication(int argc, char *argv[])
      : m_argc(argc),
        m_argv(argv),
        m_errorReporter(std::make_unique<Error::CErrorReporter>()),
        m_q(std::make_unique<QApplication>(m_argc, m_argv)),
        m_mainWindow(std::make_unique<Windows::CMainWindow>(nullptr, m_errorReporter.get())),
        m_isStarted(false)
        {
          SDF::ModelLayer::IModelLayer::getInstance()->injectDocumentModel(*m_mainWindow);
        }

      CApplication::~CApplication() {
        assert(m_mainWindow);
        assert(m_q);

        m_mainWindow.release();
        m_q.release(); // must be destroyed BEFORE m_argc and m_argv
      }

      int CApplication::start() {
        assert(m_mainWindow);
        assert(m_q);

        if(!m_isStarted) {
          m_isStarted = true;
          m_mainWindow->show();
          return m_q->exec();
        } else {
          return -1;
        }
      }
    }
  }
}
