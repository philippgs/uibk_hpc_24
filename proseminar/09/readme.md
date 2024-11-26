# Assignment 09

The goal of this assignment is to investigate parallel I/O using MPI.

## Exercise 1 (2 Points)

This exercise consists in comparing different implementations for writing and reading files using MPI I/O.

### Description

Almost all major HPC hardware platforms have maximum job wall times of 24-72 hours. Since most applications require much longer simulation times, they inherently need to support checkpoint and restart, which means they write the simulation state to persistent storage and can resume by reading previously written data, minimizing the need for repeating simulation steps in case of crashes. In this exercise, we will simulate the I/O part of such an application, omitting computation and communication as much as possible for simplicity.

### Tasks

- Provide a program that uses MPI I/O in order to read and write a one-dimensional buffer to persistent storage.
- Ranks should be responsible for reading and writing equally-sized, disjunct regions within your buffer (for simplicity, one region per rank). You can use derived data types (e.g. subarray) to model these regions. The actual data is irrelevant for this exercise, but choose something that can be easily debugged and verified for small file sizes and rank numbers (e.g. have every rank write repeated `char` elements of value `(char)rankID + 'A'` - the data does not have to change during the execution of your program).
- The file operations should be repetitive, i.e. alternately writing, reading, writing, reading, etc., until the data has been written 10 times (and thus read 9 times). The behavior should be representative of e.g. a time-dependent structured grid simulation except that the computation and communication has been removed.
- Provide four implementation variants for your program, using
  - individual, differently-named files, one per rank (you can choose to use non-MPI means for the actual write operation, such as e.g. `fwrite()`, if you prefer)
  - a single file using individual file pointers
  - a single file using a shared file pointer and non-collective I/O operations
  - a single file using a shared file pointer and collective I/O operations
- Benchmark each implementation with various data sizes and rank numbers on LCC3 while ensuring the following
  - place the file(s) in `$SCRATCH`, not `$HOME`
  - the overall storage footprint per team should not exceed ~10 GB
  - note that you might have to set a special runtime parameter for OpenMPI to get decent performance on LCC3's NFS-mounted storage: `--mca fs_ufs_lock_algorithm 1`
  - make sure to delete any generated files after you finished your benchmark runs
  - ensure that writes have fully completed (i.e. data has been written to the storage medium) before reading it again
- Illustrate the data in appropriate figures and discuss them. What can you observe?
- Insert the achieved bandwidth for 64 MB per rank and 96 ranks into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p6d9F12EtykmI2-7MnHkg0U15UAtaCvWz8Ip92ZEsWo

## Exercise 2 (1 Point)

This exercise consists in implementing a hybrid version of Exercise 1.

### Tasks

- Provide a fifth implementation that makes rank 0 responsible for writing/reading all data to/from a single file, hence requiring `MPI_Gather()` and `MPI_Scatter()` operations. Again, you can choose to use non-MPI means for the I/O operations.
- Compare the performance to your solution of Exercise 1. What can you observe?
- Insert the achieved bandwidth for 64 MB per rank and 96 ranks into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p6d9F12EtykmI2-7MnHkg0U15UAtaCvWz8Ip92ZEsWo
