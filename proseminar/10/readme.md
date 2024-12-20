# Assignment 10

The goal of this assignment is to investigate load balancing techniques.

## Exercise 1 (1 Point)

This exercise consists in parallelizing an application that generates a fractal image.

### Description

Maybe you have already heard of **Fractals** or **Mandelbrot**. [Fractals](https://en.wikipedia.org/wiki/Fractal) are geometric patterns that appear to be infinitely detailed. There are many [functions](https://en.wikipedia.org/wiki/List_of_fractals_by_Hausdorff_dimension) that can generate such patterns. The more often you evaluate these functions, the more detailed the pattern becomes.

This task will focus on the [Mandelbrot set](https://en.wikipedia.org/wiki/Mandelbrot_set), a set of complex numbers that is generated by the function *z<sub>n+1</sub>=z<sub>n</sub><sup>2</sup>+c*, where *z* is a complex number and *c* is a constant.
> Short reminder: a complex number *z* is the sum of a real part *x* and an imaginary part *y* that includes the imaginary unit *i* with the property (*i<sup>2</sup>=-1*) &rarr; *z=x+yi*.

### Tasks

- A sequential implementation is available in [mandelbrot_seq.c](mandelbrot/mandelbrot_seq.c). Read the code and make sure you understand what happens. Run it in order to see what the generated image should look like.
- Parallelize the implementation using MPI and name it `mandelbrot_mpi.c`. Run it with varying numbers of ranks and problem sizes and verify its correctness by comparing the output to `mandelbrot_seq.c`.
- Make sure you use the compiler optimization flags as specified in the Makefile.
- Discuss the effects and implications of your parallelization
- Insert the measured wall time for 96 cores and a problem size of 3840x2160 into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p6d9F12EtykmI2-7MnHkg0U15UAtaCvWz8Ip92ZEsWo
- How would you improve program performance?

## Exercise 2 (2 Points)

This exercise consists in implementing load balancing for Exercise 1.

### Tasks

- What are possible load balancing techniques that could be applied to Exercise 1? What are their advantages and disadvantages?
- Implement at least two load balancing methods/variants and evaluate their performance compared to the naive version in Exercise 1. Discuss the effects and implications.
- Insert the best wall time for 96 cores and a problem size of 3840x2160 into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p6d9F12EtykmI2-7MnHkg0U15UAtaCvWz8Ip92ZEsWo
