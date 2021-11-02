#ifndef SDF_PATTERNS_SUBJECT_HPP
#define SDF_PATTERNS_SUBJECT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Subject.hpp
 * PURPOSE: Defines the Subject template.
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

#include "IObserver.hpp"
#include "IConnection.hpp"

#include <vector>
#include <memory>

namespace SDF::Patterns {
  // Class:      Subject
  // Purpose:    Provides an observable subject to be observed with objects of type IObserver<...>.
  // Parameters: SubjT - The user should CRTP-inherit this class.
  template<class SubjT>
  class Subject {
  public:
    virtual ~Subject() = 0;

    // Function:   addObserver
    // Purpose:    Add an observer to the subject.
    // Parameters: obs - The observer to add.
    // Returns:    A connection to the observer.
    std::shared_ptr<IConnection>
    addObserver(IObserver<SubjT> *observer);
  protected:
    // Function:   notifyObservers
    // Purpose:    Notify observers of a change in the subject.
    // Parameters: None.
    // Returns:    None.
    void
    notifyObservers();
  private:
    class Connection : IConnection {
    public:
      Connection(Subject<SubjT> *subj,
                 IObserver<SubjT> *obs
                )
        : m_subj(subj),
          m_obs(obs)
      {
      }

      void
      connect() {
        m_subj->m_observers.push_back(m_obs);
      }

      void
      disconnect() {
        m_subj->m_observers.erase(m_obs);
      }
    private:
      Subject<SubjT> *m_subj;
      IObserver<SubjT> *m_obs;
    };

    std::vector<IObserver<SubjT> *> m_observers;
  };
}

#include "Subject.tpp"

#endif
