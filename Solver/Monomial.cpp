#include "Monomial.h"

Monomial operator+(const Monomial& other) const 
{
    if (degree != other.degree) {
        throw std::invalid_argument("У мономов должна быть одинаковая степень");
    }
    return Monomial(coefficient + other.coefficient, degree);
}

Monomial operator-(const Monomial& other) const 
{
    if (degree != other.degree) {
        throw std::invalid_argument("У мономов должна быть одинаковая степень");
    }
    return Monomial(coefficient - other.coefficient, degree);
}

Monomial operator*(const Monomial& other) const 
{
    return Monomial(coefficient * other.coefficient, degree + other.degree);
}

Monomial operator/(const Monomial& other) const 
{
    if (other.coefficient == 0) 
    {
        throw std::invalid_argument("Деление на ноль");
    }
    return Monomial(coefficient / other.coefficient, degree - other.degree);
}

Monomial operator<<(int shifts) const 
{
    return Monomial(coefficient, degree + shifts);
}

friend std::ostream& operator<<(std::ostream& os, const Monomial& monom);


std::ostream& operator<<(std::ostream& os, const Monomial& monom) 
{
    if (monom.degree == 0) 
    {    
        os << monom.coefficient;
    } 
    else if (monom.degree == 1) 
    {
        os << monom.coefficient << "*x";
    } 
    else 
    {
        os << monom.coefficient << "*x^" << monom.degree;
    }
    return os;
}

Monomial inputMonomial() 
{
    double coef;
    int deg;
    std::cout << "Введите коэффициент: ";
    std::cin >> coef;
    std::cout << "Введите степень: ";
    std::cin >> deg;
    return Monomial(coef, deg);
}
