#include "MazeEscape.h"

// MazeData의 maze 동적할당 및 mark 동적할당 및 mark 초기화를 하는 생성자
MazeEscape::MazeEscape()
{
    // maze 동적할당
    md.maze = new int *[ROWS];
    for (int i = 0; i < ROWS; i++)
        md.maze[i] = new int[COLS];

    // mark 동적할당
    md.mark = new int *[ROWS];
    for (int i = 0; i < ROWS; i++)
        md.mark[i] = new int[COLS];

    // mark를 모두 0으로 초기화
    for (int row = 0; row < ROWS; row++)
        for (int col = 0; col < COLS; col++)
            md.mark[row][col] = 0;

    // 총 이동거리를 0으로 초기화
    totalDistance = 0;
}

// MazeData를 받아오기 위한 함수
void MazeEscape::input(MazeData _md)
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            md.maze[row][col] = _md.maze[row][col];
            md.mark[row][col] = _md.mark[row][col];
        }
    }
}

// 미로찾기를 수행하고 수행에 성공한 여부를 리턴하는 함수
bool MazeEscape::path(int end_y, int end_x)
{
    // 현위치에서 바라보는 방향
    int dir = E;
    // 현위치의 x, y 좌표
    int current_x = 0, current_y = 0;
    // 처음 시작점은 경유했다고 설정
    md.mark[0][0] = 1;

    // 미로의 크기만큼 stack 생성
    Stack<items> stack(end_y * end_x);

    // stack에 추가하기 위한 itemBox
    items itemBox;

    // 시작점을 stack에 추가
    itemBox.x = 0;
    itemBox.y = 0;
    itemBox.dir = E;
    stack.Push(itemBox);

    while (!stack.IsEmpty())
    {
        // 시작점이거나 네 방향이 모두 막혀있을 때 stack에서 pop
        itemBox = *stack.Pop(itemBox);

        // 현위치에 정보 갱신
        current_x = itemBox.x;
        current_y = itemBox.y;
        dir = itemBox.dir;

        // 네 방향을 모두 검사
        while (dir < 4)
        {
            // 이동할 위치에 현위치과 이동 정보를 더해서 저장
            int next_y = current_y + moving[dir].y;
            int next_x = current_x + moving[dir].x;

            // 만약에 오른쪽 아래에 도착했다면
            if ((next_y == end_y) && (next_x == end_x))
            {
                // stack에서 pop하기 위한 임시의 items 구조체 객체
                items tempBox;

                // stack이 빌때까지 stack에서 pop한 후 pathData에 push_back
                while(!stack.IsEmpty())
                    pathData.push_back(*stack.Pop(tempBox));

                // stack에서 모두 pop하면 데이터의 순서가 역순이기 때문에
                // algorithm 라이브러리의 reverse 사용
                reverse(pathData.begin(), pathData.end());

                // 현위치를 pathData에 push_back
                tempBox.x = current_x;
                tempBox.y = current_y;
                tempBox.dir = E;
                pathData.push_back(tempBox);

                // 마지막위치를 pathData에 push_back
                tempBox.x = end_x;
                tempBox.y = end_y;
                tempBox.dir = E;
                pathData.push_back(tempBox);

                // 미로찾기에 성공했으므로 참을 리턴
                return true;
            }

            // 만약 이동할 위치가 index를 넘어가지 않고
            // 이동할 위치가 이동할 수 있는 위치라면
            if (rangeCheck(next_y, next_x) && (!md.maze[next_y][next_x]) && (!md.mark[next_y][next_x]))
            {
                // 이동할 위치를 경유한 위치라고 설정
                md.mark[next_y][next_x] = 1;

                // 현위치를 stack에 추가
                itemBox.x = current_x;
                itemBox.y = current_y;
                itemBox.dir = dir + 1;
                stack.Push(itemBox);

                // 이동할 위치를 현위치에 저장
                current_x = next_x;
                current_y = next_y;
                dir = E;

                // 총 이동거리를 증가
                totalDistance++;
            } 

            // 바라보는 방향으로의 이동이 불가능하므로 다음 방향으로 설정
            else
                dir++;
        }
    }

    // 미로 찾기에 실패했으므로 거짓을 리턴
    return false;
}

// 이동할 위치가 index를 넘어갔는지 체크하는 함수
bool MazeEscape::rangeCheck(int g, int h)
{
    if (g == -1 || g == ROWS)
        return false;
    if (h == -1 || h == COLS)
        return false;
    return true;
}

// pathData를 리턴해주는 함수
vector<items> MazeEscape::getPathData()
{
    return pathData;
}

// totalDistance를 리턴해주는 함수
int MazeEscape::getTotalDistance()
{
    return totalDistance;
}

// MazeData의 maze와 mark 동적할당 해제를 위한 소멸자
MazeEscape::~MazeEscape()
{
    for (int row = 0; row < ROWS; row++)
        delete[] md.maze[row];
    delete[] md.maze;

    for (int row = 0; row < ROWS; row++)
        delete[] md.mark[row];
    delete[] md.mark;
}