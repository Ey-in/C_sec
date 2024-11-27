#ifndef ENCOUNTER_H
#define ENCOUNTER_H
#include <string>

class Encounter {
public:
    Encounter();  // 默认构造函数
    Encounter(int x, int y, char heading);  // 带参构造函数

    int GetX() const;  // 获取 X 坐标
    int GetY() const;  // 获取 Y 坐标
    char GetHeading() const;  // 获取当前朝向
    void GetPosition(); //获取当前位置

    void Move();  // 移动
    void TurnRight();  // 向右转
    void TurnLeft();  // 向左转
    void ExecuteCommands(const std::string& commands);  // 执行命令

private:
    int x, y;  // 坐标
    char heading;  // 朝向
};

#endif
