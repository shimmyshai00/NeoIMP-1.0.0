#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_QTEVENT_TPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_QTEVENT_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    QtEvent.tpp
 * PURPOSE: Implements the Event template.
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

#include "../../../../../Error/Exception.hpp"
#include "../../../../../Error/DataException.hpp"
#include "../../../../../Error/ModelException.hpp"
#include "../../../../../Error/GeneralException.hpp"

#include <iostream>

#include <QMessageBox>

namespace SDF::Editor::UILayer::Gui::View::Qt::Impl {
  template<class ... ControllerArgs>
  class QtEventConn : public Common::IConnection {
  public:
    QtEventConn(
      std::list<std::unique_ptr<IController<ControllerArgs...>>> *controllerList,
      std::unique_ptr<IController<ControllerArgs...>> controller
    )
      : m_controllerList(controllerList),
        m_controller(std::move(controller)),
        m_controllerPtr(nullptr)
    {
    }

    void
    connect() {
      if(m_controllerPtr == nullptr) {
        m_controllerPtr = m_controller.get();
        m_controllerList->push_back(std::move(m_controller));
      }
    }

    void
    disconnect() {
      if(m_controllerPtr != nullptr) {
        for(typename std::list<std::unique_ptr<IController<ControllerArgs...>>>::iterator
          it(m_controllerList->begin()); it != m_controllerList->end(); ++it)
        {
          if(it->get() == m_controllerPtr) {
            m_controller = std::move(*it);
            m_controllerList->erase(it);

            m_controllerPtr = nullptr;
          }
        }
      }
    }
  private:
    std::list<std::unique_ptr<IController<ControllerArgs...>>> *m_controllerList;
    std::unique_ptr<IController<ControllerArgs...>> m_controller;
    IController<ControllerArgs...> *m_controllerPtr;
  };
}

namespace SDF::Editor::UILayer::Gui::View::Qt {
  template<class ... ControllerArgs>
  QtEvent<ControllerArgs...>::QtEvent() {
  }

  template<class ... ControllerArgs>
  Common::PIConnection
  QtEvent<ControllerArgs...>::hook(std::unique_ptr<IController<ControllerArgs...>> controller) {
    return Common::PIConnection(new Impl::QtEventConn<ControllerArgs...>(
      &m_controllers, std::move(controller)));
  }

  template<class ... ControllerArgs>
  void
  QtEvent<ControllerArgs...>::trigger(ControllerArgs... args) {
    for(typename std::list<std::unique_ptr<IController<ControllerArgs...>>>::iterator
      it(m_controllers.begin()); it != m_controllers.end(); ++it)
    {
      using namespace SDF::Error;

      bool caughtError(false);
      QString guiErrorMessage = QString("ERROR: ");
      QString likelyBugMessage = QString("\nThis likely means there is a bug in the program!");

      try {
        (*it)->onTrigger(args...);
      } catch(General<DataException> &e) { // nb: seems a lot of duplication
        guiErrorMessage += QString::fromStdString(e.what());
        caughtError = true;
      } catch(LikelyBug<DataException> &e) {
        guiErrorMessage += QString::fromStdString(e.what()) + likelyBugMessage;
        caughtError = true;
      } catch(General<ModelException> &e) {
        guiErrorMessage += QString::fromStdString(e.what());
        caughtError = true;
      } catch(LikelyBug<ModelException> &e) {
        guiErrorMessage += QString::fromStdString(e.what()) + likelyBugMessage;
        caughtError = true;
      } catch(General<GeneralException> &e) {
        guiErrorMessage += QString::fromStdString(e.what());
        caughtError = true;
      } catch(LikelyBug<GeneralException> &e) {
        guiErrorMessage += QString::fromStdString(e.what()) + likelyBugMessage;
        caughtError = true;
      }

      if(caughtError) {
        std::cerr << guiErrorMessage.toStdString() << std::endl;
        auto mb = new QMessageBox(QMessageBox::Warning, QString("Error"), guiErrorMessage,
          QMessageBox::Ok);
        mb->show();
      }
    }
  }
}

#endif
