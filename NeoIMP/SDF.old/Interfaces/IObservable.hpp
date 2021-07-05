#ifndef SDF_INTERFACES_IOBSERVABLE_HPP
#define SDF_INTERFACES_IOBSERVABLE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IObservable.hpp
 * PURPOSE: Defines the IObservable interface.
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

namespace SDF::Interfaces {
  template<class T>
  class IEventHandler;

  // Class:      IObservable
  // Purpose:    Defines an interface for objects that can be observed, as in an observer pattern, with event receivers
  //             added and removed.
  // Parameters: EventT - The event type that is produced by this observable.
  template<class EventT>
  class IObservable {
  public:
    virtual ~IObservable() = default;

    // Function:   attachObserver
    // Purpose:    Add an observer to this observable.
    // Parameters: observer - The observer to attach.
    // Returns:    None.
    virtual void
    attachObserver(IEventHandler<EventT> *observer) = 0;

    // Function:   removeObserver
    // Purpose:    Remove an observer from this observable.
    // Parmaeters: observer - The observer to remove.
    // Returns:    None.
    virtual void
    removeObserver(IEventHandler<EventT> *observer) = 0;
  };
}

#endif
