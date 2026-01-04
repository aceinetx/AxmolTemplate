#include "Utility.h"
#include "base/Director.h"

namespace aceinetx::utils
{
auto transformOpacity(float opacity) -> uint8_t
{
  return (uint8_t)(255.0f * opacity);
}

auto transformOpacity(uint8_t opacity) -> float
{
  return (float)opacity / 255.0f;
}

auto unprojectGL(ax::Camera* camera, ax::Point p, float z) -> ax::Vec3
{
  auto pointNear = ax::Vec3(p.x, p.y, 0);
  auto pointFar  = ax::Vec3(p.x, p.y, 1);

  pointNear = camera->unprojectGL(pointNear);
  pointFar  = camera->unprojectGL(pointFar);

  auto x0 = pointNear.x;
  auto y0 = pointNear.y;
  auto z0 = pointNear.z;

  auto x1 = pointFar.x;
  auto y1 = pointFar.y;
  auto z1 = pointFar.z;

  auto x = (((z - z0) / (z1 - z0)) * (x1 - x0)) + x0;
  auto y = (((z - z0) / (z1 - z0)) * (y1 - y0)) + y0;

  return {x, y, z};
}

auto unprojectGL(ax::Camera* camera, ax::Point p) -> ax::Vec2
{
  ax::Vec3 pos = unprojectGL(camera, p, 0);
  return {pos.x, pos.y};
}

void followCamera(ax::Camera* camera, ax::Node* node, ax::Vec2 diff)
{
  static auto* director = ax::Director::getInstance();
  auto winSize          = director->getVisibleSize();

  node->setScale(camera->getZoom());
  node->setPosition(camera->getPosition() - winSize / 2 * camera->getZoom() + diff * camera->getZoom());
}

void followCamera(ax::Node* node, ax::Vec2 diff)
{
  static auto* director = ax::Director::getInstance();
  auto camera           = director->getRunningScene()->getDefaultCamera();
  auto winSize          = director->getVisibleSize();

  node->setScale(camera->getZoom());
  node->setPosition(camera->getPosition() - winSize / 2 * camera->getZoom() + diff * camera->getZoom());
}
}  // namespace aceinetx::utils
