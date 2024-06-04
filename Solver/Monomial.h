#pragma once
#include <iostream>
#include <sstream>

class Monomial
{
public:
    double coefficient;
    int degree;

    Monomial(double coeff, int deg) : coefficient(coeff), degree(deg) {}

    std::string toString() const;
};