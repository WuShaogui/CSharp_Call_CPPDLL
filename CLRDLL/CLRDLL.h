#include "CPPDLL.h"




namespace CLRDLL
{
	public ref struct point_
	{
	public:
		double x;
		double y;
	};

	public ref class ManegerClass // C#的托管类
	{
		public:
			ManegerClass();
			~ManegerClass();

			int setA(int a1,System::String^ a2);
			int setB(point_^% b);
			int setC(int* c, int num);
		private:
			MyClass* myClass;  // C++的非托管类
	};
}