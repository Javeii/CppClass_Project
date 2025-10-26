#include "ExecutorImpl.hpp"

namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}
ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : pose(pose)
{
}
void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    for (char command : commands) {
        if (command == 'M') {  // 移动指令
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
        if (command == 'L') {  // 左转指令
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
        if (command == 'R') {  // 右转指令
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
    }
}
Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}

}  // namespace adas
