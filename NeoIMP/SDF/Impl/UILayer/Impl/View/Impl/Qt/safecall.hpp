#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_SAFECALL_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_SAFECALL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    safecall.hpp
 * PURPOSE: Provides an exception-checked safe call of a boost::signals2 to convert exceptions to error messages when
 *          a controller method fails as a means of default error handling - customized handling, if needed, should be
 *          implemented separately.
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

#include <boost/signals2/signal.hpp>
#include <QMessageBox>

#include <SDF/Exception/Exception.hpp>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  template<class ... Args>
  void safeCall(boost::signals2::signal<void (Args...)> sig, Args... args) {
    try {
      sig(args);
    } catch(SDF::Exception::Exception &e) {
      QMessageBox::warning(nullptr, "Error", e.what());
    }
  }
}

#endif
