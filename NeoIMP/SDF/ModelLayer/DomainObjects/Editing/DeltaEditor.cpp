/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DeltaEditor.cpp
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

#include "DeltaEditor.hpp"

#include <AbstractData/IRepository.hpp>

#include <Services/AbstractDomain/IImage.hpp>
#include <Services/AbstractDomain/IImageDelta.hpp>

namespace SDF::ModelLayer::DomainObjects::Editing {
  DeltaEditor::DeltaEditor(int id,
                           Services::AbstractDomain::IImage *image
                          )
    : m_id(id),
      m_image(image)
  {
  }

  int
  DeltaEditor::getId() const {
    return m_id;
  }

  Services::AbstractDomain::IImage *
  DeltaEditor::getEditedImage() {
    // TBA: undo functionality
    return m_image;
  }

  void
  DeltaEditor::applyDelta(std::unique_ptr<Services::AbstractDomain::IImageDelta> delta,
                          Interfaces::IMessageReceiver<Services::AbstractDomain::Defs::ImageChange> *messageReceiver
                         )
  {
    // TBA: undo functionality
    delta->applyDelta(m_image, messageReceiver);
  }

  std::size_t
  DeltaEditor::getMaxUndoCount() {
    return 0; // TBA
  }

  void
  DeltaEditor::setMaxUndoCount(std::size_t maxUndoCount) {
    // TBA
  }

  std::size_t
  DeltaEditor::getNumReversibleDeltas() {
    return 0; // TBA
  }

  void
  DeltaEditor::undoLastDelta() {
    // TBA
  }
}
