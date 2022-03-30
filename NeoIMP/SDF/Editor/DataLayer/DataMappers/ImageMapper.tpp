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

#include "../../../Error/DataException.hpp"
#include "../../../Error/SafeString.hpp"
#include "applyPersister.hpp"
#include "applyLoader.hpp"
#include "inverseApply.hpp"

namespace SDF::Editor::DataLayer::DataMappers {
  template<class FormatT, class ImageT>
  ImageMapper<FormatT, ImageT>::ImageMapper(
    Common::Data::Adapters::IFilesystemAdapter *filesystemAdapter
  )
    : m_filesystemAdapter(filesystemAdapter)
  {
  }

  template<class FormatT, class ImageT>
  bool
  ImageMapper<FormatT, ImageT>::has(std::string fileSpec) {
    Common::Data::Adapters::FilesystemKey fsk(fileSpec, 0, 0);
    return m_filesystemAdapter->exist(fsk);
  }

  template<class FormatT, class ImageT>
  void
  ImageMapper<FormatT, ImageT>::create(std::string fileSpec, const ImageT &obj) {
    if(has(fileSpec)) {
      throw Error::ObjectAlreadyExistsException<Error::SafeString>(fileSpec.c_str());
    }

    // Boost.GIL does not require direct interaction with the file system by us
    typename FormatT::persister_t persister(fileSpec);
    applyPersister(persister, obj);
  }

  template<class FormatT, class ImageT>
  void
  ImageMapper<FormatT, ImageT>::retrieve(std::string fileSpec, ImageT &obj) {
    if(!has(fileSpec)) {
      throw Error::FileNotFoundException(fileSpec.c_str());
    }

    typename FormatT::loader_t loader(fileSpec);
    applyLoader(loader, obj);
  }

  template<class FormatT, class ImageT>
  void
  ImageMapper<FormatT, ImageT>::update(std::string fileSpec, const ImageT &obj) {
    if(!has(fileSpec)) {
      throw Error::ObjectNotFoundException<Error::SafeString>(fileSpec.c_str());
    }

    // Boost.GIL does not require direct interaction with the file system by us
    typename FormatT::persister_t persister(fileSpec);
    applyPersister(persister, obj);
  }

  template<class FormatT, class ImageT>
  void
  ImageMapper<FormatT, ImageT>::deleteO(std::string fileSpec) {
    // NB: delete a file??? May be dangerous! what this should do, if anything, TBA
    throw "NOT YET IMPLEMENTED";
  }
}

#endif
