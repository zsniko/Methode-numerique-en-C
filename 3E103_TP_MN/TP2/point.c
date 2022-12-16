#include "point.h"

	// Constructeur et Destructeur
	/** Creation d'un point
	  * @param x abscisse
	  * @param y ordonnee
	  * @return un nuage de points pret a l'emploi
	  */
	Point creerPoint( double x, double y ) {
		// On cree la structure
		Point pt = {x, y};
		return pt;
	}

	/** Suppression d'un point
	  * @param pt le point a supprimer
	  */
	void freePoint( Point* pt ) {
		// Rien a faire (pas d'allocation dynamique)
	}

	// Methode d'affichage
	/** Affichage d'un point
	  * @param pt le point a afficher
	  */
	void afficherPoint( Point pt ) {
		printf( "(%lf, %lf) \n", pt.x, pt.y );	
	}
