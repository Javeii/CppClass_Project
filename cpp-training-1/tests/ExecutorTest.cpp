#include <gtest/gtest.h>  // 引入gtest测试框架

#include <memory>  // 引入智能指针，管理Executor对象内存
#include <tuple>   // 引入tuple，简化Pose对象成员比较

#include "Executor.hpp"  // 引入接口定义

namespace adas  // 避免命名冲突
{
bool operator==(const Pose& lhs, const Pose& rhs)
{  // 为Pose定义==运算符重载，使得在测试中比较Pose对象变得简单明了， std::tie提高代码可读性
    // 用std::tie将Pose的x、y、heading成员打包为tuple对象，通过tuple比较实现结构体比较（tuple结构体用于成员变量比较）

    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
}

//测试部分
//
//    测试套件名      测试用例名，清晰地描述了预期行为和测试的条件，更容易理解测试在验证什么
TEST(ExecutorTest, should_return_init_pose_when_without_command)
{  // 测试遵循了 Arrange-Act-Assert (AAA) 模式，这是提高可读性和维护性的好习惯
    // given
    // 使用std::unique_ptr智能指针：自动释放对象内存，避免内存泄漏
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    // then
    const Pose target({0, 0, 'E'});
    // gtest断言宏，若左右值不相等则终止当前测试并报错（自验性，符合FIRST原则的Self-Validating）
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor());
    // then
    const Pose target({0, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("M");
    // then
    const Pose target({1, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    // when
    executor->Execute("M");
    // then
    const Pose target({-1, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    // when
    executor->Execute("M");
    // then
    const Pose target({0, 1, 'N'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    // when
    executor->Execute("M");
    // then
    const Pose target({0, -1, 'S'});
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas