#ifndef SDF_IMPL_UILAYER_IMPL_CONTROLLER_APPLICATION_FILECONTROLLER_HPP
#define SDF_IMPL_UILAYER_IMPL_CONTROLLER_APPLICATION_FILECONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FileController.hpp
 * PURPOSE: The controller for the file commands sub-view.
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

#include <SDF/Impl/UILayer/Impl/Framework/MVCBaseController.hpp>
#include <SDF/Impl/UILayer/Impl/Framework/IMVCObserver.hpp>

#include <SDF/Impl/UILayer/Impl/View/Events/NewCommandEvent.hpp>
#include <SDF/Impl/UILayer/Impl/View/Events/SaveAsCommandEvent.hpp>

namespace SDF::Impl::UILayer::Impl::Controller::Application {
  class FileController : public Framework::MVCBaseController,
    public Framework::IMVCObserver<View::Events::NewCommandEvent>,
    public Framework::IMVCObserver<View::Events::SaveAsCommandEvent>
  {
  public:
    FileController();
    ~FileController();

    void receiveMessage(void *sender, std::string message);

    void notify(View::Events::NewCommandEvent e);
    void notify(View::Events::SaveAsCommandEvent e);
  };
}

#endif
