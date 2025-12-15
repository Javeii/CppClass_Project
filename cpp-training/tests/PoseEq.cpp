#include "PoseEq.hpp"

#include <tuple>
namespace adas
{
bool operator==(const Pose& lhs, const Pose& rhs)
{  // 为Pose定义==运算符重载，使得在测试中比较Pose对象变得简单明了， std::tie提高代码可读性
    // 用std::tie将Pose的x、y、heading成员打包为tuple对象，通过tuple比较实现结构体比较（tuple结构体用于成员变量比较）

    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
}
}  // namespace adas
