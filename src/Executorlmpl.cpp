#include "ExecutorImpl.hpp"
namespace adas
{
    Executor* Executor::NewExecutor(const Pose& pose) noexcept{
         return new (std::nothrow) ExecutorImpl(pose);}
    
    ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept: pose(pose) {}
    
    void ExecutorImpl::Execute(const std::string& commands) noexcept{
        for (auto command : commands) {
            unique_ptr<ICommand>cmder; 
            if(command == 'M') { cmder = make_unique<MoveCommand>();}
            else if(command == 'L') { cmder = make_unique<TurnLeftCommand>();}
            else if(command == 'R') { cmder = make_unique<TurnRightCommand>();}
            else if(command == 'F') { cmder = make_unique<FastCommand>();}

            if(cmder)  { cmder->DoOperate(*this); }
        }
    }
    
    Pose ExecutorImpl::Query() const noexcept{
        return pose;
    }

    void ExecutorImpl::Move() noexcept{
        if(pose.heading == 'E'){ ++pose.x; }
        else if(pose.heading == 'W'){ --pose.x; }
        else if(pose.heading == 'N'){ ++pose.y; }
        else if(pose.heading == 'S'){ --pose.y; }
    }

    void ExecutorImpl::TurnLeft() noexcept{  
    // 使用数组和取模来处理左转  
        const char directions[] = {'N', 'E', 'S', 'W'};  
        int currentIndex = (pose.heading == 'N') ? 0 :  
                           (pose.heading == 'E') ? 1 :  
                           (pose.heading == 'S') ? 2 :  
                           (pose.heading == 'W') ? 3 : -1; // 添加了-1处理无效值  
        if (currentIndex != -1) {  
            currentIndex = (currentIndex + 3) % 4; // 左转，增加3并模4  
            pose.heading = directions[currentIndex];  
        }  
    }  

    void ExecutorImpl::TurnRight() noexcept{  
    // 使用数组和取模来处理右转  
        const char directions[] = {'N', 'E', 'S', 'W'};  
        int currentIndex = (pose.heading == 'N') ? 0 :  
                           (pose.heading == 'E') ? 1 :  
                           (pose.heading == 'S') ? 2 :  
                           (pose.heading == 'W') ? 3 : -1; // 添加-1处理无效值  
        if (currentIndex != -1) {  
            currentIndex = (currentIndex + 1) % 4; // 右转，增加1并模4  
            pose.heading = directions[currentIndex];  
        }  
    }     

    void ExecutorImpl::Fast() noexcept
    {  
        fast=!fast;
    }

    bool ExecutorImpl::IsFast() const noexcept
    {
        return fast;
    }
} 
