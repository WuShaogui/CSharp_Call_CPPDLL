#pragma once

struct point {
	double x;
	double y;
};

// ����DLL���ŵĽӿ�
extern "C"
{
	// ���ͻ�����������
	__declspec(dllexport) void func1(int a, double b, char c,int& d,double& e,char& f);

	// ��������
	__declspec(dllexport) void func2(int* a, int aNum, int* b, int*& c, int& cNum);

	// �������ݽṹ
	__declspec(dllexport) void func3(point a, point& b);

	// ���ͽṹָ��
	__declspec(dllexport) void func4(point* a, int aNum,point* b,int bNum);  // һ��
	__declspec(dllexport) void func5(point** ployPoints, int ployNum, int* ployPointsNum); // ����,C#->C++
	__declspec(dllexport) void func6(point** ployPoints, int ployNum, int* ployPointsNum); // ����,C++->C#
}