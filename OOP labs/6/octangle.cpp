#include "octangle.h"

Octangle::Octangle()
{
	m_sideA = 0.0;
	m_sideB = 0.0;
	m_height = 0.0;
}

Octangle::Octangle(std::istream& is)
{
	std::cout << "================" << std::endl;
	std::cout << "Enter side A: ";
	is >> m_sideA;

}

void Octangle::print() const
{
	std::cout << "================" << std::endl;
	std::cout << "Figure type: octangle" << std::endl;
	std::cout << "Side size: " << m_sideA << std::endl;
}

double Octangle::area() const
{
	return m_height * (m_sideA + m_sideB) / 2.0;
}
