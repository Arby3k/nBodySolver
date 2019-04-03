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
    void saveFile();
    void loadFile();

    float mod();
    void computeAccelerations();
    void computeVelocities();
    void computePositions();

    int bodies;
	int timeStep;
    int totalDays;

    private:
    std::vector<Cplanet> planets;
};
