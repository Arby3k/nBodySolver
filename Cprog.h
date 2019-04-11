#pragma once
#include "Cplanet.h"
#include <vector>
#include <fstream>

/*  Class of the program
    Holds any "globally" required variables.

*/

class Cprog{
    public:
    // Prints the main menu 
    void printMenu();

    // Runs 3 body simulation with 'Data3Body.txt'
    void threeBody();

    // Runs nBody simulation with user selected data file.
    // Designed to run at larger time steps.
    // Great for Solar system scale simulations.
    void nBody();

    // Runs nBody simulation however is designed to run at
    // smaller timesteps. Great for 2body simulations
    void nBody_Planetary();

    // Function to save the computed data to an output file
    void saveFile(int totalLoops);

    // Function that loads the intial states
    void loadFile(std::string fileName);

    // Function to provide a userinput for possible data file
    void loadFileWithUserInput();

    // Using unit vectors, solves for x/y accelerations on each body
    // For each time step
    // The Exact method is explained in Readme
    void Accelerate();

    // Using the calcualted accelerations, solves for x/y velocities 
    // On each body for each time step
    void Velocities();

    // Using the calcualted velocities, solves for x/y positions 
    // On each body for each time step    
    void Positions();

    // Total number of bodies in calcualtion
    int bodies;

    // Time Step in seconds
	float timeStep;
    // Total days to run simulation
    float totalDays;

    // Time Step in days (Used to calculate loops of calculations)
    int timeStepDays;
    // Total Years to run simulation.
    int totalYears;

    private:
    std::vector<Cplanet> planets;
};
