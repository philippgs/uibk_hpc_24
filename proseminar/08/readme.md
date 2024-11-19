# Assignment 8

The goal of this assignment is to study the effect of one-sided communication.

## Exercise 1 (3 Points)

### Tasks

- Replace your two-sided communication in the n-body application of Assignment 6/7 (uniform particle distribution case) with a one-sided method of your choice. Which one did you choose and why? Are there any trade-offs with respect to the other one-sided methods available in MPI, and if so, what are they?
- Measure the speedup and efficiency for multiple problem and machine sizes as in previous exercises and compare to two-sided communication. If you have time, try to force stronger speedup effects by e.g. sending individual particles/forces in dedicated communication calls.
- Illustrate the data in appropriate figures and discuss them. What can you observe?
- Add the maximum number of particles that can be computed over 10000 timesteps in under 10 seconds on 96 ranks into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p6d9F12EtykmI2-7MnHkg0U15UAtaCvWz8Ip92ZEsWo.
