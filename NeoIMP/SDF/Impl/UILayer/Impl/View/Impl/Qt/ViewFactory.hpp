#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_VIEWFACTORY_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_VIEWFACTORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewFactory.hpp
 * PURPOSE: The Qt-based view factory.
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

#include <SDF/Impl/UILayer/Impl/View/IViewFactory.hpp>

#include <fruit/fruit.h>
#include <memory>

namespace SDF::Impl::UILayer {
  namespace AbstractAppModel {
    namespace Actions {
      class ICreateDocumentAction;
      class ISaveDocumentAsAction;
      class IOpenDocumentAction;
      class ISetFocusDocumentAction;
    }

    namespace State {
      class IOpenDocumentsAppModel;
    }
  }

  namespace Impl {
    class IUIControl;

    namespace Controller {
      class ControllerFactory;
    }

    namespace View {
      class IViewSink;

      class IApplicationView;
      class INewDocumentView;
      class ISaveDocumentView;
      class IOpenDocumentView;
      class IDocumentView;

      namespace Impl::Qt {
        class ViewFactory : public IViewFactory {
        public:
          INJECT(ViewFactory(IViewSink *viewSink,
                             AbstractAppModel::Actions::ICreateDocumentAction *createDocumentAction,
                             AbstractAppModel::Actions::ISaveDocumentAsAction *saveDocumentAsAction,
                             AbstractAppModel::Actions::IOpenDocumentAction *openDocumentAction,
                             AbstractAppModel::Actions::ISetFocusDocumentAction *setFocusDocumentAction,
                             AbstractAppModel::State::IOpenDocumentsAppModel *openDocumentsAppModel
                            ));
          ~ViewFactory();

          std::unique_ptr<IApplicationView> createApplicationView(IUIControl *uiControl);
          std::unique_ptr<INewDocumentView> createNewDocumentView();
          std::unique_ptr<ISaveDocumentView> createSaveDocumentView();
          std::unique_ptr<IOpenDocumentView> createOpenDocumentView();
          std::unique_ptr<IDocumentView> createDocumentView(AbstractAppModel::Handle handle);
        private:
          IViewSink *m_viewSink;

          AbstractAppModel::Actions::ICreateDocumentAction *m_createDocumentAction;
          AbstractAppModel::Actions::ISaveDocumentAsAction *m_saveDocumentAsAction;
          AbstractAppModel::Actions::IOpenDocumentAction *m_openDocumentAction;
          AbstractAppModel::Actions::ISetFocusDocumentAction *m_setFocusDocumentAction;

          AbstractAppModel::State::IOpenDocumentsAppModel *m_openDocumentsAppModel;
        };
      }
    }
  }
}

#endif
