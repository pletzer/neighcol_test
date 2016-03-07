#include <mpi.h>

#define FALSE 0
#define TRUE 1

/* Run with 12 processes */
int main(int argc, char *argv[]) {

    int rank, size;
    MPI_Comm vu;
    int dim[2],period[2],reorder;
    int coord[2],id;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    if (size != 12) {
        printf("Must run on 12 processors\n");
        MPI_Finalize();
        return 1;
    }

    dim[0]=4; dim[1]=3;
    period[0]=TRUE; period[1]=FALSE;
    reorder=TRUE;
    MPI_Cart_create(MPI_COMM_WORLD,
        2, dim, period, reorder, &vu);

    if(rank==5){
        MPI_Cart_coords(vu,rank,2,coord);
        printf("P:%d My coordinates are %d %d\n",
            rank, coord[0], coord[1]);
    }

    if(rank==0) {
    coord[0]=3; coord[1]=1;
    MPI_Cart_rank(vu, coord, &id);
    printf("The processor at position (%d, %d) has rank %d\n",
        coord[0], coord[1], id);
    }

    MPI_Finalize();

    return 0;
}
