/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    QtApplication.cpp
 * PURPOSE: Implementation of the QtApplication class.
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

#include <QtApplication.hpp>

#include <UILayer/IUIEntryPoint.hpp>

#include <UILayer/UIComponent.hpp>

#include <QApplication>
#include <fruit/fruit.h>

namespace SDF::Impl::Qt {
  QtApplication::QtApplication()
  {
  }

  int QtApplication::exec(int argc, char **argv) {
    QApplication q(argc, argv);

    fruit::Injector<UILayer::IUIEntryPoint> uiInjector(UILayer::getUIComponent);
    UILayer::IUIEntryPoint *ui(uiInjector.get<UILayer::IUIEntryPoint *>());

    ui->start();

    return q.exec();
  }
}
