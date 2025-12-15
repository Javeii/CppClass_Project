#pragma once
#include <functional>

#include "PoseHandler.hpp"
namespace adas
{

class MoveCommand final
{
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
class TurnLeftCommand final
{
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
            posehandler.TurnRight();
        } else {
            posehandler.Forward();
            posehandler.TurnLeft();
        }
    };
};
class TurnRightCommand final
{
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
            posehandler.TurnLeft();
        } else {
            posehandler.Forward();
            posehandler.TurnRight();
        }
    };
};
class FastCommand final
{
public:
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