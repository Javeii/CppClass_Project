#include "ExecutorImpl.hpp"

#include <memory>
#include <unordered_map>

#include "CmderFactory.hpp"
#include "Command.hpp"
#include "Singleton.hpp"

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
    // const std::unordered_map<char, std::function<void(PoseHandler & posehandler)>> cmderMap{
    //     {'M', MoveCommand()}, {'L', TurnLeftCommand()}, {'R', TurnRightCommand()},
    //     {'F', FastCommand()}, {'B', ReverseCommand()},
    // };

    // for (const auto cmd : commands) {
    //     const auto it = cmderMap.find(cmd);

    //     if (it != cmderMap.end()) {
    //         it->second(posehandler);
    //     }
    // }
    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);

    std::for_each(cmders.begin(), cmders.end(), [this](const Cmder& cmder) noexcept { cmder(posehandler); });
}
Pose ExecutorImpl::Query() const noexcept
{
    return posehandler.Query();
}
}  // namespace adas
