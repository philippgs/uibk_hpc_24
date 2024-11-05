# Assignment 6

The goal of this assignment is to implement a 3D n-body simulation.

## Exercise 1 (2 Points)

### Description

N-body simulations are one of the 7 original dwarfs of HPC and are used in research ranging from astrophysics to molecular dynamics. At their core, they model and simulate the interaction of moving particles in physical space. For this assignment, the specific n-body setting relates to astrophysics, where the mutual gravitational effect of stars is investigated. Each particle has several properties which include at least

- position,
- velocity, and
- mass.

For each timestep (you can assume `dt = 1`), particles must be moved by first computing the force exerted on them according to the [Newtonian equation for gravity](https://en.wikipedia.org/wiki/Newton%27s_law_of_universal_gravitation), `force = G * (mass_1 * mass_2) / radius^2` where `G` is the gravitational constant (and can be assumed as `G = 1` for simplicity). Second, using the computed force on a particle, its position and velocity can be updated via `velocity = velocity + force / mass` and `position = position + velocity`.

### Tasks

- Provide a sequential implementation of the n-body simulation in 3D. While making any implementation design decisions, consider that this application will have to be parallelized using MPI in a future assignment. Hints on how to proceed (not mandatory to follow):
    1. generate particles randomly, e.g. uniformly distributed
    2. provide a function for computing forces and moving particles
    3. move particles in a time loop for a given number of steps
- Measure the execution time for various particle numbers and timesteps. What can you observe?
- Write your data to a file (e.g. `data.dat` ) and use any visualization tool to visualize the movement of the data.
  - [Here is an example](particle.plt) using `gnuplot`. Adapt this file according to your particle range implementation and any other needs.
  - The data for this example visualization has to be in following format, showing x, y, and z coordinates per particle on one line:

    ````text
        x1_timestep1 y1_timestep1 z1_timestep1
        x2_timestep1 y2_timestep1 z2_timestep1
        x3_timestep1 y3_timestep1 z3_timestep1
    
    
        x1_timestep2 y1_timestep2 z1_timestep2
        x2_timestep2 y2_timestep2 z2_timestep2
        x3_timestep2 y3_timestep2 z3_timestep2
    
    
        x1_timestep3 y1_timestep3 z1_timestep3
        x2_timestep3 y2_timestep3 z2_timestep3
        x3_timestep3 y3_timestep3 z3_timestep3
    ````

       Having 2 blank lines means the points for this timestep are finished. Note that all values can be floating point numbers.
- For measuring performance either disable writing to a datafile or consider not dumping each timestep. Measure only the actual n-body simulation, not any initialization or data I/O.
- Benchmark the sequential program using 5000 particles and 100 time steps and enter the results into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p6d9F12EtykmI2-7MnHkg0U15UAtaCvWz8Ip92ZEsWo

## Exercise 2 (1 Point)

This exercise consists in investigating and planning optimization and parallelization techniques for Exercise 1.

### Tasks

- Study the nature of the problem in Exercise 1, focusing on its characteristics with regard to optimization and parallelization with MPI.
- What optimization methods can you come up with in order to improve the performance of Exercise 1?
- What parallelization strategies would you consider for Exercise 1 and why?
