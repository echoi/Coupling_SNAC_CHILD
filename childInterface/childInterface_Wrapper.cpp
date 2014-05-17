#include "childInterface.h"
#include "childInterface_Wrapper.h"

extern "C" {

	void *ChildInterface_New( void ) {
		childInterface *cI = new childInterface;
		return (void *)cI;
	}

	void ChildInterface_Initialize(const void *childinterface, int argc, char* argv[] ) {
		childInterface *cI = (childInterface *)childinterface;
		cI->Initialize( argc, argv );
	}

	void ChildInterface_Initialize_from_PointSet(const void *childinterface, char* args, int nox, int noy, double*** pts ) {
		string argstr;
		childInterface *cI = (childInterface *)childinterface;

		argstr.append( args );
		// run in the silent mode and don't write any output.
		//argstr.append( " --silent-mode" );
		//argstr.append( " --no-write-mode" );
		cI->Initialize( argstr, nox, noy, pts );
	}

	void ChildInterface_Run(const void *childinterface, double dt=0.0 ) {
		childInterface *cI = (childInterface *)childinterface;
		cI->Run( dt );
	}

	void ChildInterface_ModifyCoords(const void *childinterface, double*** newCoords ) {
		childInterface *cI = (childInterface *)childinterface;
		cI->ModifyCoords( newCoords );
	}

	void ChildInterface_GetNewCoords(const void *childinterface, double*** newCoords ) {
		childInterface *cI = (childInterface *)childinterface;
		cI->GetNewCoords( newCoords );
	}

	void ChildInterface_Delete(const void *childinterface ) {
		childInterface *cI = (childInterface *)childinterface;
		delete cI;
	}
	
}
