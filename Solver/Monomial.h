#pragma once
#include <iostream>
#include <sstream>

class Monomial
{
private:
    double coefficient;
    int degree;

    Monomial(double coef = 0.0, int deg = 0) : coefficient(coef), degree(deg) {}
};

Monomial inputMonomial();
