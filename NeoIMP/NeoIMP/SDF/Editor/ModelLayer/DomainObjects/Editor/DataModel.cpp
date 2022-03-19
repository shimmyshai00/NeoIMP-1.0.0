/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DataModel.cpp
 * PURPOSE: Implements the DataModel class.
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

#include "DataModel.hpp"

#include "../../Exceptions.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Editor {
  DataModel::DataModel()
    : m_activeDocumentHandle(Common::HANDLE_INVALID),
      m_nextViewKey(0)
  {
  }

  void
  DataModel::createDocumentRecord(Common::Handle documentHandle) {
    if(m_documentNames.find(documentHandle) != m_documentNames.end()) {
      throw DocumentAlreadyRegisteredException();
    } else {
      m_documentNames[documentHandle] = "";
    }
  }

  void
  DataModel::deleteDocumentRecord(Common::Handle documentHandle) {
    m_documentNames.erase(documentHandle);
  }

  Common::Handle
  DataModel::getActiveDocument() const {
    return m_activeDocumentHandle;
  }

  void
  DataModel::setActiveDocument(Common::Handle activeDocumentHandle) {
    m_activeDocumentHandle = activeDocumentHandle;
  }

  std::string
  DataModel::getDocumentName(Common::Handle documentHandle) {
    if(m_documentNames.find(documentHandle) == m_documentNames.end()) {
      throw DocumentNotFoundInDataModelException();
    } else {
      return m_documentNames[documentHandle];
    }
  }

  void
  DataModel::setDocumentName(Common::Handle documentHandle, std::string name) {
    if(m_documentNames.find(documentHandle) == m_documentNames.end()) {
      throw DocumentNotFoundInDataModelException();
    } else {
      m_documentNames[documentHandle] = name;
    }
  }

  Common::Handle
  DataModel::addViewToDocument(Common::Handle documentHandle) {
    if(m_documentNames.find(documentHandle) == m_documentNames.end()) {
      throw DocumentNotFoundInDataModelException();
    } else {
      Common::Handle viewHandle(m_nextViewKey++);
      m_documentViews[viewHandle] = ViewAnchor(documentHandle);

      return viewHandle;
    }
  }

  void
  DataModel::destroyView(Common::Handle viewHandle) {
    if(m_documentNames.find(documentHandle) == m_documentNames.end()) {
      throw DocumentNotFoundInDataModelException();
    } else {
      if(m_documentViews.find(viewHandle) == m_documentViews.end()) {
        throw ViewNotFoundException();
      } else {
        m_documentViews.erase(viewHandle);
      }
    }
  }

  float
  DataModel::getViewAnchorX(Common::Handle viewHandle) const {
    if(m_documentViews.find(viewHandle) == m_documentViews.end()) {
      throw ViewNotFoundException();
    } else {
      ViewAnchor anchor = m_documentViews[viewHandle];
      if(m_documentNames.find(anchor.m_document) == m_documentNames.end()) {
        throw DocumentNotFoundInDataModelException();
      } else {
        return anchor.m_position.m_x;
      }
    }
  }

  float
  DataModel::getViewAnchorY(Common::Handle viewHandle) const {
    if(m_documentViews.find(viewHandle) == m_documentViews.end()) {
      throw ViewNotFoundException();
    } else {
      ViewAnchor anchor = m_documentViews[viewHandle];
      if(m_documentNames.find(anchor.m_document) == m_documentNames.end()) {
        throw DocumentNotFoundInDataModelException();
      } else {
        return anchor.m_position.m_y;
      }
    }
  }

  float
  DataModel::getViewAnchorMag(Common::Handle viewHandle) const {
    if(m_documentViews.find(viewHandle) == m_documentViews.end()) {
      throw ViewNotFoundException();
    } else {
      ViewAnchor anchor = m_documentViews[viewHandle];
      if(m_documentNames.find(anchor.m_document) == m_documentNames.end()) {
        throw DocumentNotFoundInDataModelException();
      } else {
        return anchor.m_m_magnification;
      }
    }
  }

  void
  DataModel::setViewAnchorX(Common::Handle viewHandle, float x) {
    if(m_documentViews.find(viewHandle) == m_documentViews.end()) {
      throw ViewNotFoundException();
    } else {
      ViewAnchor anchor = m_documentViews[viewHandle];
      if(m_documentNames.find(anchor.m_document) == m_documentNames.end()) {
        throw DocumentNotFoundInDataModelException();
      } else {
        anchor.m_position.m_x = x;
      }
    }
  }

  void
  DataModel::setViewAnchorY(Common::Handle viewHandle, float y) {
    if(m_documentViews.find(viewHandle) == m_documentViews.end()) {
      throw ViewNotFoundException();
    } else {
      ViewAnchor anchor = m_documentViews[viewHandle];
      if(m_documentNames.find(anchor.m_document) == m_documentNames.end()) {
        throw DocumentNotFoundInDataModelException();
      } else {
        anchor.m_position.m_y = y;
      }
    }
  }

  void
  DataModel::setViewAnchorMag(Common::Handle viewHandle, float mag) {
    if(m_documentViews.find(viewHandle) == m_documentViews.end()) {
      throw ViewNotFoundException();
    } else {
      ViewAnchor anchor = m_documentViews[viewHandle];
      if(m_documentNames.find(anchor.m_document) == m_documentNames.end()) {
        throw DocumentNotFoundInDataModelException();
      } else {
        anchor.m_position.m_magnification = mag;
      }
    }
  }

  void
  DataModel::setViewAnchorXY(Common::Handle viewHandle, float x, float y) {
    if(m_documentViews.find(viewHandle) == m_documentViews.end()) {
      throw ViewNotFoundException();
    } else {
      ViewAnchor anchor = m_documentViews[viewHandle];
      if(m_documentNames.find(anchor.m_document) == m_documentNames.end()) {
        throw DocumentNotFoundInDataModelException();
      } else {
        anchor.m_position.m_x = x;
        anchor.m_position.m_y = y;
      }
    }
  }

  void
  DataModel::setViewAnchorAll(Common::Handle viewHandle, float x, float y, float mag) {
    if(m_documentViews.find(viewHandle) == m_documentViews.end()) {
      throw ViewNotFoundException();
    } else {
      ViewAnchor anchor = m_documentViews[viewHandle];
      if(m_documentNames.find(anchor.m_document) == m_documentNames.end()) {
        throw DocumentNotFoundInDataModelException();
      } else {
        anchor.m_position.m_x = x;
        anchor.m_position.m_y = y;
        anchor.m_magnification = mag;
      }
    }
  }
}
