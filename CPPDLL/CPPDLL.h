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


	// ����һά���ݽṹ
	struct point {
		int a;
		double b;
		char c;
	};

	// ����Ƕ�׵����ݽṹ


	/// <summary>
	/// �ӿ�1:��֤C#��C++���ݽṹ���ά����	
	/// </summary>
	/// <param name="ployPoints">�ṹ��Ķ�ά����</param>
	/// <param name="ployNum">�ṹ������</param>
	/// <param name="ployPointsNum">ÿ����ά����ĳ���</param>
	__declspec(dllexport) void ProcessPoints(point** ployPoints, int ployNum, int* ployPointsNum);

	/// <summary>
	/// �ӿ�2:��֤C#����һά�ṹָ��ռ䣬C++�����ά�ṹ�ռ�	
	/// </summary>
	/// <param name="ployPoints">�ṹ��Ķ�ά����</param>
	/// <param name="ployNum">�ṹ������</param>
	/// <param name="ployPointsNum">ÿ����ά����ĳ���</param>
	__declspec(dllexport) void ProcessPointsv2(point** ployPoints, int ployNum, int* ployPointsNum);
}