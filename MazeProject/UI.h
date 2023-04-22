#ifndef MAZEPROJECT_UI_H
#define MAZEPROJECT_UI_H

// includes
#include <iostream>
#include <vector>
#include "MazeData.h"
#include "standard.h"

using namespace std;

// 화면에 실행결과를 출력하기 위한 class
class UI
{
private:
   // 미로 및 경유 정보를 저장하기 위한 MazeData
    MazeData md;
    // 경로 정보를 저장하기 위한 vector
    vector<items> pd;
    // 총 이동거리를 저장하기 위한 int
    int totalDistance;

public:
    // MazeData의 maze 동적할당 및 mark 동적할당을 하는 생성자
    UI();
    // MazeData와 pathData와 totalDistance를 읽어들이기 위한 함수
    void readData(MazeData _md, vector<items> _pd, int _totalDistance);
    // Maze와 Path에 대한 UI를 출력하기 위한 함수
    void printMazePath();
    // 총 이동거리를 출력하기 위한 함수
    void printDistance();
    // MazeData의 maze와 mark를 동적할당 해제하기 위한 소멸자
    ~UI();
};


#endif //MAZEPROJECT_UI_H
