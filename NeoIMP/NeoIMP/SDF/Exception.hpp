#ifndef SDF_EXCEPTION_HPP
#define SDF_EXCEPTION_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exception.hpp
 * PURPOSE: Base class for custom exceptions.
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

#include "SafeString.hpp"

#include <cstdarg>

namespace SDF {
  // Note: In this, the guideline for defining "likely bug" exceptions should be those that a user
  //       *of a layer* should not be able to induce to come out of that layer by setting parameters
  //       on the interface inappropriately, nor are the result of some external contingency (i.e.
  //       a network connection loss). These often (not necessarily!) would mean a program bug.
  //       These inner exceptions need not be as specific because they are ideally not seen by the
  //       end-user but instead to be traced by a debugger; the most important point is the user
  //       knows a bug was hit. On the other hand, non-bug exceptions should be plentiful and have
  //       detailed and informative what strings, especially when they're likely to reach the user
  //       interface.
  class Exception : public std::exception {
		public:
			Exception(bool likelyBug, const char *whatFString, ...) noexcept {
				va_list vl;
        SafeString preWhatString;

				va_start(vl, whatFString);
				preWhatString.vsPrintf(whatFString, vl);
        va_end(vl);

        if(likelyBug) {
          whatString.sPrintf(
            "%s\n\nThis likely means there is a bug in the program.",
            preWhatString.get()
          );
        } else {
          whatString.sPrintf("%s", preWhatString.get());
        }
			}

			virtual ~Exception() noexcept {}

			const char* what() const noexcept final {
				return whatString.get();
			}
		private:
      bool likelyBug;
			SafeString whatString;
	};
}

// Convenience MACRO for defining a new exception type.
#define SDF_DEF_NRM_EXCEPTION(excName, whatString) \
  struct excName : public SDF::Exception { \
    excName() noexcept : Exception(false, whatString) {} \
  };

#define SDF_DEF_NRM_EXCEPTION_1(excName, whatString, typ1) \
  struct excName : public SDF::Exception { \
    excName(typ1 arg1) noexcept : Exception(false, whatString, arg1) {} \
  };

#define SDF_DEF_NRM_EXCEPTION_2(excName, whatString, typ1, typ2) \
  struct excName : public SDF::Exception { \
    excName(typ1 arg1, typ2 arg2) noexcept : Exception(false, whatString, arg1, arg2) {} \
  };

#define SDF_DEF_NRM_EXCEPTION_3(excName, whatString, typ1, typ2, typ3) \
  struct excName : public SDF::Exception { \
    excName(typ1 arg1, typ2 arg2, typ3 arg3) noexcept \
      : Exception(false, whatString, arg1, arg2, arg3) {} \
  };

#define SDF_DEF_NRM_EXCEPTION_4(excName, whatString, typ1, typ2, typ3, typ4) \
  struct excName : public SDF::Exception { \
    excName(typ1 arg1, typ2 arg2, typ3 arg3, typ4 arg4) noexcept \
      : Exception(false, whatString, arg1, arg2, arg3, arg4) {} \
  };

#define SDF_DEF_BUG_EXCEPTION(excName, whatString) \
  struct excName : public SDF::Exception { \
    excName() noexcept : Exception(false, whatString) {} \
  };

#define SDF_DEF_BUG_EXCEPTION_1(excName, whatString, typ1) \
  struct excName : public SDF::Exception { \
    excName(typ1 arg1) noexcept : Exception(false, whatString, arg1) {} \
  };

#define SDF_DEF_BUG_EXCEPTION_2(excName, whatString, typ1, typ2) \
  struct excName : public SDF::Exception { \
    excName(typ1 arg1, typ2 arg2) noexcept : Exception(false, whatString, arg1, arg2) {} \
  };

#endif
