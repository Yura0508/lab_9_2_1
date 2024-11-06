#include "pch.h"
#include "CppUnitTest.h"
#include <cmath> // для sqrt

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Оголошення макросів, які використовуються в основній програмі
#define SQR(p) ((p)*(p)) // макрос для квадрата числа
#define MAX(p,u) ((p) > (u)) ? (p) : (u) // макрос для знаходження максимального з двох
#define ABS(p) ((p) >= 0 ? (p) : -(p)) // макрос для модуля числа
#define SQRT(p) (sqrt(ABS(p))) // макрос для кореня числа

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        // Тест для перевірки макроса SQR (квадрат числа)
        TEST_METHOD(TestSQR)
        {
            int x = 4;
            int expected = 16;
            int result = SQR(x);
            Assert::AreEqual(expected, result);
        }

        // Тест для перевірки макроса MAX (максимум з двох чисел)
        TEST_METHOD(TestMAX)
        {
            int x = 5, y = 3;
            int expected = 5;
            int result = MAX(x, y);
            Assert::AreEqual(expected, result);
        }

        // Тест для перевірки макроса ABS (модуль числа)
        TEST_METHOD(TestABS)
        {
            int x = -7;
            int expected = 7;
            int result = ABS(x);
            Assert::AreEqual(expected, result);
        }

        // Тест для перевірки макроса SQRT (корінь числа)
        TEST_METHOD(TestSQRT)
        {
            int x = 16;
            float expected = 4.0f;
            float result = SQRT(x);
            Assert::AreEqual(expected, result, 0.01f); // Дозволяємо невелику похибку для чисел з плаваючою точкою
        }

        // Тест для перевірки комплексної логіки
        TEST_METHOD(TestComplexLogic)
        {
            int x = 5, y = 3, z = 2;

            // Для перевірки вищезгаданих макросів
            int n_kvadr = SQR(x - z); // (x - z)^2
            int sub = x - y;          // (x - y)
            int w = MAX(n_kvadr, sub); // max((x - z)^2, (x - y))

            // Перевірка, чи правильний результат
            int expected = 9; // (x - z)^2 = 9, (x - y) = 2
            Assert::AreEqual(w, expected);
        }
    };
}