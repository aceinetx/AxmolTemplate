#pragma once
#include "2d/Node.h"

namespace ax {
class InspectorHandler : public ax::Node {
public:
  auto init() -> bool override;

  void onEnterTransitionDidFinish() override;
  void onExit() override;

  static auto create() -> InspectorHandler *;

private:
  bool m_didOpen;
};
} // namespace ax
