#ifndef SDF_PATTERNS_LISTENABLE_HPP
#define SDF_PATTERNS_LISTENABLE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Listenable.hpp
 * PURPOSE: Defines the Listenable template.
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

#include "IListener.hpp"
#include "IConnection.hpp"

#include <vector>
#include <memory>

namespace SDF::Patterns {
  // Class:      Listenable
  // Purpose:    Provides an event source to be listened to with with objects of type IListener<...>.
  // Parameters: EventT - The type of event the listenable releases.
  template<class EventT>
  class Listenable {
  public:
    virtual ~Listenable() = 0;

    // Function:   addListener
    // Purpose:    Add a listener to the event source.
    // Parameters: listener - The listener to add.
    // Returns:    A connection to the listener.
    std::shared_ptr<IConnection>
    addListener(IListener<EventT> *listener);
  protected:
    // Function:   sendEvent
    // Purpose:    Send an event to the listeners.
    // Parameter:  event - The event to send.
    // Returns:    None.
    void
    sendEvent(std::shared_ptr<EventT> event);
  private:
    class Connection : IConnection {
    public:
      Connection(Listenable<EventT> *esrc,
                 IListener<EventT> *lis
                )
        : m_esrc(esrc),
          m_lis(lis)
      {
      }

      void
      connect() {
        m_esrc->m_listeners.push_back(m_lis);
      }

      void
      disconnect() {
        m_esrc->m_listeners.erase(m_lis);
      }
    private:
      Listenable<EventT> *m_eesrc;
      IListener<EventT> *m_lis;
    };

    std::vector<IListener<EventT> *> m_listeners;
  };
}

#include "Listenable.tpp"

#endif
