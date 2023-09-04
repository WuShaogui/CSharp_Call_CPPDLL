#pragma once
#include <iostream>
#include <string>

using namespace std;


struct point {
	double x;
	double y;
};

// ����dll�ĺ����ӿ�
extern "C"
{
	// ���ͻ�����������
	__declspec(dllexport) void func1(int a, double b, char c, int& d, double& e, char& f);

	// ��������
	__declspec(dllexport) void func2(int* a, int aNum, int* b, int*& c, int& cNum, int* d, int dNum);

	// �������ݽṹ
	__declspec(dllexport) void func3(point a, point& b);

	// ���ͽṹָ��
	__declspec(dllexport) void func4(point* a, int aNum, point* b, int bNum);  // һ��
	__declspec(dllexport) void func5(point** ployPoints, int ployNum, int* ployPointsNum); // ����,C#->C++
	__declspec(dllexport) void func6(point** ployPoints, int ployNum, int* ployPointsNum); // ����,C++->C#
};

// ����dll ����ӿ�
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