# Assignment 11

The goal of this assignment is to implement two basic applications in the Chapel programming model.

## Exercise 1 (1.5 Points)

### Description

The Chapel programming model has been briefly discussed in the lecture. It is a high-level domain-specific language (DSL) that offers both shared and distributed memory parallelism.

### Tasks

- Download and install Chapel using [this download link](https://chapel-lang.org/download.html) and [this quickstart guide](https://chapel-lang.org/docs/usingchapel/QUICKSTART.html).
> Note: Tested on LCC3 with having only `openmpi/3.1.6-gcc-12.2.0-d2gmn55` and `gcc/12.2.0-gcc-8.5.0-p4pe45v` loaded.
- Implement a parallel version of the Monte Carlo PI computation in Chapel and benchmark it for 1, 2, 6, and 12 threads on LCC3 with a problem size of 1 billion (10^9) samples.
- Implement a parallel version of matrix multiplication in Chapel and benchmark it for 1, 2, 6, and 12 threads on LCC3 with a problem size of 2552x2552.
- Enter your results for 8 threads into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p6d9F12EtykmI2-7MnHkg0U15UAtaCvWz8Ip92ZEsWo

## Exercise 2 (1.5 Points)

### Tasks

- If you haven't already done so, extend your Chapel installation to support distributed memory parallelism using [this guide](https://chapel-lang.org/docs/usingchapel/multilocale.html#readme-multilocale). 
> Note: Run through Exercise 1 first and then alter your configuration for this exercise. Avoid trying Exercise 2 from scratch. Tested on LCC3 with settings `export CHPL_COMM=gasnet CHPL_COMM_SUBSTRATE=mpi MPI_CC=/usr/site/hpc/spack/v0.19-lcc3-20230919/opt/spack/linux-rocky8-westmere/gcc-12.2.0/openmpi-3.1.6-d2gmn55g7hoinwfuk2lc3ibz6odzujak/bin/mpicc`.
- Examples of environment variables to be used on LCC3 when compiling Chapel are `CHPL_LAUNCHER=gasnetrun_mpi` and `CHPL_COMM_SUBSTRATE=mpi`. You can then re-compile your Chapel programs and launch them directly by running `./chapel_program -nl <number_of_locales>` using a job submission script.
- If you haven't already done so, extend your Chapel programs to support distributed memory parallelism.
- Benchmark your distributed memory version for 1, 2, and 6 nodes on LCC3 using 12 threads and enter your results into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p6d9F12EtykmI2-7MnHkg0U15UAtaCvWz8Ip92ZEsWo
