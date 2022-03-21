#ifndef SDF_EDITOR_DATALAYER_DATAMAPPERS_IMAGEMAPPER_TPP
#define SDF_EDITOR_DATALAYER_DATAMAPPERS_IMAGEMAPPER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageMapper.tpp
 * PURPOSE: Implements the ImageMapper template.
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

#include "../../ModelLayer/AbstractData/Exceptions.hpp"
#include "../Exceptions.hpp"
#include "applyPersister.hpp"
#include "inverseApply.hpp"
#include "EDirection.hpp"

namespace SDF::Editor::DataLayer::DataMappers {
  template<class PersisterT, class ImageT>
  ImageMapper<PersisterT, ImageT>::ImageMapper(
    Common::Data::Adapters::IFilesystemAdapter *filesystemAdapter
  )
    : m_filesystemAdapter(filesystemAdapter)
  {
  }

  template<class PersisterT, class ImageT>
  bool
  ImageMapper<PersisterT, ImageT>::has(std::string fileSpec) {
    Common::Data::Adapters::FilesystemKey fsk(fileSpec, 0, 0);
    return m_filesystemAdapter->exist(fsk);
  }

  template<class PersisterT, class ImageT>
  void
  ImageMapper<PersisterT, ImageT>::insert(std::string fileSpec, ImageT &obj) {
    if(has(fileSpec)) {
      throw DoubleMapException();
    }

    // Boost.GIL does not require direct interaction with the file system by us
    PersisterT persister(fileSpec, DIR_SAVE);
    applyPersister(persister, obj);
  }

  template<class PersisterT, class ImageT>
  void
  ImageMapper<PersisterT, ImageT>::retrieve(std::string fileSpec, ImageT &obj) {
    // NB/FEEDBACK REQ: the DM interface does not specify the creation of an initial object (note
    // the pass-by-reference) because of this thread and answer post by tereško,
    // https://stackoverflow.com/questions/11873752/how-should-a-data-mapper-return-a-domain-object
    //  ?noredirect=1&lq=1
    // where he seems to have implicitly endorsed suggestion by the OP that to pass a factory or
    // otherwise have a data mapper create domain objects violates the single-responsibility
    // principle, but it seems hard to see a solution for how this can be avoided when the domain
    // object in question is a composite, as in the case of an image, thus requiring additional
    // domain objects (the components of the composition) to be created for which they cannot be
    // predicted in advance because they depend on the content of the file, so someone who has more
    // understanding of what's going on can/should weigh in on this and explain if there is a better
    // way to do this or whether it really is as problematic as the two there are implying it is.
    //
    // Hence right now we are creating domain objects directly - we could use a factory, but still
    // note what is said there. The persister creates domain objects (components of ImageT).
    if(!has(fileSpec)) {
      throw FileNotFoundException();
    }


    PersisterT persister(fileSpec, DIR_LOAD);
    applyPersister(persister, obj);
  }

  template<class PersisterT, class ImageT>
  void
  ImageMapper<PersisterT, ImageT>::update(std::string fileSpec, ImageT &obj) {
    if(!has(fileSpec)) {
      throw FileSpecNotMappedException();
    }

    // Boost.GIL does not require direct interaction with the file system by us
    PersisterT persister(fileSpec, DIR_SAVE);
    applyPersister(persister, obj);
  }

  template<class PersisterT, class ImageT>
  void
  ImageMapper<PersisterT, ImageT>::erase(std::string fileSpec) {
    // NB: delete a file??? May be dangerous! what this should do, if anything, TBA
    throw "NOT YET IMPLEMENTED";
  }
}

#endif
