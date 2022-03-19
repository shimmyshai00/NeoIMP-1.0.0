#ifndef SDF_COMMON_VALUEFIELD_HPP
#define SDF_COMMON_VALUEFIELD_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ValueField.hpp
 * PURPOSE: Defines the ValueField template.
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

#include "IValueField.hpp"
#include "IListener.hpp"
#include "IConnection.hpp"

#include "ListenerContainer.hpp"

#include <memory>

namespace SDF::Common {
  // Class:      ValueField
  // Purpose:    Provides a default implementation of a segregated value-holding object.
  // Parameters: ValueT - The value type held.
  template<class ValueT>
  class ValueField : public IValueField<ValueT> {
  public:
    // Function:   ValueField
    // Purpose:    Constructs a new value field with a given default value.
    // Parameters: def - The default value.
    ValueField(ValueT def);

    const ValueT &
    get() const;

    void
    set(ValueT val);

    PIConnection
    addListener(std::shared_ptr<IListener<ValueT>> listener);
  private:
    ValueT m_value;
    ListenerContainer<ValueT> m_listeners;
  };
}

#include "ValueField.tpp"

#endif
