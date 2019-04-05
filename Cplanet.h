#pragma once 

//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

/* Class that holds planet data
	Positions
	Velocities
	Accelerations
	Mass

	Also holds all previous positions

*/

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
		
		std::vector<double> xposSave;
		std::vector<double> yposSave;

};