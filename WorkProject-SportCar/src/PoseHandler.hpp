#pragma once
#include "Executor.hpp"
namespace adas
{
class PoseHandler final
{
public:
    PoseHandler(const Pose& pose) noexcept;
    PoseHandler(const PoseHandler&) = delete;
    PoseHandler& operator=(const PoseHandler&) = delete;

public:
    // 转弯和移动指令中移动的距离不同，修改移动逻辑，通过设置参数来调整

    void Forward(int x) noexcept;   // M
    void Backward(int x) noexcept;  // BM
    void TurnLeft(void) noexcept;   // L
    void TurnRight(void) noexcept;  // R
    void Fast(void) noexcept;       // F
    bool IsFast(void) const noexcept;
    Pose Query(void) const noexcept;
    void Reverse(void) noexcept;  // B
    bool IsReverse(void) const noexcept;

private:
    Pose pose;
    bool fast{false};
    bool reverse{false};
};
}  // namespace adas