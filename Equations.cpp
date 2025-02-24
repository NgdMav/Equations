#include "Equations.h"

LineEquation::LineEquation()
{
	this->k = 1;
	this->b = 0;
}

LineEquation::LineEquation(double initk, double initb)
{
	this->k = initk;
	this->b = initb;
}

void LineEquation::solve() {
	if (abs(k) < 0.000001) {
		std::cout << "No solution for this equation";
		return;
	}
	std::cout << "Root = " << -(this->b / this->k);
}

void LineEquation::print() {
	std::cout << "Equation: " << this->k << "x" << ((this->b >= 0) ? " + " : " - ") << abs(this->b) << " = 0";
}

QuadraticEquation::QuadraticEquation()
{
	this->a = 1;
	this->b = 2;
	this->c = 1;
}

QuadraticEquation::QuadraticEquation(double inita, double initb, double initc)
{
	this->a = inita;
	this->b = initb;
	this->c = initc;
}

void QuadraticEquation::solve()
{
	if (abs(a) < 0.000001) {
		std::cout << "No solution for this equation";
		return;
	}
	double dis = b * b - 4 * a * c;
	if (dis < 0) {
		std::cout << "No solution for this equation";
        return;
	}
	if (dis < 0.000001) {
		std::cout << "x = " << -(b / 2 / a);
		return;
	}
	std::cout << "x1 = " << (-b + sqrt(dis)) / 2 / a << "\n";
	std::cout << "x2 = " << (-b - sqrt(dis)) / 2 / a;
}

void QuadraticEquation::print(std::ostream& out)
{
	std::cout << "Equation: " << this->a << "x^2" << ((this->b >= 0) ? " + " : " - ") << abs(this->b) << "x" <<
		((this->c >= 0) ? " + " : " - ") << abs(this->c) << " = 0";
}