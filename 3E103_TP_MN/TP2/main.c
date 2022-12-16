#include "interp.h"
#include <string.h>

//#define DATA_NAME "/Users/nikosoung/Desktop/Informatique/TP/TP2/data/ex1.txt"
//#define DATA_NAME "/Users/nikosoung/Desktop/Informatique/TP/TP2/data/ex2.txt"
#define DATA_NAME "/Users/nikosoung/Desktop/Informatique/TP/TP2/data/ex4.txt"
#define RES_NAME "/Users/nikosoung/Desktop/Informatique/TP/TP2/data/interpolation.txt"
#define FONCTION_NAME "/Users/nikosoung/Desktop/Informatique/TP/TP2/data/fonction.txt"

int main( ) {
	// 1) On lit x et y
	NuagePts nPts = lireNuagePts( DATA_NAME );
	int N = nPts.points->length;
	// 2) On re-echantillonne x
	int nbPts = 20;
	int M = (N-1)*nbPts + 1;
    int i, j;
	nPts.points->current = nPts.points->root;
	double* xI = calloc( M, sizeof( double ) );
	for( i = 0; i < N-1; i++ ) {
		double xCourant = ((Point*)nPts.points->current->data)->x;
		double xSuivant = ((Point*)nPts.points->current->next->data)->x;
		double step = (xSuivant - xCourant) / nbPts;
		for( j = 0; j < nbPts; j++ ) {
			xI[j + nbPts*i] = xCourant + step*j;
		}
		getNext( nPts.points );
	}
	xI[M-1] = ((Point*)nPts.points->current->data)->x;
	// 3) On interpole y
	NuagePts nPtsI = interpol( nPts, M, xI );
	ecrireNuagePts( RES_NAME, nPtsI );
	if( strcmp( DATA_NAME, "/Users/nikosoung/Desktop/Informatique/TP/TP2/data/ex4.txt" ) == 0 ) {
		// 4) On calcule f = sin( x/2 )e^(-0.1x)
		NuagePts nPtsR = creerNuagePts( );
		for( i = 0; i < M; i++ ) {
			Point pt = { xI[i], sin( xI[i] / 2 ) * exp( -0.1 * xI[i] ) };
			ajout(nPtsR.points,&pt,2);
		}
		ecrireNuagePts( FONCTION_NAME, nPtsR );
		freeNuagePts( &nPtsR );
	}
	// 5) On libere toutes les variables issues de calloc
	free( xI );
	freeNuagePts( &nPts );
	freeNuagePts( &nPtsI );

	return 0;
}
