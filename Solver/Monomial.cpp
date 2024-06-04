#include "Monomial.h"

std::string Monomial::toString() const
{
    std::ostringstream oss;
    if (coefficient == 0) return "";
    if (degree == 0) oss << coefficient;
    else if (degree == 1) oss << coefficient << "x";
    else oss << coefficient << "x^" << degree;
    return oss.str();
}
