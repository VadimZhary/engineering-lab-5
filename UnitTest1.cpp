#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\1\source\repos\ИПЗ лаба 5\ИПЗ лаба 5\ИПЗ лаба 5.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(calculate_Tests) {
public:
	TEST_METHOD(calculate_get0point5and2_2returned) {
		int n = 2;
		float x = 0.5;
		float expected = 324234;

		float actual = calculate(x, n);

		Assert::AreEqual(expected, actual);
	}
public:
	TEST_METHOD(calculate_get1and1_0returned) {
		int n = 1;
		float x = 1;
		float expected = 0;

		float actual = calculate(x, n);

		Assert::AreEqual(expected, actual);
	}
	};
}
