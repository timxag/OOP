#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "figure.h"

class Triangle : public Figure
{
public:
	Triangle();
	Triangle(std::istream& is);

	void print() const override;
	double area() const override;

private:
	double m_sideA;

};

#endif
