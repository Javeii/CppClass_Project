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
        if (command == 'M') {
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
    }
}
Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}

}  // namespace adas
