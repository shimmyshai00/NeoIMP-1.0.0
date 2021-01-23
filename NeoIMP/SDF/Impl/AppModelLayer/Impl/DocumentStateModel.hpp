#ifndef SDF_IMPL_APPMODELLAYER_IMPL_DOCUMENTSTATEMODEL_HPP
#define SDF_IMPL_APPMODELLAYER_IMPL_DOCUMENTSTATEMODEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentStateModel.hpp
 * PURPOSE: Centralizes all the UI state for a single document.
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

#include <SDF/Impl/UILayer/AbstractAppModel/State/IDocumentAppModel.hpp>
#include <SDF/Impl/UILayer/AbstractAppModel/Data/DocumentSpec.hpp>

#include <fruit/fruit.h>
#include <vector>
#include <string>
#include <cstdlib>

namespace SDF::Impl::AppModelLayer::Impl {
  class DocumentStateModel : public UILayer::AbstractAppModel::State::IDocumentAppModel {
  public:
    DocumentStateModel(UILayer::AbstractAppModel::Handle documentHandle,
                       std::string documentName,
                       int documentWidthPx,
                       int documentHeightPx,
                       float documentResolutionPpi,
                       const unsigned char *renderedDataPtr
                      );
    DocumentStateModel(UILayer::AbstractAppModel::Handle documentHandle,
                       UILayer::AbstractAppModel::Data::DocumentSpec spec,
                       const unsigned char *renderedDataPtr
                      );
                      
    // State manipulation.
    void setDocumentName(std::string newName);

    void setDocumentWidthPx(int documentWidthPx);
    void setDocumentHeightPx(int documentHeightPx);
    void setDocumentResolutionPpi(float documentResolutionPpi);

    void setRenderedImageDataPtr(const unsigned char *renderedDataPtr);

    // State access.
    UILayer::AbstractAppModel::Handle getDocumentHandle();
    std::string getDocumentName();

    int getDocumentWidthPx();
    int getDocumentHeightPx();
    float getDocumentResolutionPpi();

    void getRenderedImageData(const unsigned char *&origin,
                              std::ptrdiff_t &rowStride,
                              int x1, int y1, int x2, int y2
                             );
  private:
    // State.
    UILayer::AbstractAppModel::Handle m_documentHandle; // NB: is this the best place to keep this back reference?
    std::string m_documentName;

    int m_documentWidthPx;
    int m_documentHeightPx;
    float m_documentResolutionPpi;

    const unsigned char *m_renderedDataPtr;
  };
}

#endif
