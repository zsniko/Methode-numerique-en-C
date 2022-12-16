#include "interp.h"

/** Methode creant un polynome nul
  * @param N degre du polynome
  * @return le polynome nul p(x) = 0
  */
Polynome creerPolynome( int N ) {
	Polynome p = { N,
					calloc( N+1, sizeof( double ) ),		// Coefficients
					calloc( N+1, sizeof( double ) ) };		// Centres
	// On a un coefficient et centre de plus que le degre
	// car on va de 0 a N
	return p;
}

/** Methode de liberation de la memoire occupee par un polynome
  * @param p le polynome a supprimer
  */
void freePolynome( Polynome* p ){
	free( p->A );	// On detruit les coefficients
	p->A = NULL;
	free( p->C );	// On detruit les centres
	p->C = NULL;
	p->degre = 0;
}

/** Methode calculant la valeur d'un polynome en un point
  * @param p le polynome
  * @param t le point d'interet
  * @return la valeur de p en t
  */

// Evaluation d'un polynome par schema de Horner
// fonction qui calcule la valeur d'un polynome p en t
/* par exemple N=4 donc a0 a1 a2 a3 a4 et c0 c1 c2 c3
   p(x) = a0 + (x-c0)*{a1+(x-c1)*[a2+(x-c2)*(a3+(x-c3)*A4)]
   pX = p.A[4] = a4
   n = 3
   pX = a4*(x-c3)+a3
   n = 2
   pX = [(a4*(x-c3)+a3)*(x-c2)+a2]
   n = 1
   pX = [(a4*(x-c3)+a3)*(x-c2)+a2]*(x-c1)+a1
   n = 0
   pX = {[(a4*(x-c3)+a3)*(x-c2)+a2]*(x-c1)+a1}*(x-c0)+a0
 */
double pEval( Polynome p, double t ) {
	
    double pX = p.A[p.degre];
    int n;
    
    for(n = p.degre-1;n>=0;n--) {
        pX = pX * (t - p.C[n]) + p.A[n];
    }
    
	return pX;
}

/** Methode calculant le polynome d'interpolation par differences finies
  * @param nPts liste simplement chainee de points (le nuage a interpoler)
  * @return un polynome de degre N passant par (x,y)
  */
Polynome diffDiv( NuagePts nPts ) {
	
    int N = nPts.points->length; // nombre de points
    double* x = calloc(N,sizeof(double));
    double* y = calloc(N,sizeof(double));
    int l = 0; // compteur pour la boucle
    // obtenir les points stockes dans la liste nPts.points
    for(nPts.points->current = nPts.points->root;hasNext(nPts.points);getNext(nPts.points)){
        Point* pt = ((Point*)(nPts.points->current->data));
        x[l] = pt->x;
        y[l] = pt->y;
        l++;
    }
    
    // creation d'une matrice triangulaire
    // mettre les valeurs de y dans la 1ere colonne
    double **matDF = malloc( N * sizeof(double*));
    for( l = 0; l < N; l++){
        matDF[l] = calloc(l+1,sizeof(double));
        matDF[l][0] = y[l]; // mettre les valeurs de y dans la 1ere colonne
    }
    
    // calcul des valeurs de f[x0...xn] sur la diagonale donc les solutions
    for( l = 0; l < N ; l++) {
        for (int c = 1; c <= l ; c++){
            matDF[l][c] = (matDF[l][c-1] - matDF[l-1][c-1]) / (x[l] - x[l-c]);
        }
    }
    
    // creation d'un polynome
    Polynome pDF = creerPolynome(N);
    
    // Polynome d'interpolation
    for(l=0;l<N;l++){
        // les coefficients sont les valeurs de la diagonale de matDF
        pDF.A[l] = matDF[l][l];
        // les centres sont les valeurs de x0 a xN
        pDF.C[l] = x[l];
    }
    
    return pDF;
}

/** Methode interpolant les couples (x, y) en xI via les differences finies
  * @param nPts liste simplement chainee de points (le nuage a interpoler)
  * @param M le nombre de points en sortie
  * @param xI les abscisses des points en sortie
  * @return le nuage de Points interpole
  */
NuagePts interpol( NuagePts nPts, int M, double* xI ) {
    
    // interpoler le nuage des points envoye et stocker dans pI de type Polynome
    Polynome pI = diffDiv(nPts);
    int n;
    NuagePts nPtsI = creerNuagePts(); // nuage de points interpole
    
    for(n=0;n<M;n++){
        // il faut aussi un POINT pour mette dans la liste des points
        Point ptI = {xI[n],pEval(pI, xI[n])};
        printf("%lf\n",ptI.y);
        ajout(nPtsI.points,&ptI,2);
    }
    
    freePolynome(&pI);
    
    return nPtsI;
    
}
