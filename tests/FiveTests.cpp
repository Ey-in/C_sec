#include <gtest/gtest.h>  
#include "Encounter.h"

// 测试默认构造函数  
TEST(DefaultConstructorTest, Default) {  
    Encounter car;  
    EXPECT_EQ(car.GetX(), 0);  
    EXPECT_EQ(car.GetY(), 0);  
    EXPECT_EQ(car.GetHeading(), 'N');  
}  

// 测试带参数的构造函数  
TEST(ParameterizedConstructorTest, Parameterized) {  
    Encounter car(5, 10, 'E');  
    EXPECT_EQ(car.GetX(), 5);  
    EXPECT_EQ(car.GetY(), 10);  
    EXPECT_EQ(car.GetHeading(), 'E');  
}  

// 测试移动功能  
TEST(MoveTest, Move) {  
    Encounter car;  
    car.Move();  // 默认朝向 'N'  
    EXPECT_EQ(car.GetY(), 1);  // Y 应该增加 1  
    car.TurnRight();  
    car.Move();  // 现在朝向 'E'  
    EXPECT_EQ(car.GetX(), 1);  // X 应该增加 1  
    car.TurnLeft();  
    car.Move();  // 现在朝向 'N'  
    EXPECT_EQ(car.GetY(), 2);  // Y 应该增加 1  
}  

// 测试转向功能  
TEST(TurnTest, Turn) {  
    Encounter car;  
    car.TurnRight();  
    EXPECT_EQ(car.GetHeading(), 'E');  // 右转后应该是 'E'  
    car.TurnRight();  
    EXPECT_EQ(car.GetHeading(), 'S');  // 再右转后应该是 'S'  
    car.TurnLeft();  
    EXPECT_EQ(car.GetHeading(), 'E');  // 左转后应该回到 'E'  
    car.TurnLeft();  
    EXPECT_EQ(car.GetHeading(), 'N');  // 再左转后应该是 'N'  
}  

// 测试执行命令  
TEST(ExecuteCommandsTest, ExecuteCommands) {  
    Encounter car;  
    car.ExecuteCommands("MMRMM");  // 向前移动 2 次，右转，向前移动 2 次  
    EXPECT_EQ(car.GetX(), 2);  // 应该在 X=2, Y=2  
    EXPECT_EQ(car.GetY(), 2);  
    EXPECT_EQ(car.GetHeading(), 'E');  // 最后朝向 'E'  
}  

// 主程序  
int main(int argc, char **argv) {  
    ::testing::InitGoogleTest(&argc, argv);  
    return RUN_ALL_TESTS();  
}