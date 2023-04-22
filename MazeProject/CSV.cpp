#include "CSV.h"

// extern 변수의 정의
int COLS = 0;
int ROWS = 0;

// filename의 csv파일을 읽어들이고 정보를 저장시키는 함수
// MazeData를 리턴함
MazeData CSV::read(const string &filename)
{
    // filename의 csv파일을 열고 데이터를 temp에 저장시킴
    // 동시에 행과 열의 크기를 ROWS와 COLS에 저장시킴
    fstream file(filename, ios::in);
    string line;

    ROWS = 0;
    while (getline(file, line))
    {
        vector<int> rowVector;
        stringstream ss(line);

        COLS = 0;
        string value;
        while (getline(ss, value, ','))
        {
            rowVector.push_back(stoi(value));
            COLS++;
        }

        ROWS++;
        temp.push_back(rowVector);
    }

    file.close();

    // 행과 열의 크기를 알았으니
    // 그 크기만큼 MazeData의 이중포인터에 동적할당
    md.maze = new int *[ROWS];
    for (int i = 0; i < ROWS; i++)
        md.maze[i] = new int[COLS];

    md.mark = new int* [ROWS];
    for (int i = 0; i < ROWS; i++)
        md.mark[i] = new int[COLS];

    // temp에 저장된 정보를 MazeData의 maze에 저장
    for (int row = 0; row < ROWS; row++)
        for (int col = 0; col < COLS; col++)
            md.maze[row][col] = temp[row][col];

    // MazeData의 mark를 0으로 초기화
    for (int row = 0; row < ROWS; row++)
        for (int col = 0; col < COLS; col++)
            md.mark[row][col] = 0;

    // MazeData 리턴
    return md;
}

// filename의 csv파일을 생성하고 경로 정보를 저장시키는 함수
void CSV::write(const string &filename, const vector<items> &itemBox)
{
    // filename의 csv파일을 생성하거나 열고 경로 정보가 담긴 itemBox의 정보를 저장
    fstream file(filename, ios::out);

    for (const auto &row: itemBox)
        // 미로의 정보 index가 0으로 시작하나 예제에서 1부터 시작이므로
        // x축과 y축 정보에 1을 더하여 저장
        file << row.y + 1 << "," << row.x + 1 << endl;

    file.close();
}

// MazeData의 maze와 mark를 동적할당 해제하는 소멸자
CSV::~CSV()
{
    for (int row = 0; row < ROWS; row++)
        delete[] md.maze[row];
    delete[] md.maze;

    for (int row = 0; row < ROWS; row++)
        delete[] md.mark[row];
    delete[] md.mark;
}
