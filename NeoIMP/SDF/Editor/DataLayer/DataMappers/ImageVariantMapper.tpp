#ifndef SDF_EDITOR_DATALAYER_DATAMAPPERS_IMAGEVARIANTMAPPER_TPP
#define SDF_EDITOR_DATALAYER_DATAMAPPERS_IMAGEVARIANTMAPPER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageVariantMapper.tpp
 * PURPOSE: Implements the ImageVariantMapper template.
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
#include "../../ModelLayer/DomainObjects/Engine/Image/Image.hpp"
#include "Exceptions.hpp"
#include "applyPersister.hpp"
#include "applyLoader.hpp"

#include <boost/mp11/list.hpp>

namespace SDF::Editor::DataLayer::DataMappers {
  namespace Impl {
    // The trick described later
    template<class FormatT, class ImageVariantT>
    struct InverseValidateAndCreate {
      std::string m_fileName;
      ImageVariantT *m_variant;

      InverseValidateAndCreate(std::string fileName, ImageVariantT *variant)
        : m_fileName(fileName),
          m_variant(variant)
      {}

      template<class ImplSpecT>
      bool apply() {
        typename FormatT::validator_t validator(m_fileName);
        if(validator.template apply<ImplSpecT>()) {
          typename FormatT::loader_t loader(m_fileName);
          auto im = ModelLayer::DomainObjects::Engine::Image::Image<ImplSpecT>();
          applyLoader(loader, im);
          (*m_variant) = std::move(im);
          return true;
        } else {
          return false;
        }
      }
    };
  }

  template<class FormatT, class ImageVariantT>
  ImageVariantMapper<FormatT, ImageVariantT>::ImageVariantMapper(
    Common::Data::Adapters::IFilesystemAdapter *filesystemAdapter
  )
    : m_filesystemAdapter(filesystemAdapter)
  {
  }

  template<class FormatT, class ImageVariantT>
  bool
  ImageVariantMapper<FormatT, ImageVariantT>::has(std::string fileSpec) {
    Common::Data::Adapters::FilesystemKey fsk(fileSpec, 0, 0);
    return m_filesystemAdapter->exist(fsk);
  }

  template<class FormatT, class ImageVariantT>
  void
  ImageVariantMapper<FormatT, ImageVariantT>::create(
    std::string fileSpec,
    const ImageVariantT &obj)
  {
    if(has(fileSpec)) {
      throw Error::ObjectAlreadyExistsException<Error::SafeString>(fileSpec.c_str());
    }

    // Boost.GIL does not require direct interaction with the file system by us
    typename FormatT::persister_t persister(fileSpec);
    applyPersister(persister, obj);
  }

  template<class FormatT, class ImageVariantT>
  void
  ImageVariantMapper<FormatT, ImageVariantT>::retrieve(std::string fileSpec, ImageVariantT &obj)
  {
    // Note: In this case, it is quite different to when we have a known buffer. Here, we are faced
    // with a presumably empty variant. We must figure the appropriate image type from the file
    // by validating against all possible candidates within the variant spec. This means we have
    // to do some template magic to traverse the variant type's template arguments. We replicate
    // the trick that Boost uses with boost::gil::any_image, which we unfortunately cannot use here.
    if(!has(fileSpec)) {
      throw Error::FileNotFoundException(fileSpec.c_str());
    }

    Impl::InverseValidateAndCreate<FormatT, ImageVariantT> ivac(fileSpec, &obj);
    if(!inverseApply<Impl::InverseValidateAndCreate<FormatT, ImageVariantT>, ImageVariantT>(
      ivac)) {
      throw UnsupportedSubFormatException(fileSpec.c_str());
    }
  }

  template<class FormatT, class ImageVariantT>
  void
  ImageVariantMapper<FormatT, ImageVariantT>::update(
    std::string fileSpec,
    const ImageVariantT &obj
  ) {
    if(!has(fileSpec)) {
      throw Error::ObjectNotFoundException<Error::SafeString>(fileSpec.c_str());
    }

    // Boost.GIL does not require direct interaction with the file system by us
    typename FormatT::persister_t persister(fileSpec);
    applyPersister(persister, obj);
  }

  template<class FormatT, class ImageVariantT>
  void
  ImageVariantMapper<FormatT, ImageVariantT>::deleteO(std::string fileSpec) {
    throw "NOT YET IMPLEMENTED";
  }
}

#endif
