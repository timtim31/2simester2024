#include "pch.h"
#include "CppUnitTest.h"
#include "..\Solver\Monomial.h"
#include "..\Solver\Monomial.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MonomialTests
{
    TEST_CLASS(MonomialTests)
    {
    public:

        TEST_METHOD(TestSumSameDegree)
        {
            Monomial m1(3.0, 2);
            Monomial m2(4.0, 2);
            Monomial result = m1 + m2;
            Assert::AreEqual(7.0, result.coefficient);
            Assert::AreEqual(2, result.degree);
        }

        TEST_METHOD(TestSumDifferentDegree)
        {
            Monomial m1(3.0, 2);
            Monomial m2(4.0, 1);
            auto func = [&]() { m1 + m2; };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(TestSubSameDegree)
        {
            Monomial m1(3.0, 2);
            Monomial m2(1.0, 2);
            Monomial result = m1 - m2;
            Assert::AreEqual(2.0, result.coefficient);
            Assert::AreEqual(2, result.degree);
        }

        TEST_METHOD(TestSubDifferentDegree)
        {
            Monomial m1(3.0, 2);
            Monomial m2(1.0, 1);
            auto func = [&]() { m1 - m2; };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(TestMult)
        {
            Monomial m1(3.0, 2);
            Monomial m2(2.0, 1);
            Monomial result = m1 * m2;
            Assert::AreEqual(6.0, result.coefficient);
            Assert::AreEqual(3, result.degree);
        }

        TEST_METHOD(TestDivis)
        {
            Monomial m1(6.0, 3);
            Monomial m2(2.0, 1);
            Monomial result = m1 / m2;
            Assert::AreEqual(3.0, result.coefficient);
            Assert::AreEqual(2, result.degree);
        }

        TEST_METHOD(TestDivisZero)
        {
            Monomial m1(6.0, 3);
            Monomial m2(0.0, 1);
            auto func = [&]() { m1 / m2; };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(TestShift)
        {
            Monomial m1(3.0, 2);
            Monomial result = m1 << 2;
            Assert::AreEqual(3.0, result.coefficient);
            Assert::AreEqual(4, result.degree);
        }
    };
}
