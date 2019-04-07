# nBody Celestial System Solver

Can solve nBody problems using Newton's Laws of Motion and gravitation.

![build status](http://img.shields.io/travis/izaakschroeder/s3-streams/master.svg?style=flat)


Newton's laws of motion allow us to calculate the postion of celestial bodies at specific times using user input time steps 


Features:
 * Solves Preloaded 3 body system ,
 * Solves nBody system loaded through txt file
 

## Usage

For both options available to the user, the user must select total time to run simulation along with a timestep that will dictate the accuracy of the results. 


### Input Files
Input text files must follow formatting as shown below 

```sh

3               # number of bodies
5.97219e24      # body 1 mass [kg]
0.0             # body 1 initial x-pos [m]
0.0             # body 1 initial y-pos [m]
0.0             # body 1 initial Vx [m/s]
0.0             # body 1 initial Vy [m/s]
5.97219e22      # body 2 mass [kg]
1.0e8           # body 2 x-pos [m]
0.0             # body 2 y-pos [m]
0.0             # body 2 initial Vx [m/s]
1.99643e3       # body 2 initial Vy [m/s]
5.97219e20      # body 3 mass [kg]
1.1e8           # body 3 x-pos [m]
0.0             # body 3 y-pos [m]
0.0             # body 3 initial Vx [m/s]
1.39750e3       # body 3 initial Vy [m/s]

```

Each Body must have intial velocity and postion conditions stated.

## Output files

The Output files will be output as show below. This is to allow the `planetary motion viewer` software to run a visual simulation of your output. 


```sh

1000
3
0.000000e+00,0.000000e+00,1.000000e+08,0.000000e+00,1.100000e+08,0.000000e+00
4.018684e+02,0.000000e+00,9.996054e+07,1.996430e+06,1.099272e+08,1.397500e+06
1.205688e+03,8.003940e+00,9.988162e+07,3.992040e+06,1.097815e+08,2.796979e+06

```
X and Y positions for each time step and each body are output on a per line basis. 
The first Line is time step used for calculations, while the second line is the total number of bodies in the program. 


