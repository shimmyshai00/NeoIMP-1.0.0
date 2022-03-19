#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWMANAGER_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWMANAGER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewManager.hpp
 * PURPOSE: Defines the ViewManager class.
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

#include "../../../../../Common/Handle.hpp"
#include "../../../AbstractModel/Editing/IGetDocumentNameService.hpp"
#include "../../../Support/Bundle.hpp"
#include "../../IViewManager.hpp"
#include "../EViewType.hpp"

#include "ViewFactory.hpp"
#include "MainWindow.hpp"

#include <QWidget>

#include <fruit/fruit.h>
#include <map>

namespace SDF::Editor::UILayer::Gui::View::Qt {
  // Class:      ViewManager
  // Purpose:    Defines the view manager for the Qt-based GUI.
  // Parameters: None.
  class ViewManager : public IViewManager<EViewType> {
  public:
    INJECT(ViewManager(
      AbstractModel::Editing::IGetDocumentNameService *documentNameService,
      ViewFactory *viewFactory
    ));
    ~ViewManager();

    Common::Handle
    produceView(EViewType viewType, std::shared_ptr<Support::Bundle> argBundle);

    void
    destroyView(Common::Handle viewHandle);

    void
    destroyAllOfType(EViewType viewType);

    void
    destroyAll();
  private:
    AbstractModel::Editing::IGetDocumentNameService *m_documentNameService;

    std::map<Common::Handle, QWidget *> m_views;
    ViewFactory *m_viewFactory;
    Common::Handle m_nextDocumentViewHandle;

    Common::Handle addViewIfNotPresent(Common::Handle handle, QWidget *view);
  };
}

#endif
