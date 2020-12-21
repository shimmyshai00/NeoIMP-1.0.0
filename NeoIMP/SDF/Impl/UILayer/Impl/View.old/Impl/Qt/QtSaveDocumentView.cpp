/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    QtSaveDocumentView.cpp
 * PURPOSE: The Qt-based save-document view implementation.
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

#include <QtSaveDocumentView.hpp>

#include <AbstractController/IAcceptDocumentSaveParamsCommandObserver.hpp>

#include <QApplication>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  QtSaveDocumentView::QtSaveDocumentView(QFileDialog *saveFileDialog) : m_saveFileDialog(saveFileDialog) {
    m_acceptDocumentSaveParamsCommandObserverConn = QFileDialog::connect(
      m_saveFileDialog,
      &QFileDialog::accepted,
      [=]() {
        QString file(m_saveFileDialog->selectedFiles()[0]);
        m_acceptDocumentSaveParamsCommandObserver->onAcceptDocumentSaveParamsCommand(
          file.toStdString(), AbstractModel::Properties::FILE_FORMAT_PNG
        );
      }
    );
  }

  QtSaveDocumentView::~QtSaveDocumentView() {
    QObject::disconnect(m_acceptDocumentSaveParamsCommandObserverConn);
  }

  void QtSaveDocumentView::show() {
    m_saveFileDialog->open();
  }

  void QtSaveDocumentView::setAcceptDocumentSaveParamsCommandObserver(
    AbstractController::IAcceptDocumentSaveParamsCommandObserver *observer
  ) {
    m_acceptDocumentSaveParamsCommandObserver = observer;
  }
}
