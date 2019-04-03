#pragma once 

//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class Cplanet {
	friend class Cprog;
	private:
		
		float xpos;
		float ypos;
		float xvel;
		float yvel;
        float mass;
		float xacc;
		float yacc;
		void print();

};