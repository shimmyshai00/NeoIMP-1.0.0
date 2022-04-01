#ifndef SDF_COMMON_VALUEFIELD_TPP
#define SDF_COMMON_VALUEFIELD_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ValueField.tpp
 * PURPOSE: Implements the ValueField template.
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

namespace SDF::Common {
  template<class ValueT>
  ValueField<ValueT>::ValueField(ValueT a_def)
    : m_value(a_def)
  {
  }

  template<class ValueT>
  ValueField<ValueT>::ValueField(const ValueField<ValueT> &a_rhs)
    : m_value(a_rhs.m_value)
  {
  }

  template<class ValueT>
  ValueField<ValueT>::ValueField(ValueField<ValueT> &&a_rhs)
    : m_value(a_rhs.m_value),
      m_listeners(a_rhs.m_listeners)
  {
    a_rhs.m_value = ValueT();
    a_rhs.m_listeners = ListenerContainer<ValueT>();
  }

  template<class ValueT>
  const ValueT &
  ValueField<ValueT>::get() const {
    return m_value;
  }

  template<class ValueT>
  void
  ValueField<ValueT>::set(ValueT a_val) {
    m_value = a_val;
    m_listeners.notify(a_val);
  }

  template<class ValueT>
  PIConnection
  ValueField<ValueT>::addListener(std::shared_ptr<IListener<ValueT>> a_listener) {
    return m_listeners.addListener(a_listener);
  }
}

#endif
