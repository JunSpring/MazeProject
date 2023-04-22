#ifndef MAZEPROJECT_CSV_H
#define MAZEPROJECT_CSV_H

// includes
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "MazeData.h"

using namespace std;

// class

// csv파일을 읽어들이고 추출하기 위한 클래스
class CSV
{
private:
    // 임시로 csv파일 데이터를 저장하기 위한 vector
    vector<vector<int>> temp;
    // 미로 및 경유 정보를 저장하기 위한 MazeData
    MazeData md;

public:
    // filename의 csv파일을 읽어들이고 정보를 저장시키는 함수
    // MazeData를 리턴함
    MazeData read(const string &filename);
    // filename의 csv파일을 생성하고 경로 정보를 저장시키는 함수
    void write(const string &filename, const vector<items> &itemBox);
    // MazeData의 maze와 mark를 동적할당 해제하는 소멸자
    ~CSV();
};


#endif //MAZEPROJECT_CSV_H
