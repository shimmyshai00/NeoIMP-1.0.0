/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewFactory.cpp
 * PURPOSE: The Qt-based view factory implementation.
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

#include <ViewFactory.hpp>

#include <AbstractModel/Services/IImageInformationService.hpp>
#include <AbstractModel/Services/IImageRenderingService.hpp>

#include <IApplicationViewComposite.hpp>
#include <INewDocumentView.hpp>

#include <ApplicationViewComposite.hpp>
#include <NewDocumentView.hpp>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  ViewFactory::ViewFactory(
    AbstractModel::Services::IImageInformationService *imageInformationService,
    AbstractModel::Services::IImageRenderingService *imageRenderingService
  )
    : m_imageInformationService(imageInformationService),
      m_imageRenderingService(imageRenderingService)
  {}

  std::unique_ptr<IApplicationViewComposite> ViewFactory::createApplicationViewComposite() {
    return std::make_unique<ApplicationViewComposite>(m_imageInformationService, m_imageRenderingService);
  }

  std::unique_ptr<INewDocumentView> ViewFactory::createNewDocumentView() {
    return std::make_unique<NewDocumentView>();
  }
}
