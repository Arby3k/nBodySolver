//#include "stdafx.h"

#include "Cprog.h"

#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>

// OpenCV Include
//#include "opencv.hpp"

// OpenCV Library
#pragma comment(lib,".\\opencv\\lib\\opencv_world310d.lib")

using namespace std;
#define PI 3.14159265358979
#define G  6.67384e-11            // gravitational constant in m^3/kg * s^2;
#define M_EARTH 5.97219e24        // earth mass [kg]
#define R_EARTH 6.371e6           // earth radius [m]
#define T_GEOSTATIC  86164.0905;  // earth rotational period [s]



int main()
{
	Cprog GeoProg;

	char inputSelect;
	string iSelect;

	do {
	 GeoProg.printMenu();
				
		cin >> inputSelect;
		
		switch (inputSelect){

		case 'A':
		case 'a': {
			GeoProg.threeBody();
			break;
		}
		case 'B':
		case 'b': {
			GeoProg.nBody();
			break;
		}
		case 'Q':
		case 'q':
			cout << "Quiting" << endl;
			exit(0);
			break;
		default:
			cout << "Command not found\n";
			inputSelect = 0;
			break;

		}
		if (inputSelect != 0) {
			cout << "Back to Main Menu?(y/n): ";
			cin >> inputSelect;
		} 
		

	} while (inputSelect == 'Y' || inputSelect == 'y'|| inputSelect == 0);
		
	return 0;

}

