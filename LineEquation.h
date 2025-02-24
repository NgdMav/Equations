#pragma once
#include "Equations.h"
class LineEquation :
    public Equations
{
private:
    double k;
    double b;
    double root = 0;
    bool hasSolution = false;
public:
    LineEquation();
    LineEquation(double, double);
    bool solve() override;
    void solve(std::ostream&) override;
    void print(std::ostream&) override;
    bool hasSolution_v() override;
    bool hasInfSolution_v() override;
};