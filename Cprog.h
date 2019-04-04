#pragma once
//#include "stdafx.h"
#include "Cplanet.h"
#include <vector>
#include <fstream>

class Cprog{
    public:
    void printMenu();
    void threeBody();
    void nBody();
    void saveFile(int totalLoops);
    void loadFile(std::string fileName);
    void loadFileWithUserInput();


    void computeAccelerations();
    void computeVelocities();
    void computePositions();

    int bodies;
	int timeStep;
    int totalDays;

    int totalYears;

    private:
    std::vector<Cplanet> planets;
};
