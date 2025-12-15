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
                posehandler.Backward(2);
            } else {
                posehandler.Forward(2);
            }
        }

        if (posehandler.IsReverse()) {
            posehandler.Backward(2);
        } else {
            posehandler.Forward(2);
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
                posehandler.Backward(1);
            } else {
                posehandler.Forward(1);
            }
        }

        if (posehandler.IsReverse()) {
            posehandler.TurnRight();
            posehandler.Backward(1);
        } else {
            posehandler.TurnLeft();
            posehandler.Forward(1);
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
                posehandler.Backward(1);
            } else {
                posehandler.Forward(1);
            }
        }
        if (posehandler.IsReverse()) {
            posehandler.TurnLeft();
            posehandler.Backward(1);
        } else {
            posehandler.TurnRight();
            posehandler.Forward(1);
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