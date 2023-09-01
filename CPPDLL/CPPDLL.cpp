#include <iostream>

#include "CPPDLL.h"

using namespace std;


void func1(int a, double b, char c,int& d, double& e, char& f) {
    std::cout << "[i n]C++: " << a << "-" << b << "-" << c << "-" << d << "-" << e << "-" << f << endl;
    a = 8, b = 3.3, c = 'K';
    d = 8, e = 10.2, f = 'G';
    std::cout << "[out]C++: " << a << "-" << b << "-" << c << "-" << d << "-" << e << "-" << f << endl;
};


void ProcessPoints(point** ployPoints, int ployNum, int* ployPointsNum) {

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

void ProcessPointsv2(point** ployPoints, int ployNum, int* ployPointsNum)
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