#ifndef SDF_ERROR_SAFESTRING_HPP
#define SDF_ERROR_SAFESTRING_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SafeString.hpp
 * PURPOSE: Exception-safe string class for use in exception objects.
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

#include <cstring>
#include <cstdio>
#include <cstddef>
#include <cstdarg>

namespace SDF::Error {
  class SafeString {
		public:
			SafeString() noexcept {
				stringBuf[0] = '\0';
			}

			SafeString(const char *initString) noexcept {
				strncpy(stringBuf, initString, c_maxStrLen);
				stringBuf[c_maxStrLen + 1] = '\0';
			}

			const char* get() const noexcept {
				return stringBuf;
			}

			// like sprintf
			void sPrintf(const char *fString, ...) noexcept {
				va_list vl;

				va_start(vl, fString);
				vsPrintf(fString, vl);
				va_end(vl);
			}

			// like vsprintf
			void vsPrintf(const char *fString, va_list vl) noexcept {
				vsnprintf(stringBuf, c_maxStrLen, fString, vl);
			}
		private:
			static const std::size_t c_maxStrLen = 1023;
			char stringBuf[c_maxStrLen + 1];
	};

  // Convenience methods.
  SafeString safePrintf(const char *fString, ...) noexcept {
    SafeString rv;
    va_list vl;

    va_start(vl, fString);
    rv.vsPrintf(fString, vl);
    va_end(vl);

    return rv;
  }
}

#endif
