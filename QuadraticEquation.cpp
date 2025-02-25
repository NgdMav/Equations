#include "QuadraticEquation.h"

QuadraticEquation::QuadraticEquation()
{
	this->a = 1;
	this->b = 2;
	this->c = 1;
	this->hasSolution = true;
	this->root1 = -1;
	this->root2 = -1;
}

QuadraticEquation::QuadraticEquation(double inita, double initb, double initc)
{
	if(abs(a) < 0.000001){
		throw "a can not be 0";
	}
	this->a = inita;
	this->b = initb;
	this->c = initc;
	this->solve();
}

bool QuadraticEquation::solve(){
	// if (abs(a) < 0.000001) {
	// 	this->hasSolution = false;
	// 	return false;
	// }
	double dis = b * b - 4 * a * c;
	if (dis < 0) {
		this->hasSolution = false;
		return false;
	}
	this->hasSolution = true;
	if (dis < 0.000001) {
		this->root1 = -b / (2 * a);
		this->root2 = -b / (2 * a);
		return true;
	}
	this->root1 = (-b + sqrt(dis)) / (2 * a);
	this->root2 = (-b - sqrt(dis)) / (2 * a);
	return true;
}

void QuadraticEquation::solve(std::ostream& out)
{
	if(!this->hasSolution) {
		out << "No solution for this equation";
		return;
	}
	if(this->root1 == this->root2) {
		out << "Root = " << this->root1;
	}
	else {
		out << "Root1 = " << this->root1 << "\nRoot2 = " << this->root2;
	}
}

void QuadraticEquation::print(std::ostream& out)
{
	out << "Equation: " << this->a << "x^2" << ((this->b >= 0) ? " + " : " - ") << abs(this->b) << "x" <<
	((this->c >= 0) ? " + " : " - ") << abs(this->c) << " = 0";
}

bool QuadraticEquation::hasSolution_v()
{
	return this->hasSolution;
}

bool QuadraticEquation::hasInfSolution_v()
{
    return false;
}

double QuadraticEquation::getLeadingCoefficient()
{
    return this->a;
}

double QuadraticEquation::getFreeCoefficient()
{
    return this->c;
}

double QuadraticEquation::getDiscriminant()
{
    return b * b - 4 * a * c;
}

int32_t QuadraticEquation::type()
{
    return 3;
}
