#include "pch.h"
#include "..\Solver\Monomial.h"
#include "..\Solver\Polynomial.h"

void runTests() {
    Odnochlen m1(1, 2);
    Odnochlen m2(2, 1);
    Odnochlen m3(3, 0);

    Polinom p1({ m1, m2, m3 });
    Polinom p2({ Odnochlen(3, 1), Odnochlen(4, 0) });

    std::cout << "p1: " << p1 << std::endl; // 1*x^2 + 2*x + 3
    std::cout << "p2: " << p2 << std::endl; // 3*x + 4

    // Тест сложения
    Polinom p3 = p1 + p2;
    std::cout << "p1 + p2: " << p3 << std::endl; // 1*x^2 + 5*x + 7
    assert(p3.terms[2] == 1);
    assert(p3.terms[1] == 5);
    assert(p3.terms[0] == 7);

    // Тест вычитания
    Polinom p4 = p1 - p2;
    std::cout << "p1 - p2: " << p4 << std::endl; // 1*x^2 - 1*x - 1
    assert(p4.terms[2] == 1);
    assert(p4.terms[1] == -1);
    assert(p4.terms[0] == -1);

    // Тест умножения
    Polinom p5 = p1 * p2;
    std::cout << "p1 * p2: " << p5 << std::endl; // 3*x^3 + 10*x^2 + 17*x + 12
    assert(p5.terms[3] == 3);
    assert(p5.terms[2] == 10);
    assert(p5.terms[1] == 17);
    assert(p5.terms[0] == 12);

    // Тест сдвига влево
    Polinom p6 = p1 << 2;
    std::cout << "p1 << 2: " << p6 << std::endl; // 1*x^4 + 2*x^3 + 3*x^2
    assert(p6.terms[4] == 1);
    assert(p6.terms[3] == 2);
    assert(p6.terms[2] == 3);

    std::cout << "All tests passed!" << std::endl;
}

int main() 
{
    runTests();
    return 0;
}
