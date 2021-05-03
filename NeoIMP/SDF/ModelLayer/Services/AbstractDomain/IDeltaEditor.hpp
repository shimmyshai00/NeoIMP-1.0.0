#ifndef SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IDELTAEDITOR_HPP
#define SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IDELTAEDITOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDeltaEditor.hpp
 * PURPOSE: Defines the IDeltaEditor interface.
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

#include <SDF/Interfaces/IMessageReceiver.hpp>

#include <SDF/ModelLayer/Services/AbstractDomain/IDomainObject.hpp>

#include <SDF/UILayer/AbstractModel/Handle.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/Defs/ImageChanges.hpp>

#include <cstddef>
#include <memory>

namespace SDF::ModelLayer::Services::AbstractDomain {
  class IImage;
  class IImageDelta;

  // Function:   IDeltaEditor
  // Purpose:    Provides an interface for a domain object that applies image deltas to edit an image. This allows us to
  //             treat the undo functionality.
  // Parameters: None.
  class IDeltaEditor : public IDomainObject<IDeltaEditor> {
  public:
    virtual ~IDeltaEditor() = default;

    // Function:   getEditedImage
    // Purpose:    Gets the most recent edited version of the held image.
    // Parameters: None.
    // Returns:    The handle to the edited image.
    virtual IImage *
    getEditedImage() = 0;

    // Function:   applyDelta
    // Purpose:    Apply a delta to a given image document.
    // Parameters: delta - The delta to apply.
    //             messageReceiver - An optional message receiver to receive editing reports.
    // Returns:    None.
    virtual void
    applyDelta(std::unique_ptr<IImageDelta> delta,
               Interfaces::IMessageReceiver<Defs::ImageChange> *messageReceiver
              ) = 0;

    // Function:   getMaxUndoCount
    // Purpose:    Gets the maximum number of undoable deltas allowed per image.
    // Parameters: None.
    // Returns:    The maximum number.
    virtual std::size_t
    getMaxUndoCount() = 0;

    // Function:   setMaxUndoCount
    // Purpose:    Sets the maximum number of allowed undoable deltas per image.
    // Parameters: maxUndoCount - The new maximum undo count.
    // Returns:    None.
    virtual void
    setMaxUndoCount(std::size_t maxUndoCount) = 0;

    // Function:   getNumReversibleDeltas
    // Purpose:    Gets the number of reversible deltas applied to the held image.
    // Parameters: None.
    // Returns:    The desired count.
    virtual std::size_t
    getNumReversibleDeltas() = 0;

    // Function:   undoLastDelta
    // Purpose:    Undo (if any) the last reversible delta on the held image.
    // Parameters: None.
    // Returns:    None.
    virtual void
    undoLastDelta() = 0;
  };
}

#endif
