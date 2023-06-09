#include "UI.h"

// MazeData의 maze 동적할당 및 mark 동적할당을 하는 생성자
UI::UI()
{
    // MazeData의 maze 동적할당
    md.maze = new int *[ROWS];
    for (int i = 0; i < ROWS; i++)
        md.maze[i] = new int[COLS];

    // MazeData의 mark 동적할당
    md.mark = new int *[ROWS];
    for (int i = 0; i < ROWS; i++)
        md.mark[i] = new int[COLS];
}

// MazeData와 pathData와 totalDistance를 읽어들이기 위한 함수
void UI::readData(MazeData _md, vector<items> _pd, int _totalDistance)
{
    // MazeData
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            md.maze[row][col] = _md.maze[row][col];
            md.mark[row][col] = _md.mark[row][col];
        }
    }

    // pathData
    pd = _pd;

    // totalDistance
    totalDistance = _totalDistance;
}

// Maze와 Path에 대한 UI를 출력하기 위한 함수
void UI::printMazePath()
{
    for (int col = 0; col < COLS + 2; col++)
        cout << "■";
    cout << endl;

    for(int row = 0; row < ROWS; row++)
    {
        cout << "■";
        
        for(int col = 0; col < COLS; col++)
        {
            if (row == 0 && col == 0 || row == ROWS-1 && col == COLS-1)
            {
                cout << "⊙";
                continue;
            }

            if(md.maze[row][col] == 1)
            {
                cout << "■";
                continue;
            }

            bool printed = false;
            for(int item = 0; item < pd.size(); item++)
            {
                if(pd.at(item).y == row && pd.at(item).x == col)
                {
                    cout << "○";
                    printed = true;
                    break;
                }
            }

            if(!printed)
                cout << "  ";
        }
        
        cout << "■" << endl;
    }

    for (int col = 0; col < COLS + 2; col++)
        cout << "■";
    cout << endl;
}

// 총 이동거리를 출력하기 위한 함수
void UI::printDistance()
{
    // totalDistance는 시작점도 이동한것이라고 가정하기 때문에
    // 실질적인 총 이동거리는 totalDistance-1이다.
    cout << "총 이동거리는 " << totalDistance - 1 << "번이다." << endl;
}

// MazeData의 maze와 mark를 동적할당 해제하기 위한 소멸자
UI::~UI()
{
    for (int row = 0; row < ROWS; row++)
        delete[] md.maze[row];
    delete[] md.maze;

    for (int row = 0; row < ROWS; row++)
        delete[] md.mark[row];
    delete[] md.mark;
}