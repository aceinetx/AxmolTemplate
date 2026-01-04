#include "Utility.h"

auto Utility::transformOpacity(float opacity) -> uint8_t {
  return (uint8_t)(255.0f * opacity);
}

auto Utility::transformOpacity(uint8_t opacity) -> float {

  return (float)opacity / 255.0f;
}
