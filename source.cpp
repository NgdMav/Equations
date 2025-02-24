#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <type_traits>
#include "Equations.h"
#include "LineEquation.h"
#include "QuadraticEquation.h"

void CheckFile(std::ofstream&);
bool comparatorForSort(Equations*, Equations*);

int main() {
    srand(time(NULL));
	std::ofstream fout("output.txt");
	try
	{
		CheckFile(fout);
	}
	catch(const char* e)
	{
		std::cout << e;
	}
	
	std::vector<Equations*> vect;
	try
	{
        for (size_t i = 0; i < 5; ++i) {
			Equations* eq = new LineEquation((rand() % 21) - 10, rand() % 21 - 10);
            vect.push_back(eq);
			eq = new QuadraticEquation((rand() % 5) + 1, rand() % 21 - 10, rand() % 21 - 10);
			vect.push_back(eq);
        }
        
        for (auto i = vect.begin(); i < vect.end(); ++i) {
            (*i)->print(fout);
            fout << "\n";
            (*i)->solve(fout);
            fout << "\n\n";
        }
		fout << "============================\n\nEquations without solution:\n\n";
		bool hasSuch = false;
		for (auto i = vect.begin(); i < vect.end(); ++i) {
			if (!(*i)->hasSolution_v()) {
				(*i)->print(fout);
				fout << "\n\n";
				hasSuch = true;
			}
		}
		if(!hasSuch) {
			fout << "No such equations\n\n";
		}

		fout << "============================\n\nEquations with infinite solutions:\n\n";
		hasSuch = false;
		for (auto i = vect.begin(); i < vect.end(); ++i) {
			if ((*i)->hasInfSolution_v()) {
				(*i)->print(fout);
				fout << "\n\n";
				hasSuch = true;
			}
		}
		if(!hasSuch) {
			fout << "No such equations\n\n";
		}

		fout << "============================\n\nSorted equations:\n\n";
		sort(vect.begin(), vect.end(), comparatorForSort);
		for (auto i = vect.begin(); i < vect.end(); ++i) {
			(*i)->print(fout);
			fout << "\n\n";
		}
	}
	catch (const char* ex)
	{
		std::cout << ex;
	}
	
	for (auto i = vect.begin(); i < vect.end(); ++i){
		delete (*i);
	}
	return 0;
}

void CheckFile(std::ofstream& file) {
	if (!file) {
		throw "Not created\n";
	}
	if (!file.is_open()) {
		throw "Not opend\n";
	}
}

bool comparatorForSort(Equations* first, Equations* second) {
	return first->getLeadingCoefficient() < second->getLeadingCoefficient();
}