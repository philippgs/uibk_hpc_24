# Assignment 3

The goal of this assignment is to extend the heat stencil application and measure its performance.

## Exercise 1 (1.5 Points)

This exercise consists in extending the heat stencil application of Assignment 2 to two dimensions.

### Tasks

- Extend the heat stencil application to the two-dimensional case and name it `heat_stencil_2D`.
- Provide a sequential and an MPI implementation. Try to make your implementation as efficient as possible, also with regard to code readability.
- Run your programs with multiple problem and machine sizes and measure speedup and efficiency. Consider using strong scalability, weak scalability, or both. Justify your choice.
- Illustrate the data in appropriate figures and discuss them. What can you observe?
- Measure and illustrate one domain-specific and one domain-inspecific performance metric. What can you observe?
- How can you verify the correctness of your applications?
- Insert the wall times for the sequential version and for 96 cores for `N=768x768` and `T=N*100` into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p6d9F12EtykmI2-7MnHkg0U15UAtaCvWz8Ip92ZEsWo

## Exercise 2 (1.5 Points)

This exercise consists in comparing blocking and non-blocking communication for the heat stencil applications.

### Tasks

- Provide an MPI implementation for the 1D and 2D heat stencil that uses non-blocking communication. If you already implemented a non-blocking version, provide a blocking version, but ensure the non-blocking version works as described below.
- Structure your program such that you 1) start a non-blocking ghost cell exchange, 2) compute the inner cells which do not require the result of the ghost cell exchange, 3) block until the ghost cell exchange has finished, and 4) compute the remaining cells.
- Run your programs with multiple problem and machine sizes and compare both versions.
- Insert wall time for 96 cores for `N=768x768` and `T=N*100` into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p6d9F12EtykmI2-7MnHkg0U15UAtaCvWz8Ip92ZEsWo
