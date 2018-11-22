#include "square.h"
#include "triangle.h"
#include "trapezoid.h"

void testFigure(Figure* figure);

int main()
{
	testFigure(new Square(std::cin));
	testFigure(new Triangle(std::cin));
	testFigure(new Octangle(std::cin));

	return 0;
}

void testFigure(Figure* figure)
{
	figure->print();

	std::cout << "Area: " << figure->area() << std::endl;

	delete figure;
}
