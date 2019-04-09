#include "Cprog.h"
#include "Cplanet.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>
#include <math.h>

#define PI 3.14159265358979
#define G  6.67384e-11            // gravitational constant in m^3/kg * s^2;
#define M_EARTH 5.97219e24        // earth mass [kg]
#define R_EARTH 6.371e6           // earth radius [m]
#define T_GEOSTATIC  86164.0905         // earth rotational period [s]
#define Day_Second_Converstion 86400    // Day to second conversion for loop calcualtions

using namespace std;

void Cprog::printMenu(){
    std::cout<<"******************** \n"
             << "Planetary motion things \n"
             << "******************** \n"
             << "A) Pre Loaded 3Body \n"
             << "B) nBody Simulation on Solar System Time Scale \n"
             << "C) nBody Simulation on Planetary Time Scale \n"
             << "Q) quit \n"
             << "\nCommand: ";

}

void Cprog::threeBody(){
    
    string threeBodyFile = "Data3Body.txt"; 
    loadFile(threeBodyFile);
    
    for(int i = 0; i <bodies; i++){
        planets[i].xposSave.push_back(planets[i].xpos);
        planets[i].yposSave.push_back(planets[i].ypos);
    }

    cout << "\n[Recommended 1000 seconds]\nTime Step in seconds:";
	cin >> timeStep;
    cout <<"\n[Recommended 20 Days]\nHow long should we run this simulation for? (In Days):";
    cin >> totalDays;
    cout << "\n";

    int totalLoops = 0;

    totalLoops  = (totalDays*Day_Second_Converstion)/timeStep;

    cout << "X pos        Y Pos\n";
    for (int i = 0; i < totalLoops; i++) {
        Accelerate();
        Velocities();
		Positions();
        cout << "Running\r";
 	}

    saveFile(totalLoops);

}

void Cprog::nBody(){

    loadFileWithUserInput();
    cout << "\nTime Step in days:";
	cin >> timeStepDays;
    cout <<"\nHow long should we run this simulation for? (In Years):";
    cin >> totalYears;
    cout << "\n";

    int totalLoops = 0;

    totalLoops  = (totalYears*365)/timeStepDays;

    timeStep = timeStepDays*Day_Second_Converstion;

    for(int i = 0; i <bodies; i++){
        planets[i].xposSave.push_back(planets[i].xpos);
        planets[i].yposSave.push_back(planets[i].ypos);
    }

    for (int i = 0; i < totalLoops; i++) {
        Accelerate();
        Velocities();
		Positions();
		cout << "Running\r";
 	}
	
	saveFile(totalLoops);
	
}

void Cprog::nBody_Planetary(){

    loadFileWithUserInput();

    cout << "\nThis Simulation keeps the first body in simlualtion locked to inital position."
         << "\nThis is done to allow to visual geostationary orbits without main planet drifting.";

    cout << "\n\nTime Step in seconds:";
	cin >> timeStep;
    cout <<"\nHow long should we run this simulation for? (In Days):";
    cin >> totalDays;
    cout << "\n";

    float totalLoops = 0;

    totalLoops  = (totalDays*Day_Second_Converstion)/timeStep;

 
    for(int i = 0; i <bodies; i++){
        //First X and Y Postions of planets put into 
        planets[i].xposSave.push_back(planets[i].xpos);
        planets[i].yposSave.push_back(planets[i].ypos);
    }

    cout << "X Accel       Y Accel       XVel     YVel    XPos  vPos\n";

    for (int i = 0; i < totalLoops; i++) {
        Accelerate();
        planets[0].xacc = 0; //Keep Earth Centered
        planets[0].yacc = 0; //Keep Earth Centered

        cout << planets[1].xacc <<"      " << planets[1].yacc <<"      ";

        Velocities();
        cout << planets[1].xvel <<"      " << planets[1].yvel <<"      ";

		Positions();
        cout << planets[1].xpos <<"      " << planets[1].ypos << "\n";

		cout << "Running\r";
 	}
	
	saveFile(totalLoops);
	
}

void Cprog::saveFile(int totalLoops){
    
	string fileName;
	string fileType = ".txt";
	std::cout << "\nName Save file (do not include '.txt')\n";
	cin >> fileName;
	fileName.append(fileType);

	ofstream saved(fileName);
	if (!saved) {
		std::cout << "Error saving file for output" << endl;
		return ;
	}
    saved << timeStep << endl;
    saved << bodies << endl;

	for (int i = 0; i < totalLoops; i++) {
        for(int j = 0; j < bodies; j++){
		    saved << std::scientific << planets[j].xposSave[i] << "," << planets[j].yposSave[i];
            cout << "Saving\r";
            if(j != bodies-1){
                saved << ",";
            }
            else{
                saved << endl;
            }
        }
	}
	cout << "File Saved\n\n";
	saved.close();
	return ;

}

void Cprog::loadFileWithUserInput(){
    string fileName;
    string fileType = ".txt";
    
    cout << "\nName of File (Do not include '.txt')\n";
    cin >> fileName;
    fileName.append(fileType);
    loadFile(fileName);
}

void Cprog::loadFile(string fileName){
    Cplanet planet;
    string loadedData;
	string skippedData;

    this->planets.clear();
    ifstream saved(fileName);
    if (!saved){
        cout <<"Error Loading data File\n";
        cout <<"If Running 3 body, make sure 3 body file is named correctly\n";
        cout <<"'Data3Body.txt'\n";

		loadFileWithUserInput();
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

            planet.xacc = 0;
            planet.yacc = 0;
            
            this->planets.push_back(planet);
            
        }
        cout <<"File Loaded \n";
        saved.close();
    }
}

void Cprog::Accelerate() {
    for (int i = 0; i < bodies; ++i) {
        for (int j = 0; j < bodies; ++j) {
            if (i != j) {
                double rTemp = sqrt(pow(planets[i].xpos - planets[j].xpos ,2) + pow(planets[i].ypos - planets[j].ypos , 2));
                double temp = G * planets[j].mass / pow(rTemp, 3);
                planets[i].xacc = ((planets[j].xpos - planets[i].xpos) * temp);
				planets[i].yacc = ((planets[j].ypos - planets[i].ypos) * temp);
            }
        }
    }
}

void Cprog::Velocities() {
    for (int i = 0; i < bodies; ++i) {
        planets[i].xvel = planets[i].xvel + (planets[i].xacc * timeStep);
        planets[i].yvel = planets[i].yvel + (planets[i].yacc * timeStep);
    }
}

void Cprog::Positions() {
    for (int i = 0; i < bodies; ++i) {
        planets[i].xpos = planets[i].xpos + (planets[i].xvel * timeStep);
        planets[i].ypos = planets[i].ypos + (planets[i].yvel * timeStep);

        planets[i].xposSave.push_back(planets[i].xpos);
        planets[i].yposSave.push_back(planets[i].ypos);

    }
}

