#pragma once
#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <string>
#include<iostream>
#include<memory>
using namespace std;

namespace adas{
    struct Pose{
        int x;
        int y;
        char heading;
        Pose(int x = 0, int y = 0, char heading = 'N') : x(x), y(y), heading(heading) {} 
    };

class Executor {
public:
    static Executor* NewExecutor(const Pose& pose = {0, 0, 'N'}) noexcept;
    
    Executor(void) = default;
    virtual ~Executor(void) = default;
    
    Executor(const Executor&) = delete;
    Executor& operator=(const Executor&) = delete;

    virtual void Execute(const string & commands) noexcept=0;
    virtual Pose Query(void) const noexcept=0;
    };
}
#endif
