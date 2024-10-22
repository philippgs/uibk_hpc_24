# Assignment 4

The goal of this assignment is to improve the 2D heat stencil application.

## Exercise 1 (3 Points)

This exercises consists in improving the 2D heat stencil application, fixing any existing bugs and/or improving its performance.

### Tasks

- If you need to fix errors, run through the usual debugging workflow detailed in the lecture on debugging:
    1) enable compiler warnings
    2) check with sanitizers
    3) run with a debugging tool of your choice (a working installation of MUST for debugging MPI applications on LCC3 is provided in `/scratch/c703429/software/must-1.9.1`)
- If you are looking to improve performance, do a detailed performance analysis. Use either tools discussed in the lecture (`perf`, `gprof`, `gperftools`, etc.) or any tools you deem fit for generating a performance profile. Provide a report that discusses the most expensive source code locations ("hot spots") along with explaining why they are expensive and how to possibly improve on that. Compare blocking and non-blocking if possible, as well as 1D and 2D if you get bored otherwise.
- Improve your stencil application using the instructions above. When you do, document the improvement you managed to achieve. If you don't, argue why you failed or think you hit the limit.
- If you want to share your performance results of the improved version, insert the final walltime and speedup of the 2D stencil for 96 cores for N=768x768 and T=768x100 into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p6d9F12EtykmI2-7MnHkg0U15UAtaCvWz8Ip92ZEsWo
