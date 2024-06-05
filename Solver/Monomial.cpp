#include "Monomial.h"

std::ostream& operator<<(std::ostream& os, const Monomial& monom) 
{
    if (monom.degree == 0)
        os << monom.coefficient;
    else if (monom.degree == 1)
        os << monom.coefficient << "*x";
    else
        os << monom.coefficient << "*x^" << monom.degree;
    return os;
}

