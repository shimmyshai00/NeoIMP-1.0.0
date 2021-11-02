#ifndef SDF_PATTERNS_SUBJECT_TPP
#define SDF_PATTERNS_SUBJECT_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Subject.tpp
 * PURPOSE: Implements the Subject template.
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
  template<class SubjT>
  Subject<SubT>::~Subject() {
  }

  template<class SubjT>
  std::shared_ptr<IConnection>
  Subject<SubjT>::addObserver(IObserver<SubjT> *observer) {
    return std::shared_ptr<IConnection>(new Connection(this, observer));
  }

  template<class SubjT>
  void
  Subject<SubjT>::notifyObservers() {
    for(auto obs : m_observers) {
      obs->onChanged(static_cast<SubjT *>(this));
    }
  }
}

#endif
