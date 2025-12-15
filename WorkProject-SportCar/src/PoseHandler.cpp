#include "PoseHandler.hpp"

namespace adas
{
PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose)
{
}
void PoseHandler::Forward(int x) noexcept
{
    switch (pose.heading) {
    case 'N':
        pose.y += x;
        break;
    case 'S':
        pose.y -= x;
        break;
    case 'E':
        pose.x += x;
        break;
    case 'W':
        pose.x -= x;
        break;
    default:
        break;
    }
}
void PoseHandler::Backward(int x) noexcept
{
    switch (pose.heading) {
    case 'N':
        pose.y -= x;
        break;
    case 'S':
        pose.y += x;
        break;
    case 'E':
        pose.x -= x;
        break;
    case 'W':
        pose.x += x;
        break;
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
void PoseHandler::Reverse() noexcept
{
    reverse = !reverse;
}
bool PoseHandler::IsReverse() const noexcept
{
    return reverse;
}
}  // namespace adas
