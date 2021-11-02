#ifndef SDF_PATTERNS_LISTENABLE_TPP
#define SDF_PATTERNS_LISTENABLE_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Listenable.tpp
 * PURPOSE: Implements the Listenable template.
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

namespace SDF::Patterns {
  template<class EventT>
  Listenable<EventT>::~Listenable() {
  }

  template<class EventT>
  std::shared_ptr<IConnection>
  Listenable<EventT>::addListener(IListener<EventT> *listener) {
    return std::shared_ptr<IConnection>(new Connection(this, listener));
  }

  template<class EventT>
  void
  Listenable<EventT>::sendEvent(std::shared_ptr<EventT> event) {
    for(auto lis : m_listeners) {
      lis->onEvent(event);
    }
  }
}

#endif
