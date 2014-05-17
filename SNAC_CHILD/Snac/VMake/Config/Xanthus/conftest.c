#include <mpi.h>
#include <StGermain/StGermain.h>
#include <StgDomain/StgDomain.h>
#include <StgFEM/StgFEM.h>
#include <PICellerator/PICellerator.h>
#include "Xanthus/Xanthus.h"


int main( int argc, char** argv ) {
	MPI_Init( &argc, &argv );
	StGermain_Init( &argc, &argv );
	StgFEM_Init( &argc, &argv );
	PICellerator_Init( &argc, &argv );
	Xanthus_Init( &argc, &argv );

	Xanthus_Finalise();
	PICellerator_Finalise();
	StgFEM_Finalise();
	StGermain_Finalise();
	MPI_Finalize();
	return 0;
}
