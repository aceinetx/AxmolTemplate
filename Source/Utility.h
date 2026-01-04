#pragma once
#include <cstdint>

namespace Utility {
auto transformOpacity(uint8_t opacity) -> float;
auto transformOpacity(float opacity) -> uint8_t;
} // namespace Utility
