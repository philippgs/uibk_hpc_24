/*
 * This program does the same operation as an MPI_Bcast() but
 * does it using MPI_Send() and MPI_Recv().  We also time the
 * operation.
 */

#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
	int nprocs; /* the number of processes in the task */
	int myrank; /* my rank */
    int i;
	const int count = 10;
	int tag = 42;  /* tag used for all communication */
	int tag2 = tag + 1; /* extra tag used for what ever you want */
	int good_data = 1;
	int data[count];   /* data buffers */
	MPI_Status status; /* status of MPI_Recv() operation */

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

	for(int i = 0; i < count; i++)
		if(myrank == 0) {
			data[i] = 399; /* initialize the data for rank 0 process only.  */
		} else
			data[i] = i; /* initialize all other data buffers from 0 to count */

	if(myrank == 0) {
		for(int i = 0; i < nprocs; i++) {
			MPI_Send(&data, count, MPI_INT, i, tag, MPI_COMM_WORLD);
		}
	} else {
		MPI_Recv(&data, count, MPI_INT, 0, tag2, MPI_COMM_WORLD, &status);
	}

	MPI_Barrier(MPI_COMM_WORLD);

	/* Check the data everywhere. */

	if(myrank != 0) {
		for(int i = 0; i < count; i++) {
			if(data[i] != 399) {
				good_data = 0;
			}
		}
		if(good_data == 0) {
			fprintf(stdout, "Whoa! The data is incorrect\n");
		} else {
			fprintf(stdout, "Rank %d received correct data\n", myrank);
		}
	}

	MPI_Finalize();

	return 0;
}
