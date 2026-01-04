#pragma once
#include <cstdint>
#include "2d/Camera.h"

namespace aceinetx::utils
{
auto transformOpacity(uint8_t opacity) -> float;
auto transformOpacity(float opacity) -> uint8_t;

auto unprojectGL(ax::Camera* camera, ax::Point p, float z) -> ax::Vec3;
auto unprojectGL(ax::Camera* camera, ax::Point p) -> ax::Vec2;

void followCamera(ax::Camera* camera, ax::Node* node, ax::Vec2 diff = ax::Vec2(0, 0));
void followCamera(ax::Node* node, ax::Vec2 diff = ax::Vec2(0, 0));
}  // namespace aceinetx::utils
