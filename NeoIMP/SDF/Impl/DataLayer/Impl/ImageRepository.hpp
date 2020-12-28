#ifndef SDF_IMPL_DATALAYER_IMPL_IMAGEREPOSITORY_HPP
#define SDF_IMPL_DATALAYER_IMPL_IMAGEREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageRepository.hpp
 * PURPOSE: Implementation of the image repository. This provides both an in-memory cache and facilities to write to
 *          persistent storage.
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

#include <SDF/Impl/ModelLayer/AbstractData/IImageRepository.hpp>
#include <SDF/Impl/ModelLayer/AbstractData/IImageFileMap.hpp>

#include <fruit/fruit.h>
#include <memory>
#include <map>

namespace SDF::Impl::DataLayer::Impl {
  class ImageRepository : public ModelLayer::AbstractData::IImageRepository,
    public ModelLayer::AbstractData::IImageFileMap {
  public:
    INJECT(ImageRepository());

    void add(
      std::unique_ptr<Framework::IMVCDomainObject<ModelLayer::Impl::DomainObjects::Image::AbstractImage>> object
    );

    std::unique_ptr<Framework::IMVCDomainObject<ModelLayer::Impl::DomainObjects::Image::AbstractImage>> retrieve(
      Framework::Handle handle
    );
    Framework::IMVCDomainObject<ModelLayer::Impl::DomainObjects::Image::AbstractImage> *retrieveNonOwning(
      Framework::Handle handle
    );

    void update(
      std::unique_ptr<Framework::IMVCDomainObject<ModelLayer::Impl::DomainObjects::Image::AbstractImage>> object
    );
    void remove(Framework::Handle handle);

    void addBinding(
      Framework::Handle handle,
      std::string fileName, UILayer::AbstractModel::Properties::FileFormat fileFormat
    );

    void removeBinding(Framework::Handle handle);
  private:
    std::map<Framework::Handle,
      std::unique_ptr<Framework::IMVCDomainObject<ModelLayer::Impl::DomainObjects::Image::AbstractImage>>>
      m_domainObjectMap;

    std::map<Framework::Handle, std::string> m_fileNameMap;
    std::map<Framework::Handle, UILayer::AbstractModel::Properties::FileFormat> m_fileFormatMap;
  };
}

#endif
