# Assignment 12

The goal of this assignment is to experiment with accelerator programming using SYCL.

## Exercise 1 (2 Points)

This exercise consists in porting the main computation of the heat stencil application from pure C++ to SYCL.

### Description

- A sequential C++ implementation of a 1-D heat stencil is available in [heat_stencil_1d.cpp](heat_stencil_1d/heat_stencil_1d.cpp). Read the code and make sure you understand what happens.
- Make sure you can compile the sequential and a future SYCL version of the source code. A minimal CMake build infrastructure is provided and can be used as follows

```bash
mkdir build && cd build
cmake .. -DCMAKE_PREFIX_PATH="/scratch/c703429/software/adaptivecpp/lib/cmake/AdaptiveCpp/"
make -j2
```

- Port the pure C++ version to SYCL to be run on an accelerator (e.g. a GPU). A copy of the source code, to be edited, is available in [heat_stencil_1d_sycl.cpp](heat_stencil_1d/heat_stencil_1d_sycl.cpp). Note that while our experiment platform LCC3 does not provide any accelerators, you can still run the SYCL code using the OpenMP CPU backend of AdaptiveCPP.
- For this exercise, you can remove the periodic data output on the terminal.
- Benchmark your SYCL version using varying numbers of OpenMP threads (environment variable `OMP_NUM_THREADS`). Discuss the effects and implications of your parallelization.
- Insert the measured wall time for N=2400 and T=50000 into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p6d9F12EtykmI2-7MnHkg0U15UAtaCvWz8Ip92ZEsWo

## Exercise 2 (1 Point)

This exercise consists in extending the SYCL port of Exercise 1 to include the periodic data output on the terminal.

### Tasks

- Extend the solution of Exercise 1 to include the period data output on the terminal. For this purpose, add a second SYCL kernel that properly copies the data before printing, as the SYCL kernel can run on a device (e.g. GPU) for which you can not directly access and print data on a terminal.
- Benchmark your SYCL version using varying numbers of OpenMP threads (environment variable `OMP_NUM_THREADS`). Discuss the effects and implications of adding this data output.
- Insert the measured wall time for N=2400 and T=50000 into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p6d9F12EtykmI2-7MnHkg0U15UAtaCvWz8Ip92ZEsWo
