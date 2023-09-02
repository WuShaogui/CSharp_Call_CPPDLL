本项目用于测试C#调用C++ DLL时，其数据互送规则

## 数据封送类型

**1. 基础数据类型**

![]("doc/CSharp调用动态链接库(DLL)-20230704210547-1.png")

   - 对于P/Invoke(平台调用)，具有相同格式的托管和c++本机基元类型之间不需要封送处理。例如，在Int32和int之间，或者在Double和double之间不需要封送处理
   - 但是必须对不具有相同形式的类型进行封送处理。 这包括 char、string 和 struct 类型， 在 C/C++中long和int都是4个字节，都对应着 C#中的int 类型，而C/C++中的char类型占一个字节，用来表示一个ASCII码字符，在 C#中能够表示一个字节的是byte类型

2. 数据结构
3. 数组/指针
4. 类

# 技巧

1. C#如果要接收固定大小的C++返回，直接在C#申请空间即可；如果要接收不固定大小的C++返回，需要使用IntPtr接收返回


## 已实现详情

|序号|C++接口|C#调用|解释|
|1|void ProcessPoints(point** ployPoints, int ployNum, int* ployPointsNum)|Test_interface1|C#的双重结构指针往C++传递数据|
|1|void ProcessPointsv2(point** ployPoints, int ployNum, int* ployPointsNum)|Test_interface2||
|1||||
|1||||
|1||||
|1||||
|1||||
|1||||

