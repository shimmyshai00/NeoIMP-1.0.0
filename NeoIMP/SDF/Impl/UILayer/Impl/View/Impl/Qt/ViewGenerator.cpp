/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewGenerator.cpp
 * PURPOSE: The Qt-based view generator implementation.
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

#include <ViewGenerator.hpp>

#include <UILayer/Exceptions/Exceptions.hpp>

#include <AbstractModel/Services/IImageInformationService.hpp>
#include <AbstractModel/Services/IImageRenderingService.hpp>
#include <AbstractModel/Handle.hpp>

#include <IApplicationView.hpp>
#include <INewDocumentView.hpp>
#include <IDocumentView.hpp>

#include <IImageDataSource.hpp>

#include <ApplicationView.hpp>
#include <NewDocumentView.hpp>
#include <DocumentView.hpp>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  ViewGenerator::ViewGenerator(
    AbstractModel::Services::IImageInformationService *imageInformationService,
    AbstractModel::Services::IImageRenderingService *imageRenderingService
  )
    : m_imageInformationService(imageInformationService),
      m_imageRenderingService(imageRenderingService)
  {}

  std::unique_ptr<IApplicationView> ViewGenerator::createApplicationView() {
    return std::make_unique<ApplicationView>();
  }

  std::unique_ptr<INewDocumentView> ViewGenerator::createNewDocumentView(IApplicationView *context) {
    return std::make_unique<NewDocumentView>();
  }

  std::unique_ptr<IDocumentView> ViewGenerator::createDocumentView(
    IApplicationView *context,
    AbstractModel::Handle handle
  ) {
    // note: it seems to be a tricky problem to avoid this here
    if(ApplicationView *applicationView = dynamic_cast<ApplicationView *>(context)) {
      return std::make_unique<DocumentView>(
        m_imageInformationService, m_imageRenderingService,
        applicationView->getWidget(),
        handle
      );
    } else {
      throw UILayer::Exceptions::IncompatibleContextException("DocumentView");
    }
  }
}
