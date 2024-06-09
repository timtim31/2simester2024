#include <iostream>
#include "..\Solver\Monomial.h"
#include "..\Solver\Monomial.cpp"
int main() 
{
    std::cout << "Введите параметры для первого монома (m1):" << std::endl;
    Monomial m1 = inputMonomial();

    std::cout << "Введите параметры для второго монома (m2):" << std::endl;
    Monomial m2 = inputMonomial();
    
    Monomial sum = m1 + m2;
    Monomial dif = m1 - m2;
    Monomial mult = m1 * m2;
    Monomial divis = m1 / m2;
    Monomial shift = m1 << 2;
    
    std::cout << "\nm1:" << m1;
    std::cout << "\nm2:" << m2;
    std::cout << "\nm1 + m2:" << sum; 
    std::cout << "\nm1 - m2:" << dif;
    std::cout << "\nm1 * m2:" << mult;
    std::cout << "\nm1 / m2:" << divis;
    std::cout << "\nm1 << 2:" << shift;
    
    return 0;
}
