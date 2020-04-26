#include "pch.h"
#include "CppUnitTest.h"
#include"..\Project9\test.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
	
		TEST_METHOD(TestMethod1)
		{
			test A;
			int choice = 1;//选择运算类型
			int grade = 1;//年级
		    int number = 20;//选择生成题量
			char name = 10;//生成文件命名
			Assert::AreEqual(1,A.AddSub(1));
		}
		TEST_METHOD(TestMethod2)
		{
			test A;
			int choice = 1;//选择运算类型
			int grade = 2;//年级
			int number = 20;//选择生成题量
			char name = 20;//生成文件命名
			Assert::AreEqual(1, A.Mul_Div(2,3));
		}
		TEST_METHOD(TestMethod3)
		{
			test A;
			int choice = 1;//选择运算类型
			int grade = 3;//年级
			int number = 20;//选择生成题量
			char name = 30;//生成文件命名
			Assert::AreEqual(1, A.Print(3));
		}
		TEST_METHOD(TestMethod4)
		{
			test A;
			int choice = 1;//选择运算类型
			int grade = 4;//年级
			int number = 20;//选择生成题量
			char name = 40;//生成文件命名
			Assert::AreEqual(1, A.FloatCount(2));
		}

		
	};
}
