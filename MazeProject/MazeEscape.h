#ifndef MAZEPROJECT_MAZEESCAPE_H
#define MAZEPROJECT_MAZEESCAPE_H

// includes
#include <iostream>
#include <vector>
#include <algorithm>
#include "standard.h"
#include "MazeData.h"
#include "Stack.h"

using namespace std;

// class

// 미로찾기 및 각종 기능을 제공하는 class
class MazeEscape
{
private:
    // 미로 및 경유 정보를 저장하기 위한 MazeData
    MazeData md;
    // 경로 정보를 저장하기 위한 vector
    vector<items> pathData;
    // 총 이동거리를 저장하기 위한 int
    int totalDistance;
public:
    // MazeData의 maze 동적할당 및 mark 동적할당
    // mark 초기화 및 총 이동거리 초기화를 하는 생성자
    MazeEscape();
    // MazeData를 받아오기 위한 함수
    void input(MazeData maze);
    // 미로찾기를 수행하고 수행에 성공한 여부를 리턴하는 함수
    bool path(int end_y, int end_x);
    // 이동할 위치가 index를 넘어갔는지 체크하는 함수
    bool rangeCheck(int g, int h);
    // pathData를 리턴해주는 함수
    vector<items> getPathData();
    // totalDistance를 리턴해주는 함수
    int getTotalDistance();
    // MazeData의 maze와 mark 동적할당 해제를 위한 소멸자
    ~MazeEscape();
};

#endif //MAZEPROJECT_MAZEESCAPE_H
