#include <iostream>

#include "CPPDLL.h"

using namespace std;


void func1(int a, double b, char c,int& d, double& e, char& f) {
    std::cout << "[i n]C++: " << a << "-" << b << "-" << c << "-" << d << "-" << e << "-" << f << endl;
    a = 8, b = 3.3, c = 'K';
    d = 8, e = 10.2, f = 'G';
    std::cout << "[out]C++: " << a << "-" << b << "-" << c << "-" << d << "-" << e << "-" << f << endl;
};


void func2(int* a, int aNum,int* b,int*& c, int& cNum) {
    // 打印C#传递过来的数组
    for (int i = 0; i < aNum; i++)
    {
        std::cout << a[i] << "-";
    }
    std::cout << "" << endl;

    b[0] = -1;
    b[1] = -2;

    cNum = 10;
    c = new int[cNum];
    for (int i = 0; i < cNum; i++)
    {
        c[i] = 100 + i;
    }
};


void func3(point a, point& b) {
    std::cout << "a: " << a.x << "," << a.y << endl;

    b.x = 10;
    b.y = 100;
}

void func4(point* a, int aNum, point* b, int bNum) {

    for (int i = 0; i < aNum; i++)
    {
        std::cout << a[i].x << "," << a[i].y << endl;
    }

    for (int i = 0; i < bNum; i++)
    {
        b[i].x = (i+1)*10+i;
        b[i].y = (i + 2) * 10 + i;
    }
}


void func5(point** ployPoints, int ployNum, int* ployPointsNum) {

    std::cout << ployNum << endl;
    for (int i = 0; i < ployNum; i++) {
        std::cout << ployPointsNum[i] << endl;
    }

    for (int i = 0; i < ployNum; i++)
    {
        for (int j = 0; j < ployPointsNum[i]; j++)
        {
            std::cout << i << "," << j << "=" << ployPoints[i][j].x << "," << ployPoints[i][j].y << endl;
        }
    }
}


void func6(point** ployPoints, int ployNum, int* ployPointsNum)
{
    ployPoints[0] = new point[1];
    ployPoints[0][0].x = 1.1;
    ployPoints[0][0].y = 2.1;

    ployPoints[1] = new point[2];
    ployPoints[1][0].x = 3.1;
    ployPoints[1][0].y = 3.2;
    ployPoints[1][1].x = 4.1;
    ployPoints[1][1].y = 4.2;

    ployPoints[2] = new point[3];
    ployPoints[2][0].x = 5.1;
    ployPoints[2][0].y = 5.2;
    ployPoints[2][1].x = 6.1;
    ployPoints[2][1].y = 6.2;
    ployPoints[2][2].x = 7.1;
    ployPoints[2][2].y = 7.2;

    ployNum = 3;
    ployPointsNum[0] = 1;
    ployPointsNum[1] = 2;
    ployPointsNum[2] = 3;

}