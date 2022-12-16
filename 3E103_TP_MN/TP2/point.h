#ifndef _point_h_
#define _point_h_

	// Bibliotheques "standards"
	#include <stdio.h>
	#include <stdlib.h>

	// Definition des structures
	typedef struct {
		double x;	// Abscisse
		double y;	// Ordonnee
	} Point;
	
	// Constructeur et Destructeur
	/** Creation d'un point
	  * @return un point
	  */
	Point creerPoint( double x, double y );
	
	/** Suppression d'un points
	  * @param pt le point a supprimer
	  */
	void freePoint( Point* pt );


	// Methode d'affichage
	/** Affichage d'un point
	  * @param pt le point a afficher
	  */
	void afficherPoint( Point pt );
	
#endif
