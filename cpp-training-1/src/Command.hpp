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
    //          executor.Forward();
    //      }
    //     executor.Forward();
    // }
public:
    void operator()(PoseHandler& posehandler) const noexcept
    {
        if (posehandler.IsFast()) {
            if (posehandler.IsReverse()) {
                posehandler.Backward();
            } else {
                posehandler.Forward();
            }
        }

        if (posehandler.IsReverse()) {
            posehandler.Backward();
        } else {
            posehandler.Forward();
        }
    }
};
class TurnLeftCommand final  // : public ICommand
{
public:
    // void DoOperate(PoseHandler& executor) const noexcept override
    // {
    //     if (executor.IsFast()) {
    //         executor.Forward();
    //     }
    //     executor.TurnLeft();
    // }
    void operator()(PoseHandler& posehandler) const noexcept
    {
        if (posehandler.IsFast()) {
            if (posehandler.IsReverse()) {
                posehandler.Backward();
            } else {
                posehandler.Forward();
            }
        }

        if (posehandler.IsReverse()) {
            posehandler.TurnRight();
        } else {
            posehandler.TurnLeft();
        }
    };
};
class TurnRightCommand final  // : public ICommand
{
public:
    // void DoOperate(PoseHandler& executor) const noexcept override
    // {
    //     if (executor.IsFast()) {
    //         executor.Forward();
    //     }
    //     executor.TurnRight();
    // }
    void operator()(PoseHandler& posehandler) const noexcept
    {
        if (posehandler.IsFast()) {
            if (posehandler.IsReverse()) {
                posehandler.Backward();
            } else {
                posehandler.Forward();
            }
        }
        if (posehandler.IsReverse()) {
            posehandler.TurnLeft();
        } else {
            posehandler.TurnRight();
        }
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
class ReverseCommand final
{
public:
    void operator()(PoseHandler& posehandler) const noexcept
    {
        posehandler.Reverse();
    }
};
}  // namespace adas