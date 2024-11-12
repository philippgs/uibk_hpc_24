# Assignment 7

The goal of this assignment is to implement your parallelization and optimization plan of the n-body simulation of Assignment 6 and experiment with load imbalance.

## Exercise 1 (2 Points)

### Tasks

- Provide an MPI implementation of your parallelization and optimization plan for the n-body simulation of Assignment 6.
- Measure the speedup and efficiency for multiple problem and machine sizes as in previous exercises. If your parallelization and optimization are orthogonal code modifications, try to measure the impact of your optimization separately.
- Illustrate the data in appropriate figures and discuss them. What can you observe? Did the implementation meet your expectations from Assignment 6?
- Add your best parallel wall time for 96 cores, 5000 particles, and 100 time steps into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p6d9F12EtykmI2-7MnHkg0U15UAtaCvWz8Ip92ZEsWo.

## Exercise 2 (1 Point)

### Tasks

- Modify your n-body simulation to investigate spatial load imbalance by comparing two cases, with initial particle velocity set to 0:
  - Generate all particle locations using a uniform distribution
  - Generate all particles in one corner extending a maximum of 10% in each dimension, e.g. from (0,0,0) to (0.1,0.1,0.1)
- Compare the performance to that of Exercise 1, how are speedup and efficiency affected?
- Add your best parallel wall time for 96 cores, 5000 particles, and 100 time steps into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p6d9F12EtykmI2-7MnHkg0U15UAtaCvWz8Ip92ZEsWo.
