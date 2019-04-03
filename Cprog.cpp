#include "Cprog.h"
#include "Cplanet.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>

#define PI 3.14159265358979
#define G  6.67384e-11            // gravitational constant in m^3/kg * s^2;
#define M_EARTH 5.97219e24        // earth mass [kg]
#define R_EARTH 6.371e6           // earth radius [m]
#define T_GEOSTATIC  86164.0905;  // earth rotational period [s]

using namespace std;

void Cprog::printMenu(){
    std::cout<<"******************** \n"
             << "Planetary motion things \n"
             << "******************** \n"
             << "A) 3Body \n"
             << "B) Solarsystem Sim \n"
             << "Q) quit \n"
             << "\nCommand: ";

}

void Cprog::threeBody(){
    
    //loadFile();

    //Run the math
    //Save the finished file output
}
void Cprog::nBody(){

	loadFile();
    cout << "\nTime Step in seconds:";
	cin >> timeStep;
    cout <<"\n";
//	cout << "X Acceleration: " << planets[0].xacc << "\n";
//	cout << "X Acceleration: " << planets[0].yacc << "\n";
//	cout << "X Velocity: " << planets[0].xvel << "\n";
//	cout << "Y Velocity: " << planets[0].yvel << "\n";
//	cout << "X Position: " << planets[0].xpos << "\n";
//	cout << "Y Position: " << planets[0].ypos << "\n";


    cout << "X  Earth" << "    " << "Y  Earth\n";
    cout << planets[0].xpos << "     " << planets[0].ypos << "\n";

    for (int i = 0; i < 100; i++) {
        computeAccelerations();
        computeVelocities();
		computePositions();
        cout << planets[0].xpos << "     " << planets[0].ypos << "\n";
	}
	
	//Run the math
	//Save the finished file output
}

void Cprog::saveFile(){
    //save the data from the work done
}

void Cprog::loadFile(){
    Cplanet planet;
    string fileName;
    string fileType = ".txt";

    string loadedData;
	string skippedData;

    cout << "\nName of File\n";
    cin >> fileName;
    fileName.append(fileType);
    

    this->planets.clear();
    ifstream saved(fileName);
    if (!saved){
        cout <<"Error Loading data File";
        return;
    }
    else{
        getline(saved, loadedData, ' ');
        bodies = std::stoi(loadedData);
		getline(saved, skippedData);
        for (int i = 0; i <(bodies); i++){
            getline(saved, loadedData, ' ');
            planet.mass = std::stof(loadedData);
            
			getline(saved, skippedData);
			getline(saved, loadedData, ' ');
            planet.xpos = std::stof(loadedData);
            
			getline(saved, skippedData);
			getline(saved, loadedData, ' ');
            planet.ypos = std::stof(loadedData);
            
			getline(saved, skippedData);
            getline(saved, loadedData, ' ');
            planet.xvel = std::stof(loadedData);
            
			getline(saved, skippedData);
            getline(saved, loadedData, ' ');
            planet.yvel = std::stof(loadedData);
			getline(saved, skippedData);
            
            this->planets.push_back(planet);
        }
        cout <<"File Loaded \n";
        saved.close();
    }
}

void Cprog::computeAccelerations() {
    for (int i = 0; i < bodies; ++i) {
        for (int j = 0; j < bodies; ++j) {
            if (i != j) {
                float rTemp = sqrt(pow(planets[i].xpos - planets[j].xpos ,2) + pow(planets[i].ypos - planets[j].ypos , 2));
                float temp = G * planets[j].mass / pow(rTemp, 3);
                planets[i].xacc = planets[i].xacc + ((planets[j].xpos - planets[i].xpos) * temp);
				planets[i].yacc = planets[i].yacc + ((planets[j].ypos - planets[i].ypos) * temp);
            }
        }
    }
}

void Cprog::computeVelocities() {
    for (int i = 0; i < bodies; ++i) {
        planets[i].xvel = planets[i].xvel + (planets[i].xacc * timeStep);
        planets[i].yvel = planets[i].yvel + (planets[i].yacc * timeStep);
    }
}

void Cprog::computePositions() {
    for (int i = 0; i < bodies; ++i) {
        planets[i].xpos = planets[i].xpos + (planets[i].xvel * timeStep);
        planets[i].ypos = planets[i].ypos + (planets[i].yvel * timeStep);
    }
}

