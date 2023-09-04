#include "CPPDLL.h"
#include "CLRDLL.h"
#include <string>

#include <msclr\marshal_cppstd.h>

using namespace std;

using namespace System;
using namespace Runtime::InteropServices;
using namespace msclr::interop;


namespace CLRDLL 
{

	ManegerClass::ManegerClass()
	{
		myClass = new MyClass();
		std::cout << "init ManegerClass..." << endl;
	}
	ManegerClass::~ManegerClass()
	{
		throw gcnew System::NotImplementedException();
	}
	int ManegerClass::setA(int a1, System::String^ a2)
	{
		std:;string a2_= marshal_as<std::string>(a2->ToString());
		myClass->setA(a1, a2_);
		return 0;
	}
	int ManegerClass::setB(point_^% b)
	{
		point* b_=new point();
		b_->x = b->x;
		b_->y = b->y;
		myClass->setB(*b_);
		return 0;
	}
	int ManegerClass::setC(int* c, int num)
	{
		myClass->setC(c, num);
		return 0;
	}
}