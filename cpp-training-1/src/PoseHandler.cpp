#include "PoseHandler.hpp"

namespace adas
{
PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose)
{
}
void PoseHandler::Move() noexcept
{
    switch (pose.heading) {
    case 'N':
        pose.y += 1;
        break;
    case 'S':
        pose.y -= 1;
        break;
    case 'E':
        pose.x += 1;
        break;
    case 'W':
        pose.x -= 1;
        break;
    // 默认情况可以处理未知方向
    default:
        break;
    }
}
void PoseHandler::TurnLeft() noexcept
{
    switch (pose.heading) {
    case 'N':
        pose.heading = 'W';
        break;
    case 'S':
        pose.heading = 'E';
        break;
    case 'E':
        pose.heading = 'N';
        break;
    case 'W':
        pose.heading = 'S';
        break;
    default:
        break;
    }
}
void PoseHandler::TurnRight() noexcept
{
    switch (pose.heading) {
    case 'N':
        pose.heading = 'E';
        break;
    case 'S':
        pose.heading = 'W';
        break;
    case 'E':
        pose.heading = 'S';
        break;
    case 'W':
        pose.heading = 'N';
        break;
    default:
        break;
    }
}
void PoseHandler::Fast() noexcept
{
    fast = !fast;
}
bool PoseHandler::IsFast() const noexcept
{
    return fast;
}
Pose PoseHandler::Query() const noexcept
{
    return pose;
}
}  // namespace adas
