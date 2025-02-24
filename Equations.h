#pragma once
#include <iostream>
#include <cmath>
#include <cstdint>

class Equations
{
public:
	virtual bool solve() = 0;
	virtual void solve(std::ostream&) = 0;
	virtual void print(std::ostream&) = 0;
	virtual bool hasSolution_v() = 0;
	virtual bool hasInfSolution_v() = 0;
	virtual double getLeadingCoefficient() = 0;
};