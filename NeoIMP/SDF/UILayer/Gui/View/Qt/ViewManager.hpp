#ifndef SDF_UILAYER_GUI_VIEW_QT_VIEWMANAGER_HPP
#define SDF_UILAYER_GUI_VIEW_QT_VIEWMANAGER_HPP

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

#include "../../../../Common/IFactory.hpp"
#include "../../../../Common/Handle.hpp"
#include "../../../Support/Bundle.hpp"
#include "../../IViewManager.hpp"
#include "../EViewType.hpp"

#include "MainWindow.hpp"

#include <QWidget>

#include <fruit/fruit.h>

namespace SDF::UILayer::Gui::View::Qt {
  // Class:      ViewManager
  // Purpose:    Defines the view manager for the Qt-based GUI.
  // Parameters: None.
  class ViewManager : public IViewManager<EViewType> {
  public:
    INJECT(ViewManager());
    ~ViewManager();

    Common::Handle
    produceView(EViewType viewType,
                std::shared_ptr<Support::Bundle> argBundle
               );

    void
    destroyView(Common::Handle viewHandle);

    void
    destroyAllOfType(EViewType viewType);

    void
    destroyAll();
  private:
    std::map<Common::Handle, QWidget *> m_views;

    template<class ViewT, class ... Args>
    Common::Handle
    produceViewIfNotPresent(Common::Handle reqHandle,
                            std::unique_ptr<Common::IFactory<ViewT, Args...>> factory,
                            Args... factoryArgs
                           );
  private:
    static const Common::Handle HANDLE_MAIN_WINDOW = 0;
  };
}

#endif
