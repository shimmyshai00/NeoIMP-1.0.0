#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWPRODUCERS_MAINWINDOWPRODUCER_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWPRODUCERS_MAINWINDOWPRODUCER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainWindowProducer.hpp
 * PURPOSE: Defines the MainWindowProducer class.
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

#include "../../../../../../Common/Model/ServicePack.hpp"
#include "../../../../../../Common/IConnection.hpp"

#include "../../../../AbstractModel/DocumentMgmt/IDocumentAddedService.hpp"
#include "../../../../AbstractModel/Storage/IGetDocumentFileInfoService.hpp"

#include "../../../Controller/IViewProducer.hpp"
#include "../../../Controller/IGuiDismisser.hpp"

#include "../Views/MainWindow.hpp"

#include "AProducerNode.hpp"
#include "NewDocumentDialogProducer.hpp"
#include "DocumentViewProducer.hpp"
#include "FileDialogProducer.hpp"

#include <fruit/fruit.h>

#include <QPointer>

namespace SDF::Editor::UILayer::Gui::View::Qt::ViewProducers {
  // Class:      MainWindowProducer
  // Purpose:    Produces the main window. The view producers form a hierarchical structure which
  //             mirrors and encodes the compositional layout of the GUI, because each producer
  //             will need to satisfy the requirements of its dependent's controllers - most notably
  //             the parent view - and thus the children producers which those controllers want must
  //             ultimately be spawned by the parent producer as well.
  // Parameters: None.
  class MainWindowProducer : public AProducerNode,
                             public Controller::IViewProducer<>,
                             public Controller::IGuiDismisser
  {
  public:
    typedef Common::Model::UnionPack<
      typename NewDocumentDialogProducer::deps_t,
      typename DocumentViewProducer::deps_t,
      typename FileDialogProducer::deps_t,
      Common::Model::ServicePack< // our own dependencies
        AbstractModel::DocumentMgmt::IDocumentAddedService,
        AbstractModel::Storage::IGetDocumentFileInfoService
      >
    > deps_t;
  public:
    INJECT(MainWindowProducer(deps_t a_deps));

    MainWindowProducer(const MainWindowProducer &) = delete;
    MainWindowProducer(MainWindowProducer &&) = delete;
    MainWindowProducer &operator=(const MainWindowProducer &) = delete;
    MainWindowProducer &operator=(MainWindowProducer &&) = delete;

    ~MainWindowProducer();

    QWidget *
    getViewWidget();

    void
    produceView();

    void
    dismissGui();
  private:
    deps_t m_services;

    QPointer<Views::MainWindow> m_mainWindow;

    Common::PIConnection m_documentAddedListenerConn;

    class DocumentAddedListener;
  };
}

#endif
