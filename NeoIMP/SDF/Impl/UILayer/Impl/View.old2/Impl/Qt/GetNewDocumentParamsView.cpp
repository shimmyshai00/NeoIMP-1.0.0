/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GetNewDocumentParamsView.cpp
 * PURPOSE: The Qt-based get new document parameters view object. This just wraps the associated dialog box.
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

#include <GetNewDocumentParamsView.hpp>

#include <Dialogs/NewDocumentDialog.hpp>
#include <Observers/IGetNewDocumentParamsViewObserver.hpp>

#include <QObject>

#include <algorithm>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  GetNewDocumentParamsView::GetNewDocumentParamsView(QPointer<Dialogs::NewDocumentDialog> newDocumentDialog)
    : m_newDocumentDialog(newDocumentDialog)
  {
    QObject::connect(m_newDocumentDialog, &Dialogs::NewDocumentDialog::accepted, [=]() {
      AbstractModel::Data::DocumentSpec documentSpec {
        "Untitled",
        m_newDocumentDialog->getDocumentWidthPx(), m_newDocumentDialog->getDocumentHeightPx(),
        m_newDocumentDialog->getDocumentResolutionPpi(),
        m_newDocumentDialog->getDocumentColorModel(), m_newDocumentDialog->getDocumentBitDepth()
      };

      for(Observers::IGetNewDocumentParamsViewObserver *observer : m_observers) {
        observer->onParametersAccepted(documentSpec);
      }
    });
  }

  void GetNewDocumentParamsView::show() {
    m_newDocumentDialog->open();
  }

  void GetNewDocumentParamsView::close() {
    m_newDocumentDialog->close();
  }

  void GetNewDocumentParamsView::addObserver(Observers::IGetNewDocumentParamsViewObserver *observer) {
    if(std::find(m_observers.begin(), m_observers.end(), observer) == m_observers.end()) {
      m_observers.push_back(observer);
    }
  }

  void GetNewDocumentParamsView::removeObserver(Observers::IGetNewDocumentParamsViewObserver *observer) {
    m_observers.erase(std::find(m_observers.begin(), m_observers.end(), observer));
  }
}
