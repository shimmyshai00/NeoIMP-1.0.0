#ifndef SDF_MODELLAYER_SERVICES_DOCUMENTRENDERSERVICE_HPP
#define SDF_MODELLAYER_SERVICES_DOCUMENTRENDERSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentRenderService.hpp
 * PURPOSE: Defines the DocumentRenderService class.
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

#include <SDF/UILayer/AbstractModel/IDocumentRenderService.hpp>
#include <SDF/UILayer/AbstractModel/Handle.hpp>

#include <SDF/Interfaces/IFactory.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/Algorithms/Annotations.hpp>

#include <fruit/fruit.h>
#include <memory>

namespace SDF::ModelLayer {
  namespace AbstractData {
    template<class T>
    class IRepository;
  }

  namespace Services {
    namespace AbstractDomain {
      class IImage;
      class IImageDataVisitor;
      class IRenderBuffer;
    }

    // Class:      DocumentRenderService
    // Purpose:    Provides the model layer service for rendering documents.
    // Parameters: None.
    class DocumentRenderService : public UILayer::AbstractModel::IDocumentRenderService {
    public:
      INJECT(DocumentRenderService(AbstractData::IRepository<AbstractDomain::IImage> *imageRepository,
                                   AbstractData::IRepository<AbstractDomain::IRenderBuffer> *renderingsRepository,
                                   ANNOTATED(AbstractDomain::Algorithms::RendererAlgorithm,
                                             Interfaces::IFactory<AbstractDomain::IImageDataVisitor,
                                                                  AbstractDomain::IRenderBuffer *
                                                                 > *) algorithmFactory,
                                   ANNOTATED(AbstractDomain::Algorithms::RGB32Buffer,
                                            Interfaces::IFactory<AbstractDomain::IRenderBuffer,
                                                                 std::size_t,
                                                                 std::size_t> *)
                                    renderBufferFactory
                                  ));

      UILayer::AbstractModel::Handle
      renderImage(UILayer::AbstractModel::Handle imageHandle);

      void
      getRenderedRegion(const unsigned char *&origin,
                        std::ptrdiff_t &rowStride,
                        UILayer::AbstractModel::Handle renderingHandle,
                        int x1, int y1, int x2, int y2
                       );
    private:
      AbstractData::IRepository<AbstractDomain::IImage> *m_imageRepository;
      AbstractData::IRepository<AbstractDomain::IRenderBuffer> *m_renderingsRepository;

      Interfaces::IFactory<AbstractDomain::IImageDataVisitor, AbstractDomain::IRenderBuffer *> *m_algorithmFactory;
      Interfaces::IFactory<AbstractDomain::IRenderBuffer, std::size_t, std::size_t> *m_renderBufferFactory;
    };
  }
}

#endif
