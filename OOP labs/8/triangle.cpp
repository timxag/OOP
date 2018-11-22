#include "triangle.h"
#include <bits/stdc++.h>
Triangle::Triangle()
{
	m_sideA = 0.0;
	m_sideB = 0.0;
}

Triangle::Triangle(std::istream& is)
{
	std::cout << "================" << std::endl;
	std::cout << "Enter side: ";
	is >> m_sideA;
}

void Triangle::print() const
{
	std::cout << "================" << std::endl;
	std::cout << "Figure type: Triangle" << std::endl;
	std::cout << "Side size: " << m_sideA << std::endl;
}

double Triangle::area() const
{
	return m_sideA * m_sideA * sqrt(3) /4;
}
