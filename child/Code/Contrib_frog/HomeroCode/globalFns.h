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
#include "tArray/tArray.h"
#include "tArray/tArray2.h"
#include "MeshElements/meshElements.h"
#include "tLNode/tLNode.h"
#include "tPtrList/tPtrList.h"
#include "Predicates/predicates.h"
#include "tMatrix/tMatrix.h"

// Macros for max, min
#undef max
#undef min
#define max(a, b)               ((a) < (b) ? (b) : (a))
#define min(a, b)               ((a) > (b) ? (b) : (a))


extern Predicates predicate; // object should be declared elsewhere, e.g. main

/******** Global Function Declarations **************************************/
tArray< double > UnitVector( tEdge const * );
tArray< double > UnitVector( double, double );

tArray< double > NewUnitVector( tEdge * );

double FindCosineAngle0_2_1( tArray< double > const &, tArray< double > const &,
                             tArray< double > const & );

int TriPasses( tArray< double > const &, tArray< double > const &,
               tArray< double > const &, tArray< double > const & );

bool PointsCCW( tArray< double > const &, tArray< double > const &, tArray< double > const & );

bool PointsCCW( tArray2< double > const &, tArray2< double > const &, tArray2< double > const & );

int Orientation( tArray< double > const &,
                 tArray< double > const &,
                 tArray< double > const & );

int NewTriCCW( tTriangle const * );

int InNewTri( tArray< double > const &, tTriangle const * );

template< class tSubNode >
int Next3Delaunay( tPtrList< tSubNode > &, tPtrListIter< tSubNode > & );

int Intersect( tEdge *, tEdge * );

tEdge* IntersectsAnyEdgeInList( tEdge*, tPtrList< tEdge >& );

double InterpSquareGrid( double, double, tMatrix< double > const &, int );

tArray2< double > FindIntersectionCoords( tArray2< double > const&,
					  tArray2< double > const&,
					  tArray2< double > const&,
					  tArray2< double > const&);

//double timetrack;

//Returns z value at location x,y on the plane defined by the
//x-y coordinates in p0, p1, and p2, and their zvals in the zs array
double PlaneFit(double x, double y, tArray<double> const &p0,
                tArray<double>const & p1, tArray<double> const &p2, tArray<double> const &zs);

double LineFit(double x1, double y1, double x2, double y2, double nx);

double DistanceBW2Points(double x1, double y1, double x2, double y2 );

// BilinearInterp: bilinear interpolation of rectangular grid
inline double BilinearInterp( double x, double y, double dx, double dy,
                              double nodata, tMatrix< double >& z )
{
   assert( &z > 0 );
   assert( dx > 0.0 && dy > 0.0 );
   int maxj = z.getNumRows() - 1;
   int maxi = z.getNumCols() - 1;
   int i = static_cast<int>( x / dx );
   int j = static_cast<int>( maxj - y / dy );
   //int j = y / dy;
   int jy = static_cast<int>( y / dy );
   int jp1 = j + 1;
   int ip1 = i + 1;
   if( jp1 > maxj || ip1 > maxi ) return nodata;
   double xi = static_cast<double>(i) * dx;
   double yj = static_cast<double>(jy) * dy;
   double u = ( x - xi ) / dx;
   double t = ( y - yj ) / dy;
   // make sure point lies in square with data at all
   // four vertices; otherwise, return nodata:
   double z0 = z( j, i );
   if( z0 == nodata ) return nodata;
   double z1 = z( j, ip1 );
   if( z1 == nodata ) return nodata;
   double z2 = z( jp1, ip1 );
   if( z2 == nodata ) return nodata;
   double z3 = z( jp1, i );
   if( z3 == nodata ) return nodata;
   return (1-t)*(1-u)*z3 + t*(1-u)*z0 + t*u*z1 + (1-t)*u*z2;
}


#endif
