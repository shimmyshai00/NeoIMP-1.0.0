#ifndef SDF_MODELLAYER_DOMAINOBJECTS_EDITING_DELTAEDITOR_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_EDITING_DELTAEDITOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DeltaEditor.hpp
 * PURPOSE: Defines the DeltaEditor class.
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

#include <SDF/Interfaces/IGenerator.hpp>
#include <SDF/Interfaces/IMessageReceiver.hpp>

#include <SDF/ModelLayer/Services/AbstractDomain/IDeltaEditor.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/Defs/ImageChanges.hpp>

#include <SDF/UILayer/AbstractModel/Handle.hpp>

#include <cstddef>
#include <memory>

namespace SDF::ModelLayer {
  namespace Services::AbstractDomain {
    class IImage;
    class IImageDelta;
  }

  namespace DomainObjects::Editing {
    // Class:      DeltaEditor
    // Purpose:    Implements the image delta editor.
    // Parameters: None.
    class DeltaEditor : public Services::AbstractDomain::IDeltaEditor {
    public:
      DeltaEditor(int id,
                  Services::AbstractDomain::IImage *image
                 );

      int
      getId() const;

      Services::AbstractDomain::IImage *
      getEditedImage();

      void
      applyDelta(std::unique_ptr<Services::AbstractDomain::IImageDelta> delta,
                 Interfaces::IMessageReceiver<Services::AbstractDomain::Defs::ImageChange> *messageReceiver
                );

      std::size_t
      getMaxUndoCount();

      void
      setMaxUndoCount(std::size_t maxUndoCount);

      std::size_t
      getNumReversibleDeltas();

      void
      undoLastDelta();
    private:
      int m_id;

      Services::AbstractDomain::IImage *m_image;
    };
  }
}

#endif
