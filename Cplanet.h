#pragma once 

//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class Cplanet {
	friend class Cprog;
	private:
		
		double xpos;
		double ypos;
		double xvel;
		double yvel;
        double mass;
		double xacc;
		double yacc;
		void print();

		std::vector<double> xposSave;
		std::vector<double> yposSave;

};