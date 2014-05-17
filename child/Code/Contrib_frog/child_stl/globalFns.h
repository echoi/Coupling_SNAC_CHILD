//-*-c++-*- 

/**************************************************************************/
/**
**  @file globalFns.h
**  @brief Header file for global functions used by tGrid and other
**         modules of CHILD.
**
**  This file contains geometric functions used for computing and
**  updating triangulations, a function for interpolating values on
**  a regular grid, and several functions for plane- and line-fitting
**  which can be used by interpolation procedures (such as the layer
**  interpolation routines in CHILD).
**
**  $Id: globalFns.h,v 1.19 2004/06/16 13:37:24 childcvs Exp $
*/
/**************************************************************************/

#ifndef GLOBALFNS_H
#define GLOBALFNS_H

#include <math.h>
#include "MeshElements/meshElements.h"
#include "tLNode/tLNode.h"
#include "tPtrList/tPtrList.h"
#include "Predicates/predicates.h"
#include "tMatrix/tMatrix.h"
#include <iostream>
#include <vector>

using namespace std;



// Macros for max, min
#undef max
#undef min
#define max(a, b)               ((a) < (b) ? (b) : (a))
#define min(a, b)               ((a) > (b) ? (b) : (a))


extern Predicates predicate; // object should be declared elsewhere, e.g. main

/******** Global Function Declarations **************************************/
vector< double > UnitVector( tEdge const * );
vector< double > UnitVector( double, double );

vector< double > NewUnitVector( tEdge * );

double FindCosineAngle0_2_1( vector< double > const &, vector< double > const &,
                             vector< double > const & );

int TriPasses( vector< double >, vector< double >,
               vector< double >, vector< double >);

bool PointsCCW( vector< double >, vector< double >, vector< double >);

// bool PointsCCW( tArray2< double > const &, tArray2< double > const &, tArray2< double > const & );

int Orientation( vector< double >,
                 vector< double >,
                 vector< double >);

int NewTriCCW( tTriangle const * );

int InNewTri( vector< double >, tTriangle const * );

template< class tSubNode >
int Next3Delaunay( tPtrList< tSubNode > &, tPtrListIter< tSubNode > & );

int Intersect( tEdge *, tEdge * );

tEdge* IntersectsAnyEdgeInList( tEdge*, tPtrList< tEdge >& );

double InterpSquareGrid( double, double, tMatrix< double > const &, int );

vector< double > FindIntersectionCoords( vector< double >,
					  vector< double >,
					  vector< double >,
					  vector< double >);

//double timetrack;

//Returns z value at location x,y on the plane defined by the
//x-y coordinates in p0, p1, and p2, and their zvals in the zs array
double PlaneFit(double x, double y, vector<double> const &p0,
                vector<double>const & p1, vector<double> const &p2, vector<double> const &zs);

double LineFit(double x1, double y1, double x2, double y2, double nx);

double DistanceBW2Points(double x1, double y1, double x2, double y2 );

#endif
