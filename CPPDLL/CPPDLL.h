#pragma once

struct point {
	double x;
	double y;
};

// ����DLL���ŵĽӿ�
__declspec(dllexport) extern "C"
{
	/// <summary>
	/// �ӿ�1:��֤C#��C++���ݽṹ���ά����	
	/// </summary>
	/// <param name="ployPoints">�ṹ��Ķ�ά����</param>
	/// <param name="ployNum">�ṹ������</param>
	/// <param name="ployPointsNum">ÿ����ά����ĳ���</param>
	void ProcessPoints(point** ployPoints, int ployNum, int* ployPointsNum);

	/// <summary>
	/// �ӿ�2:��֤C#����һά�ṹָ��ռ䣬C++�����ά�ṹ�ռ�	
	/// </summary>
	/// <param name="ployPoints">�ṹ��Ķ�ά����</param>
	/// <param name="ployNum">�ṹ������</param>
	/// <param name="ployPointsNum">ÿ����ά����ĳ���</param>
	void ProcessPointsv2(point** ployPoints, int ployNum, int* ployPointsNum);
}