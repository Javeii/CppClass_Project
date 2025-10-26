#include "ExecutorImpl.hpp"

#include <memory>

#include "Command.hpp"

namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}
ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : posehandler(pose)
{
}
void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    for (char command : commands) {
        std::unique_ptr<ICommand> cmder;
        if (command == 'M') {  // Move();
            cmder = std::make_unique<MoveCommand>();
        }
        if (command == 'L') {  // TurnLeft();
            cmder = std::make_unique<TurnLeftCommand>();
        }
        if (command == 'R') {  // TurnRight();
            cmder = std::make_unique<TurnRightCommand>();
        }
        if (command == 'F') {  // Fast();
            cmder = std::make_unique<FastCommand>();
        }

        if (cmder) {
            cmder->DoOperate(posehandler);
        }
    }
}
Pose ExecutorImpl::Query() const noexcept
{
    return posehandler.Query();
}
}  // namespace adas
