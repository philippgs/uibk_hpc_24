# Assignment 1

The goal of this assignment is to get you acquainted with working on a distributed memory cluster as well as obtaining, illustrating, and interpreting measurement data.

## Exercise 1 (1 Point)

### Description

This exercise consists in familiarizing yourself with SLURM job submission.

You received user credentials for the LCC3 cluster. If you did not change the default password, do so **immediately**. You are responsible for this account during this semester.

You can find information about LCC3 at https://www.uibk.ac.at/zid/systeme/hpc-systeme/leo3/ and information about SLURM job submission at https://www.uibk.ac.at/zid/systeme/hpc-systeme/common/tutorials/slurm-tutorial.html.

**Please run any benchmarks or heavy CPU loads only on the compute nodes, not on the login node.**
If you want to do some interactive experimentation, use an *interactive job* as outlined in the tutorial. Make sure to stop any interactive jobs once you are done.

### Tasks

- Study how to submit jobs in SLURM, how to check their state and how to cancel them.
- Prepare a submission script that starts an arbitrary executable, e.g. `/bin/hostname`
- In your opionion, what are the 5 most important parameters available when submitting a job and why? What are possible settings of these parameters, and what effect do they have?
- How do you run your program in parallel? What environment setup is required?

## Exercise 2  (2 Points)

This exercise consists in running an MPI microbenchmark in order to examine the impact of HPC topologies on performance.

### Description

The OSU Micro-Benchmarks suite holds multiple benchmarks that measure low-level performance properties such as latency and bandwidth between MPI ranks (=processes). Specifically, for this exercise, we are interested in the *point-to-point* ones, which exchange messages between 2 MPI ranks.

### Tasks

- Download and build the OSU Micro-Benchmarks available at http://mvapich.cse.ohio-state.edu/download/mvapich/osu-micro-benchmarks-5.8.tgz. Do not forget to set the compiler parameters for `configure`, e.g. `./configure CC=mpicc CXX=mpic++ ...`
- After building, submit SLURM jobs that run the `osu_latency` and `osu_bw` executables.
- Create a table and figures that illustrate the measured data and study them. What effects can you observe?
- Find out more about the hardware that you're running on, e.g. by using `lstopo --of txt` (available via `module load hwloc`). Modify your experiment such that the 2 MPI ranks are placed on
  - different cores of the same socket,
  - different sockets of the same node, and
  - different nodes.
- Amend your table and figures to include these additional measurements. What effects can you observe? How can you verify rank placement without looking at performance?
- How stable are the measurements when running the experiments multiple times?
- Insert the measured time for latency (size 0) and bandwidth (size 1048576) into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p6d9F12EtykmI2-7MnHkg0U15UAtaCvWz8Ip92ZEsWo
