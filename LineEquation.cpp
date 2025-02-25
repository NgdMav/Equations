#include "LineEquation.h"

LineEquation::LineEquation()
{
	this->k = 1;
	this->b = 0;
	this->hasSolution = true;
	this->root = 0;
}

LineEquation::LineEquation(double initk, double initb)
{
	this->k = initk;
	this->b = initb;
	this->solve();
}

bool LineEquation::solve(){
	if (abs(k) < 0.000001) {
		this->hasSolution = false;
		return false;
	}
	this->hasSolution = true;
	this->root = (-this->b / this->k);
	return true;
}

void LineEquation::solve(std::ostream& out) {
	if (this->hasSolution) {
		out << "Root = " << this->root;
	}
	else {
		out << "No solution for this equation";
	}
}

void LineEquation::print(std::ostream& out) {
	out << "Equation: " << this->k << "x" << ((this->b >= 0) ? " + " : " - ") << abs(this->b) << " = 0";
}

bool LineEquation::hasSolution_v()
{
    return this->hasSolution;
}

bool LineEquation::hasInfSolution_v()
{
    if(this->k == 0 && this->b == 0){
		return true;
	}
	return false;
}

double LineEquation::getLeadingCoefficient()
{
    return this->k;
}

double LineEquation::getDiscriminant()
{
	return 0.0;
}

int32_t LineEquation::type()
{
    return 2;
}
