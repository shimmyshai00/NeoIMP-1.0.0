/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SaveDocumentView.cpp
 * PURPOSE: The Qt-based save-document view.
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

#include <SaveDocumentView.hpp>

#include <QStringList>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  SaveDocumentView::SaveDocumentView() : m_saveDocumentDialog(new QFileDialog()) {
    m_saveDocumentDialog->setAcceptMode(QFileDialog::AcceptSave);
    
    QObject::connect(m_saveDocumentDialog, &QFileDialog::accepted, [=]() {
      QStringList fileSpecs(m_saveDocumentDialog->selectedFiles());
      std::string fileSpec(fileSpecs.at(0).toStdString());
      Framework::MVCObservable<Events::AcceptSaveParametersEvent>::notifyObservers(
        Events::AcceptSaveParametersEvent { fileSpec, AbstractModel::Properties::FileFormat::FILE_FORMAT_PNG }
      );
    });

    QObject::connect(m_saveDocumentDialog, &QFileDialog::rejected, [=]() {
      Framework::MVCObservable<Events::ViewDismissedEvent>::notifyObservers(Events::ViewDismissedEvent());
    });
  }

  void SaveDocumentView::activate() {
    m_saveDocumentDialog->open();
  }

  void SaveDocumentView::update(std::string updateEvent) {}

  void SaveDocumentView::shutdown() {
    m_saveDocumentDialog->close();
  }
}
