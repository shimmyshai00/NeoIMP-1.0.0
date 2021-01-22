/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentStateModel.cpp
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

#include <DocumentStateModel.hpp>

namespace SDF::Impl::AppModelLayer::Impl {
  DocumentStateModel::DocumentStateModel(UILayer::AbstractAppModel::Handle documentHandle,
                                         UILayer::AbstractAppModel::Data::DocumentSpec spec,
                                         const unsigned char *renderedDataPtr
                                        )
    : m_documentHandle(documentHandle),
      m_documentName(spec.documentName),
      m_documentWidthPx(spec.documentWidthPx),
      m_documentHeightPx(spec.documentHeightPx),
      m_documentResolutionPpi(spec.documentResolutionPpi),
      m_renderedDataPtr(renderedDataPtr)
  {}

  void
  DocumentStateModel::setDocumentName(std::string newName) {
    m_documentName = newName;
    onDocumentNameChanged(newName);
  }

  void
  DocumentStateModel::setDocumentWidthPx(int documentWidthPx) {
    m_documentWidthPx = documentWidthPx;
  }

  void
  DocumentStateModel::setDocumentHeightPx(int documentHeightPx) {
    m_documentHeightPx = documentHeightPx;
  }

  void
  DocumentStateModel::setDocumentResolutionPpi(float documentResolutionPpi) {
    m_documentResolutionPpi = documentResolutionPpi;
  }

  void
  DocumentStateModel::setRenderedImageDataPtr(const unsigned char *renderedDataPtr) {
    m_renderedDataPtr = renderedDataPtr;
  }

  UILayer::AbstractAppModel::Handle
  DocumentStateModel::getDocumentHandle() {
    return m_documentHandle;
  }

  std::string
  DocumentStateModel::getDocumentName() {
    return m_documentName;
  }

  int
  DocumentStateModel::getDocumentWidthPx() {
    return m_documentWidthPx;
  }

  int
  DocumentStateModel::getDocumentHeightPx() {
    return m_documentHeightPx;
  }

  float
  DocumentStateModel::getDocumentResolutionPpi() {
    return m_documentResolutionPpi;
  }

  void
  DocumentStateModel::getRenderedImageData(const unsigned char *&origin,
                                           std::ptrdiff_t &rowStride,
                                           int x1, int y1, int x2, int y2
                                          )
  {
    origin = m_renderedDataPtr + (4*(y1*m_documentWidthPx + x1)); // TBA: "4" is from RGB32 = 4 bytes - may need to
                                                                  // generalize?
    rowStride = 4*m_documentWidthPx;
  }
}
