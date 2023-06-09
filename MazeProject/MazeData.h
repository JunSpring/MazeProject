#ifndef MAZEPROJECT_MAZEDATA_H
#define MAZEPROJECT_MAZEDATA_H

// include
#include "standard.h"

// enum

// 왼쪽 위에서 오른쪽 아래로 미로를 탐색할때
// 동쪽과 남쪽을 우선적으로 탐색하는 것이 유리하기 때문에
// 동쪽을 첫번째 인덱스로 설정
enum DIR
{
    E, S, W, N
}; // 동남서북

// structs

// 이동 offset에 struct 
struct offsets
{
    int x, y;
}; // x축 정보, y축 정보

// 헤더파일을 두번 이상 include하면 중복 선언이 되기 때문에
// static 사용
static offsets moving[4] = {{1,  0},    // 동
                            {0,  1},    // 남
                            {-1, 0},    // 서
                            {0,  -1}};  // 북

// 경로에 대한 정보를 저장하기 위한 struct
struct items
{
    int x, y, dir;
}; // x축 정보, y축 정보, 방향 정보

// 미로 정보와 경유 정보를 묶기 위한 struct
struct MazeData
{
    int **maze;
    int **mark;
}; // 미로 정보의 이중 포인터, 경유 정보의 이중 포인터

#endif //MAZEPROJECT_MAZEDATA_H
