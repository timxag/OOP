#ifndef OCTANGLE_H
#define OCTANGLE_H

#include <iostream>
#include "figure.h"

class Octangle : public Figure
{
public:
	Octangle();
	Octangle(std::istream& is);

	void print() const override;
	double area() const override;

private:
	double m_sideA;
};

#endif
