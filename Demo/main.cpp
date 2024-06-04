#include <iostream>
#include "..\Solver\Monomial.h"
#include "..\Solver\Polynomial.h"
int main()
{
    setlocale(LC_ALL, "ru");
    std::cout << "Создайте первый многочлен:\n";
    Polynomial p1 = createPolynomialFromUserInput();

    std::cout << "\nСоздайте второй многочлен:\n";
    Polynomial p2 = createPolynomialFromUserInput();

    Polynomial sum = p1 + p2;
    Polynomial difference = p1 - p2;
    Polynomial product = p1 * p2;
    Polynomial quotient = p1 / p2;
    Polynomial shifted = p1 << 2;

    std::cout << "\np1: " << p1.toString() << std::endl;
    std::cout << "p2: " << p2.toString() << std::endl;
    std::cout << "p1 + p2: " << sum.toString() << std::endl;
    std::cout << "p1 - p2: " << difference.toString() << std::endl;
    std::cout << "p1 * p2: " << product.toString() << std::endl;
    std::cout << "p1 / p2: " << quotient.toString() << std::endl;
    std::cout << "p1 << 2: " << shifted.toString() << std::endl;

    return 0;
}