#pragma once
#include <functional>

#include "PoseHandler.hpp"
namespace adas
{
// class ICommand
// {
// public:
//     virtual ~ICommand() = default;
//     virtual void DoOperate(PoseHandler& executor) const noexcept = 0;
// };
class MoveCommand final  // : public ICommand
{
    // public:
    //  void DoOperate(PoseHandler& executor) const noexcept override
    //  {
    //      if (executor.IsFast()) {
    //          executor.Move();
    //      }

    //     executor.Move();
    // }
public:
    void operator()(PoseHandler& posehandler) const noexcept
    {
        if (posehandler.IsFast()) {
            posehandler.Move();
        }

        posehandler.Move();
    }
};
class TurnLeftCommand final  // : public ICommand
{
public:
    // void DoOperate(PoseHandler& executor) const noexcept override
    // {
    //     if (executor.IsFast()) {
    //         executor.Move();
    //     }

    //     executor.TurnLeft();
    // }
    void operator()(PoseHandler& posehandler) const noexcept
    {
        if (posehandler.IsFast()) {
            posehandler.Move();
        }

        posehandler.TurnLeft();
    };
};
class TurnRightCommand final  // : public ICommand
{
public:
    // void DoOperate(PoseHandler& executor) const noexcept override
    // {
    //     if (executor.IsFast()) {
    //         executor.Move();
    //     }

    //     executor.TurnRight();
    // }
    void operator()(PoseHandler& posehandler) const noexcept
    {
        if (posehandler.IsFast()) {
            posehandler.Move();
        }

        posehandler.TurnRight();
    };
};
class FastCommand final  // : public ICommand
{
public:
    // void DoOperate(PoseHandler& executor) const noexcept override
    // {
    //     executor.Fast();
    //
    void operator()(PoseHandler& posehandler) const noexcept
    {
        posehandler.Fast();
    };
};
}  // namespace adas