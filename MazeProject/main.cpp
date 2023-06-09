// includes
#include <iostream>
#include "CSV.h"
#include "MazeEscape.h"
#include "UI.h"

using namespace std;

int main()
{
    // CSV 객체 생성
    CSV csv;
    // maze.csv의 정보를 md에 저장
    MazeData md = csv.read("maze.csv");

    // MazeEscape 객체 생성
    MazeEscape me;
    // md의 정보를 me에 저장
    me.input(md);

    // 미로찾기 수행
    me.path(ROWS - 1, COLS - 1);
    // 경로 데이터를 path.csv에 저장
    csv.write("path.csv", me.getPathData());

    // UI 객체 생성
    UI ui;
    // pathData와 totalDistance를 ui에 저장
    ui.readData(md, me.getPathData(), me.getTotalDistance());
    // UI 출력
    ui.printMazePath();
    ui.printDistance();
}