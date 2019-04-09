#pragma once 
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
		in a vector to allow easy save output

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