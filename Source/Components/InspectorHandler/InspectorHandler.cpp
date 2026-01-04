#include "InspectorHandler.h"
#include "Inspector/Inspector.h"
#include "Logging.h"
#include "Utils.h"
#include "base/Director.h"

auto ax::InspectorHandler::init() -> bool {
  if (!Node::init())
    return false;
  m_didOpen = false;

  return true;
}

void ax::InspectorHandler::onEnterTransitionDidFinish() {
  Node::onEnterTransitionDidFinish();

  scheduleOnce(
      [this](float) -> void {
        ax::extension::Inspector::getInstance()->openForCurrentScene();
        m_didOpen = true;
      },
      0.5f, "inspectorSchedule");
}

void ax::InspectorHandler::onExit() {
  Node::onExit();

  if (m_didOpen) {
    ax::extension::Inspector::getInstance()->close();
  }
}

auto ax::InspectorHandler::create() -> ax::InspectorHandler * {
  return ax::utils::createInstance<ax::InspectorHandler>();
}
