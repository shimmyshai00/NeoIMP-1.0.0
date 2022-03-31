#ifndef SDF_EDITOR_DATALAYER_DATAMAPPERS_INVERSEAPPLY_HPP
#define SDF_EDITOR_DATALAYER_DATAMAPPERS_INVERSEAPPLY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    inverseApply.hpp
 * PURPOSE: Defines methods to apply a functor, instead of to what is contained in a variant, to
 *          each type in the variant in succession. This is a template metaprogramming hack.
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

#include <boost/variant2/variant.hpp>
#include <boost/mp11/list.hpp>

namespace SDF::Editor::DataLayer::DataMappers {
  // Apply the operation Op for each type given in succession until either it returns True, or we
  // run out of types. We call it "inverse application" because while applyPersister takes a variant
  // and applies variably to the type contained therein, this presumes a variant implicity and
  // applies to the *types* one at a time.
  namespace Impl {
    template<class ImplSpecT, class ... ImplSpecTs>
    struct App {
      template<class Op>
      bool operator()(Op op) {
        if(op.template apply<ImplSpecT>()) {
          return true;
        } else {
          return App<ImplSpecTs...>(op);
        }
      }
    };

    template<class ImplSpecT>
    struct App<ImplSpecT> {
      template<class Op>
      bool operator()(Op op) {
        return op.template apply<ImplSpecT>();
      }
    };
  }

  template<class Op, class ImageT>
  bool inverseApply(Op op) {
    boost::mp11::mp_apply<Impl::App, ImageT> implOpp;
    return implOpp(op);
  }
}

#endif
