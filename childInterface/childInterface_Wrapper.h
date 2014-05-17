#ifndef CHILDINTERFACE_WRAPPER_H
#define CHILDINTERFACE_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

	void * ChildInterface_New( void );
	void ChildInterface_Initialize(const void *, int, char**);
	void ChildInterface_Initialize_from_PointSet(const void *childinterface, char* args, int nox, int noy, double*** pts );
	void ChildInterface_Run(const void *, double );
 	void ChildInterface_ModifyCoords(const void *, double*** pts);
 	void ChildInterface_GetNewCoords(const void *, double*** pts);
	void ChildInterface_Delete(const void *);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CHILDINTERFACE_WRAPPER_H
