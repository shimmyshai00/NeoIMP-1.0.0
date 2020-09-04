#ifndef SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_CDOCUMENT_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_CDOCUMENT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CDocument.hpp
 * PURPOSE: Definition of the document class.
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

#include <SDF/Exception.hpp>

#include <Spec/EColorModel.hpp>
#include <Spec/EBitDepth.hpp>

#include <Impl/DomainObjects/Metrics/Length/Quantity.hpp>
#include <Impl/DomainObjects/Metrics/Resolution/Quantity.hpp>

#include <vector>
#include <memory>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects {
        namespace Pixel {
          class IPixelVisitor;
        }

        class CLayer;

        class CDocument {
        public:
          CDocument(int width, int height,
            Metrics::Resolution::Quantity resolution,
            Spec::EColorModel colorModel, Spec::EBitDepth bitDepth);
          CDocument(Metrics::Length::Quantity widthPhys, Metrics::Length::Quantity heightPhys,
            Metrics::Resolution::Quantity resolution,
            Spec::EColorModel colorModel, Spec::EBitDepth bitDepth);
          CDocument(int width, Metrics::Length::Quantity heightPhys,
            Metrics::Resolution::Quantity resolution,
            Spec::EColorModel colorModel, Spec::EBitDepth bitDepth);
          CDocument(Metrics::Length::Quantity widthPhys, int height,
            Metrics::Resolution::Quantity resolution,
            Spec::EColorModel colorModel, Spec::EBitDepth bitDepth);
          ~CDocument();

          int getDocumentWidthPx() const;
          int getDocumentHeightPx() const;

          Metrics::Length::Quantity getDocumentWidthPhys() const;
          Metrics::Length::Quantity getDocumentHeightPhys() const;
          Metrics::Resolution::Quantity getDocumentResolution() const;

          Spec::EColorModel getDocumentColorModel() const;
          Spec::EBitDepth getDocumentBitDepth() const;

          int getNumLayers() const;

          void createNewLayer(int layerWidthPx, int layerHeightPx);
          void createNewLayer(Metrics::Length::Quantity layerWidthPhys, Metrics::Length::Quantity layerHeightPhys);

          void visitPixel(int layerNum, int x, int y, Pixel::IPixelVisitor &vis);
        public:
          static constexpr int c_maxDocumentWidthPx = 1048576; // 1 Tpx max size
          static constexpr int c_maxDocumentHeightPx = 1048576;
        public:
          struct BadDocumentSizeException : public SDF::Exception {
            BadDocumentSizeException(int width, int height)
            : Exception("INTERNAL ERROR: Tried to create a document with bad (zero or negative) size %d px x %d px", width, height)
            {
            }
          };

          struct DocumentSizeTooBigException : public SDF::Exception {
            DocumentSizeTooBigException(int width, int height)
            : Exception("INTERNAL ERROR: Requested creation of a document of size %d px x %d px, which is too big (max: %d px x %d px)", width, height, c_maxDocumentWidthPx, c_maxDocumentHeightPx)
            {
            }
          };

          struct LayerNotFoundException : public SDF::Exception {
            LayerNotFoundException(int layerNum, int numLayers)
            : Exception("INTERNAL ERROR: Tried to access a layer with index %d that is negative or does not exist (there are only %d layers in the document)", layerNum, numLayers)
            {
            }
          };

          struct OutOfBoundsException : public SDF::Exception {
            OutOfBoundsException(int layerNum, int x, int y)
            : Exception("INTERNAL ERROR: Tried to access a pixel in layer %d at coordinates (%d, %d) which are out of layer bounds", layerNum, x, y)
            {
            }
          };
        private:
          int m_documentWidthPx;
          int m_documentHeightPx;

          Metrics::Length::Quantity m_documentWidthPhys;
          Metrics::Length::Quantity m_documentHeightPhys;
          Metrics::Resolution::Quantity m_documentResolution;

          Spec::EColorModel m_colorModel;
          Spec::EBitDepth m_bitDepth;

          // This stack of layers is ordered topmost first.
          std::vector<std::unique_ptr<CLayer>> m_layerStack;
        };
      }
    }
  }
}

#endif
