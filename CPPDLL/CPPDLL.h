#pragma once

struct point {
	double x;
	double y;
};

// 声明DLL开放的接口
extern "C"
{
	// 封送基础数据类型
	__declspec(dllexport) void func1(int a, double b, char c,int& d,double& e,char& f);


	// 封送一维数据结构
	struct point {
		int a;
		double b;
		char c;
	};

	// 封送嵌套的数据结构


	/// <summary>
	/// 接口1:验证C#向C++传递结构体二维数组	
	/// </summary>
	/// <param name="ployPoints">结构体的二维数组</param>
	/// <param name="ployNum">结构体数量</param>
	/// <param name="ployPointsNum">每个二维数组的长度</param>
	__declspec(dllexport) void ProcessPoints(point** ployPoints, int ployNum, int* ployPointsNum);

	/// <summary>
	/// 接口2:验证C#申请一维结构指针空间，C++申请二维结构空间	
	/// </summary>
	/// <param name="ployPoints">结构体的二维数组</param>
	/// <param name="ployNum">结构体数量</param>
	/// <param name="ployPointsNum">每个二维数组的长度</param>
	__declspec(dllexport) void ProcessPointsv2(point** ployPoints, int ployNum, int* ployPointsNum);
}