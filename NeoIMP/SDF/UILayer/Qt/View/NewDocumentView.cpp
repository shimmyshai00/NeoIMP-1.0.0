/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentView.cpp
 * PURPOSE: Implementation of the NewDocumentView class.
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

#include <NewDocumentView.hpp>

#include <Controller/INewDocumentParameterReceiver.hpp>
#include <Dialogs/NewDocumentDialog.hpp>

#include <QObject>

namespace SDF::UILayer::Qt::View {
  class NewDocumentView : public Controller::INewDocumentView {
  public:
    INJECT(NewDocumentView()) {}
    ~NewDocumentView() {}

    void requestNewDocumentParamsFromUser(Controller::INewDocumentParameterReceiver *recv) {
      // Start a modal dialog box to get the parameters.
      Dialogs::NewDocumentDialog *dialog(new Dialogs::NewDocumentDialog);
      QObject::connect(dialog, &QDialog::accepted, dialog, [=]() { dialog->submit(recv); });
      dialog->open();
    }
  };
}

namespace SDF::UILayer::Qt::View {
  fruit::Component<Controller::INewDocumentView> getNewDocumentViewComponent() {
    return fruit::createComponent()
      .bind<Controller::INewDocumentView, NewDocumentView>();
  }
}
