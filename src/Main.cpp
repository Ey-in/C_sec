#include "Encounter.h"
#include <string>
#include<iostream>
using namespace std;

Encounter::Encounter() : x(0), y(0), heading('N') {}

Encounter::Encounter(int x, int y, char heading) : x(x), y(y), heading(heading) {}

int Encounter::GetX() const {return x;}

int Encounter::GetY() const {return y;}

char Encounter::GetHeading() const {return heading;}

void Encounter::GetPosition(){cout << x <<" " << y <<" " << heading << endl; }

void Encounter::Move() {
    if (heading == 'N') y++;
    else if (heading == 'E') x++;
    else if (heading == 'S') y--;
    else if (heading == 'W') x--;
}

void Encounter::TurnRight() {  
    // 使用数组和取模来处理右转  
    const char directions[] = {'N', 'E', 'S', 'W'};  
    int currentIndex = (heading == 'N') ? 0 :  
                       (heading == 'E') ? 1 :  
                       (heading == 'S') ? 2 :  
                       (heading == 'W') ? 3 : -1; // 添加-1处理无效值  

    if (currentIndex != -1) {  
        currentIndex = (currentIndex + 1) % 4; // 右转，增加1并模4  
        heading = directions[currentIndex];  
    }  
}  

void Encounter::TurnLeft() {  
    // 使用数组和取模来处理左转  
    const char directions[] = {'N', 'E', 'S', 'W'};  
    int currentIndex = (heading == 'N') ? 0 :  
                       (heading == 'E') ? 1 :  
                       (heading == 'S') ? 2 :  
                       (heading == 'W') ? 3 : -1; // 添加了-1处理无效值  

    if (currentIndex != -1) {  
        currentIndex = (currentIndex + 3) % 4; // 左转，增加3并模4  
        heading = directions[currentIndex];  
    }  
}  

void Encounter::ExecuteCommands(const string& commands) {
    for (char command : commands) {
        if (command == 'M') Move();
        else if (command == 'R') TurnRight();
        else if (command == 'L') TurnLeft();
    }
}

int main()
{
	string str;
	cin >> str;
	Encounter car1;
	car1.ExecuteCommands(str);
	car1.GetPosition();
    system("pause"); 
	return 0;
} 