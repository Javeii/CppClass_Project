#include "PoseHandler.hpp"

namespace adas
{
PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose)
{
}
void PoseHandler::Forward() noexcept
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
    default:
        break;
    }
}
void PoseHandler::Backward() noexcept
{
    switch (pose.heading) {
    case 'N':
        pose.y -= 1;
        break;
    case 'S':
        pose.y += 1;
        break;
    case 'E':
        pose.x -= 1;
        break;
    case 'W':
        pose.x += 1;
        break;
    default:
        break;
    }
}

// 车长为2 转弯以车中心为轴 修改转弯逻辑

void PoseHandler::TurnLeft() noexcept
{
    switch (pose.heading) {
    case 'N':
        pose.heading = 'W';
        pose.x--;
        pose.y--;
        break;
    case 'S':
        pose.heading = 'E';
        pose.x++;
        pose.y++;
        break;
    case 'E':
        pose.heading = 'N';
        pose.x--;
        pose.y++;
        break;
    case 'W':
        pose.heading = 'S';
        pose.x++;
        pose.y--;
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
        pose.x++;
        pose.y--;
        break;
    case 'S':
        pose.heading = 'W';
        pose.x--;
        pose.y++;
        break;
    case 'E':
        pose.heading = 'S';
        pose.x--;
        pose.y--;
        break;
    case 'W':
        pose.heading = 'N';
        pose.x++;
        pose.y++;
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
