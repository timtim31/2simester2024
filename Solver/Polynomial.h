#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include "..\Solver\Monomial.h"

class Polynomial
{
private:
    std::vector<Monomial> monomials;

    void simplify();

public:
    Polynomial(const std::vector<Monomial>& mons) : monomials(mons)
    {
        simplify();
    }

    Polynomial operator+(const Polynomial& other) const;

    Polynomial operator-(const Polynomial& other) const;

    Polynomial operator*(const Polynomial& other) const;

    Polynomial operator/(const Polynomial& other) const;

    Polynomial operator<<(int shift) const;

    std::string toString() const;
};

Polynomial createPolynomialFromUserInput();