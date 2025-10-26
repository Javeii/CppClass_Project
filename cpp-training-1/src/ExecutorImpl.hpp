// 定义子类implement
#pragma once
#include "Executor.hpp"
#include "PoseHandler.hpp"

namespace adas
{
class ExecutorImpl final : public Executor
{
public:
    explicit ExecutorImpl(const Pose& pose) noexcept;
    ~ExecutorImpl() noexcept = default;
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;

public:
    // override显式声明重写，避免拼写错误
    // 重写父类的纯虚函数；执行指令
    void Execute(const std::string& command) noexcept override;
    // （重写）查询状态
    Pose Query(void) const noexcept override;

private:
    // “最小可见原则”
    PoseHandler posehandler;
};
}  // namespace adas