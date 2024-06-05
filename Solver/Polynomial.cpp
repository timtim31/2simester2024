#include "Polynomial.h"

void Polynomial::simplify()
{
    std::sort(monomials.begin(), monomials.end(), [](const Monomial& a, const Monomial& b)
        {
            return a.degree > b.degree;
        });

    std::vector<Monomial> simplified;
    for (const auto& m : monomials)
    {
        if (!simplified.empty() && simplified.back().degree == m.degree)
        {
            simplified.back().coefficient += m.coefficient;
        }
        else
        {
            simplified.push_back(m);
        }
    }

    monomials = simplified;
}

Polynomial Polynomial::operator+(const Polynomial& other) const
{
    Polinomial result(*this);
    for (const auto& term : other.terms) 
    {
        result.terms[term.first] += term.second;
    }
    return Polynomial(result);
}

Polynomial Polynomial::operator-(const Polynomial& other) const
{
  Polinomial result(*this);
    for (const auto& term : other.terms) 
    {
        result.terms[term.first] -= term.second;
    }
    return Polynomial(result);
}

Polynomial Polynomial::operator*(const Polynomial& other) const
{
    Polinomial result;
    for (const auto& term1 : this->terms) 
    {
        for (const auto& term2 : other.terms) 
        {
            int newDegree = term1.first + term2.first;
            double newCoefficient = term1.second * term2.second;
            result.terms[newDegree] += newCoefficient;
        }
    }
    return Polynomial(result);
}

Polynomial Polynomial::operator/(const Polynomial& other) const
{
    if (other.monomials.empty() || (other.monomials.size() == 1 && other.monomials[0].coefficient == 0))
    {
        throw std::invalid_argument("Cannot divide by a zero polynomial.");
    }

    std::vector<Monomial> dividend = monomials;
    std::vector<Monomial> divisor = other.monomials;
    std::vector<Monomial> result;

    while (!dividend.empty() && dividend.front().degree >= divisor.front().degree)
    {
        Monomial leadDividend = dividend.front();
        Monomial leadDivisor = divisor.front();
        Monomial quotientMonomial(leadDividend.coefficient / leadDivisor.coefficient, leadDividend.degree - leadDivisor.degree);

        result.push_back(quotientMonomial);

        Polynomial subtrahend({ quotientMonomial });
        subtrahend = subtrahend * Polynomial(divisor);

        Polynomial newDividend(dividend);
        newDividend = newDividend - subtrahend;
        dividend = newDividend.monomials;
    }

    return Polynomial(result);
}

Polynomial Polynomial::operator<<(int shift) const
{
    std::vector<Monomial> result;
    for (const auto& m : monomials)
    {
        result.push_back(Monomial(m.coefficient, m.degree + shift));
    }
    return Polynomial(result);
}

std::string Polynomial::toString() const
{
    if (monomials.empty()) return "0";

    std::ostringstream oss;
    for (const auto& monomial : monomials)
    {
        if (oss.tellp() > 0 && monomial.coefficient > 0)
        {
            oss << "+";
        }
        oss << monomial.toString();
    }
    return oss.str();
}

Polynomial createPolynomialFromUserInput()
{
    std::vector<Monomial> monomials;
    std::cout << "Введите количество одночленов в многочлене: ";
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Введите коэффициент и показатель степени для одночлена " << i + 1 <<;
        double coefficient;
        int degree;
        std::cin >> coefficient >> degree;
        monomials.push_back(Monomial(coefficient, degree));
    }
    return Polynomial(monomials);
}
