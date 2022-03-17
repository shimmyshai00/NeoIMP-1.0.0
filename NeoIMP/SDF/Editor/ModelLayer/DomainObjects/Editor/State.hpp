#ifndef SDF_EDITOR_DOMAINBOJECTS_EDITOR_STATE_HPP
#define SDF_EDITOR_DOMAINBOJECTS_EDITOR_STATE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    State.hpp
 * PURPOSE: Defines the State class.
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

#include "../../../Common/Handle.hpp"

namespace SDF::Editor::DomainObjects::Editor {
  // Class:   State
  // Purpose: Defines a domain object storing the state of the abstract, UI-independent editor. This
  //          is used by various edit operations. NOTE: This does seem to bear some kinship with the
  //          UI layer; it is hard to exactly factor it in this 3-level architecture. One could
  //          argue that it should best reside in a new kind of layer between the present model and
  //          UI layers. (In another language such as Kotlin, we might try for a Model-View-
  //          ViewModel pattern, but MVVM is very hard and/or messy to do in C++ owing to the lack
  //          of high-quality reflection features. It's part of why this program was being
  //          "reworked" so often before finally settling down as one would find browsing the
  //          repositories - trying to fiddle with these various architectural patterns and compare
  //          their pros and cons in a C++ environment. -SS)
  // NOTE: There is the potential this could grow into a "big hairy object" grab bag anti pattern.
  //       This should be watched for and it factorized accordingly as growth occurs to ensure each
  //       state object only stores logically related chunks of state (e.g. don't put tool state
  //       in here, but WHICH tool is considered active is okay!).
  class State {
  public:
    INJECT(State());

    // Function:   getActiveDocument
    // Purpose:    Gets the document marked as active for contextual editing.
    // Parameters: None.
    // Returns:    The handle of the active document in the image repository.
    Common::Handle
    getActiveDocument() const;

    // Function:   setActiveDocument
    // Purpose:    Sets the document marked as active for contextual editing.
    // Parameters: handle - The document handle for the desired active document.
    // Returns:    None.
    void
    setActiveDocument(Common::Handle handle) const;
  private:
    Common::Handle m_activeDocumentHandle;
  };
}

#endif
