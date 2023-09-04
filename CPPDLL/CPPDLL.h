#pragma once
#include <iostream>
#include <string>

using namespace std;


struct point {
	double x;
	double y;
};

// 声明dll的函数接口
extern "C"
{
	// 封送基础数据类型
	__declspec(dllexport) void func1(int a, double b, char c, int& d, double& e, char& f);

	// 封送数组
	__declspec(dllexport) void func2(int* a, int aNum, int* b, int*& c, int& cNum, int* d, int dNum);

	// 封送数据结构
	__declspec(dllexport) void func3(point a, point& b);

	// 封送结构指针
	__declspec(dllexport) void func4(point* a, int aNum, point* b, int bNum);  // 一重
	__declspec(dllexport) void func5(point** ployPoints, int ployNum, int* ployPointsNum); // 二重,C#->C++
	__declspec(dllexport) void func6(point** ployPoints, int ployNum, int* ployPointsNum); // 二重,C++->C#
};

// 声明dll 的类接口
class __declspec(dllexport) MyClass 
{
public:
	MyClass();
	~MyClass();

	int setA(int a1,string a2);
	int setB(point b);
	int setC(int* c,int num);

private:
	int a1;
	string a2;
	point b;
	int* c;
};