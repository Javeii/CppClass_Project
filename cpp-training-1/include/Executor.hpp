#pragma once
#include <string>
namespace adas
{
struct Pose {
    int x;
    int y;
    char heading;
};

class Executor
{
public:
    // 初始化接口
    static Executor* NewExecutor(const Pose& pose = {0, 0, 'N'}) noexcept;

public:
    // 构造函数和析构函数采用默认实现
    Executor(void) = default;
    virtual ~Executor(void) = default;

    // 禁用拷贝构造与赋值
    Executor(const Executor&) = delete;
    Executor& operator=(const Executor&) = delete;

public:
    // 执行指令
    virtual void Execute(const std::string& command) noexcept = 0;
    // 查询当前状态
    virtual Pose Query(void) const noexcept = 0;
};

}  // namespace adas
