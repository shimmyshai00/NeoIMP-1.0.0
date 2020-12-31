/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewManager.cpp
 * PURPOSE: The Qt-based view manager implementation.
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

#include <ViewManager.hpp>

#include <UILayer/Exceptions/Exceptions.hpp>

#include <AbstractModel/Services/IImageInformationService.hpp>
#include <AbstractModel/Services/IImageRenderingService.hpp>
#include <AbstractModel/Handle.hpp>

#include <IApplicationView.hpp>

#include <ApplicationView.hpp>


namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  ViewManager::ViewManager(
    AbstractModel::Services::IImageInformationService *imageInformationService,
    AbstractModel::Services::IImageRenderingService *imageRenderingService
  )
    : m_imageInformationService(imageInformationService),
      m_imageRenderingService(imageRenderingService)
  {}

  ViewManager::~ViewManager() {}

  void ViewManager::showApplicationView() {
    if(!m_applicationView) {
      m_applicationView = std::make_unique<ApplicationView>();
    }
  }

  IApplicationView *ViewManager::getApplicationView() {
    return m_applicationView.get();
  }
}
