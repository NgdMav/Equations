#pragma once
#include "Equations.h"
#include <cmath>
class QuadraticEquation :
    public Equations
{
private:
    double a = 1;
    double b;
    double c;
    double root1 = 0;
    double root2 = 0;
    bool hasSolution = false;
public:
    QuadraticEquation();
    QuadraticEquation(double, double, double);
    bool solve() override;
    void solve(std::ostream&) override;
    void print(std::ostream&) override;
    bool hasSolution_v() override;
    bool hasInfSolution_v() override;
    double getLeadingCoefficient() override;
    double getFreeCoefficient() override;
    double getDiscriminant() override;
    int32_t type() override;

};