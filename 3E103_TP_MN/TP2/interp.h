#ifndef _interp_h_
#define _interp_h_

	// Bibliotheques "standardes"
	#include <math.h>
	// Bibliotheques "personnelles"	
	#include "nuageDePoints.h"
	
	typedef struct {
		int degre;
		double* A;	// Coefficients a_i du polynome
		double* C;	// Centres c_i du polynome
	} Polynome;

	Polynome creerPolynome( int N );
	void freePolynome( Polynome* p );
	double pEval( Polynome p, double t );
	Polynome diffDiv( NuagePts nPts );
	NuagePts interpol( NuagePts nPts, int M, double* xI );

#endif
