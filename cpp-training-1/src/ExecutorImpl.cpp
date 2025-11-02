#include "ExecutorImpl.hpp"

#include <memory>
#include <unordered_map>

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
    // std::unordered_map<char, std::function<void(PoseHandler & posehandler)>> cmderMap;
    // cmderMap.emplace('M', MoveCommand());
    // cmderMap.emplace('L', TurnLeftCommand());
    // cmderMap.emplace('R', TurnRightCommand());
    // cmderMap.emplace('F', FastCommand());
    const std::unordered_map<char, std::function<void(PoseHandler & posehandler)>> cmderMap{
        {'M', MoveCommand()},
        {'L', TurnLeftCommand()},
        {'R', TurnRightCommand()},
        {'F', FastCommand()},
    };

    for (const auto cmd : commands) {
        const auto it = cmderMap.find(cmd);

        if (it != cmderMap.end()) {
            it->second(posehandler);
        }
    }
}
Pose ExecutorImpl::Query() const noexcept
{
    return posehandler.Query();
}
}  // namespace adas
