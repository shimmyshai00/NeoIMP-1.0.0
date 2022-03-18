#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_SERVICEDEPS_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_SERVICEDEPS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ServiceDeps.hpp
 * PURPOSE: Defines the DI model layer service dependencies for the Qt-based view subsystem.
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

#include "../../../AbstractModel/Create/IGetDocumentPrefabService.hpp"
#include "../../../AbstractModel/Create/IGetMemoryRequirementsService.hpp"
#include "../../../AbstractModel/Create/ICreateDocumentService.hpp"
#include "../../../AbstractModel/Metrics/IConvertLengthService.hpp"
#include "../../../AbstractModel/Metrics/IConvertResolutionService.hpp"
#include "../../../AbstractModel/Metrics/IGetDocumentDimensionsService.hpp"
#include "../../../AbstractModel/Storage/ISaveDocumentService.hpp"
#include "../../../AbstractModel/Viewing/IAddViewService.hpp"
#include "../../../AbstractModel/Viewing/IGetViewCoordinatesService.hpp"
#include "../../../AbstractModel/Viewing/ISetViewXCoordinateService.hpp"
#include "../../../AbstractModel/Viewing/ISetViewYCoordinateService.hpp"
#include "../../../AbstractModel/Viewing/ISetViewCoordinatesService.hpp"
#include "../../../AbstractModel/Viewing/IRenderingService.hpp"
#include "../../../AbstractModel/Editing/IGetActiveDocumentService.hpp"
#include "../../../AbstractModel/Editing/ISetActiveDocumentService.hpp"
#include "../../../AbstractModel/Editing/IGetDocumentNameService.hpp"

#include <fruit/fruit.h>

namespace SDF::Editor::UILayer::Gui::View::Qt {
  // nb: factorize some into controller unit as a separate module?
  typedef fruit::Required<
    AbstractModel::Create::IGetDocumentPrefabService,
    AbstractModel::Create::IGetMemoryRequirementsService,
    AbstractModel::Create::ICreateDocumentService,
    AbstractModel::Metrics::IConvertLengthService,
    AbstractModel::Metrics::IConvertResolutionService,
    AbstractModel::Metrics::IGetDocumentDimensionsService,
    AbstractModel::Storage::ISaveDocumentService,
    AbstractModel::Viewing::IAddViewService,
    AbstractModel::Viewing::IGetViewCoordinatesService,
    AbstractModel::Viewing::ISetViewXCoordinateService,
    AbstractModel::Viewing::ISetViewYCoordinateService,
    AbstractModel::Viewing::ISetViewCoordinatesService,
    AbstractModel::Viewing::IRenderingService,
    AbstractModel::Editing::IGetActiveDocumentService,
    AbstractModel::Editing::ISetActiveDocumentService,
    AbstractModel::Editing::IGetDocumentNameService
  > ServiceDeps;
}

#endif
