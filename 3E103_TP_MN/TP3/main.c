#include "integrale.h"

#define RES_CLASSIC "/Users/nikosoung/Desktop/Informatique/TP/TP3/resultats/intClassique.txt"
#define RES_QUADRA "/Users/nikosoung/Desktop/Informatique/TP/TP3/resultats/intQuadra.txt"
#define N 20

int main( ) {
	Integrale iC = { 1, 2 };
	Integrale iGLe = {0, 2};
	Integrale iT = {1, 3};
	Integrale iGLa = {1, 1};
	Integrale iGH = {0, 2};
	int n;

	FILE *fClassic = fopen( RES_CLASSIC, "w" );
	FILE *fQuadra = fopen( RES_QUADRA, "w" );
	for( n = 1; n <= N; n++ ) {
		iC.nbIntervalles = n;
		fprintf( fClassic, "%d %lf ", n, intClassic( iC, 1, 3 ) );
		fprintf( fClassic, "%lf ", intClassic( iC, 2, 3 ) );
		fprintf( fClassic, "%lf ", intClassic( iC, 3, 3 ) );
		fprintf( fClassic, "%lf \n", intClassic( iC, 4, 3 ) );
		
		iGLe.nbIntervalles = n;
		fprintf( fQuadra, "%d %lf ", n, intQuadrature( iGLe, 0, 4 ) );
		iT.nbIntervalles = n;
		fprintf( fQuadra, "%lf ", intQuadrature( iT, 1, 2 ) );
		fprintf( fQuadra, "%lf ", intQuadrature( iT, 2, 2 ) );
		iGLa.nbIntervalles = n;
		fprintf( fQuadra, "%lf ", intQuadrature( iGLa, 3, 2 ) );
		iGH.nbIntervalles = n;
		fprintf( fQuadra, "%lf \n", intQuadrature( iGH, 4, 1 ) );		
	}
	fclose( fClassic );
	fclose( fQuadra );

	return 0;
}
