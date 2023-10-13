#include "pch.h"
#include "CppUnitTest.h"
#include "..\complex3\ComplexNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexTests
{
	TEST_CLASS(ComplexTests)
	{
	public:
		
		TEST_METHOD(TestModule)			
		{
			ComplexNumber c(3,-4);
			Assert::IsTrue(c.Module() == 5.65685);
		}
		TEST_METHOD(TestConjugate)
		{
			ComplexNumber c(3,-4);
			Assert::IsTrue(c.Conjugate().GetReal() == 3);
			Assert::IsTrue(c.Conjugate().GetImaginary() == 4);
		}

		TEST_METHOD(TestConstructor)
		{
			ComplexNumber c;
			Assert::IsTrue(c.GetReal() == 0);
			Assert::IsTrue(c.GetImaginary() == 0);
		}
		TEST_METHOD(TestConstructorDouble)
		{
			ComplexNumber c(2,0);
			Assert::IsTrue(c.GetReal() == 2);
			Assert::IsTrue(c.GetImaginary() == 0);
		}
		TEST_METHOD(TestConstructorComplex)
		{
			ComplexNumber c(2,3);
			Assert::IsTrue(c.GetReal() == 2);
			Assert::IsTrue(c.GetImaginary() == 3);
		}
		//+
		TEST_METHOD(TestOperatorPlus)
		{
			ComplexNumber complex1{ 3, -4 };
			ComplexNumber complex2{ 4, 0 };
			ComplexNumber result{};
			result += (complex1 + complex2);
			Assert::IsTrue(result.GetReal() == 7);
			Assert::IsTrue(result.GetImaginary() == -4);
			result = complex1 + 1;
			Assert::IsTrue(result.GetReal() == 4);
			Assert::IsTrue(result.GetImaginary() == -4);
		}
		//-
		TEST_METHOD(TestOperatorMinus)
		{
			ComplexNumber complex1{ 3, -4 };
			ComplexNumber complex2{ 4, 0 };
			ComplexNumber result{};
			result += (complex1 - complex2);
			Assert::IsTrue(result.GetReal() == 1);
			Assert::IsTrue(result.GetImaginary() == -4);
			result = complex1 - 1;
			Assert::IsTrue(result.GetReal() == 2);
			Assert::IsTrue(result.GetImaginary() == -4);
		}
		//*
		TEST_METHOD(TestOperatorMultiplication)
		{
			ComplexNumber complex1{ 3, -4 };
			ComplexNumber complex2{ 1, 13 };
			ComplexNumber result{};
			result += (complex1 * complex2);
			Assert::IsTrue(result.GetReal() == 55);
			Assert::IsTrue(result.GetImaginary() == 35);
			
		}
		// /
		TEST_METHOD(TestOperatorDivision)
		{
			ComplexNumber complex1{ 3, -4 };
			ComplexNumber complex2{ 1, 13 };
			ComplexNumber result{};
			result += (complex1 / complex2);
			Assert::IsTrue(result.GetReal() == -0.288235);
			Assert::IsTrue(result.GetImaginary() == -0.252941);

		}
		//++
		TEST_METHOD(TestOperatorIncrement)
		{
			ComplexNumber complex1{ 3, -4 };
			complex1++;
	
			Assert::IsTrue(complex1.GetReal() == 4);
			Assert::IsTrue(complex1.GetImaginary() == -4);

			complex1--;

			Assert::IsTrue(complex1.GetReal() == 3);
			Assert::IsTrue(complex1.GetImaginary() == -4);
		}
		// --
		TEST_METHOD(TestOperatorDecrement)
		{
			ComplexNumber complex1{ 3, -4 };

			complex1--;

			Assert::IsTrue(complex1.GetReal() == 2);
			Assert::IsTrue(complex1.GetImaginary() == -4);
		}
	};
}
