#ifndef SDF_UILAYER_ABSTRACTUI_IUI_HPP
#define SDF_UILAYER_ABSTRACTUI_IUI_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IUi.hpp
 * PURPOSE: Defines the IUi interface.
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

#include <string>

namespace SDF::AbstractUi {
  // Class:      IUi
  // Purpose:    Defines the base interface for UI objects.
  // Parameters: None.
  class IUi {
  public:
    virtual ~IUi() = default;

    // Function:   setupUi
    // Purpose:    Perform any necessary initialization we don't want to do immediately upon construction.
    // Parameters: None.
    // Returns:    None.
    virtual void
    setupUi() = 0;


    // Function:   terminateUi
    // Purpose:    Closes down this UI session.
    // Parameters: None.
    // Returns:    None.
    virtual void
    terminateUi() = 0;

    // Function:   showLoadingScreen
    // Purpose:    Deploys the loading (also called "splash") screen for this UI.
    // Parameters: None.
    // Returns:    None.
    virtual void
    showLoadingScreen() = 0;

    // Function:   updateLoadingStage
    // Purpose:    Changes the status on the loading screen.
    // Parameters: loadingStageName - What to display as the current stage of program loadup.
    // Returns:    None.
    virtual void
    updateLoadingStage(std::string loadingStageName) = 0;

    // Function:   finishLoading
    // Purpose:    Completes the loading screen session.
    // Parameters: None.
    // Returns:    None.
    virtual void
    finishLoading() = 0;

    // Function:   enterMainUi
    // Purpose:    Transitions to the main UI screen (e.g. the main window, in the case of a GUI).
    // Parameters: None.
    // Returns:    None.
    virtual void
    enterMainUi() = 0;
  };
}

#endif
