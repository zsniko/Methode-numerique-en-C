#ifndef _nuageDePoints_h_
#define _nuageDePoints_h_

	// Bibliotheques "personnelles"	
	#include "point.h"
	#include "listeSC.h"

	// Definition des structures
	typedef struct NuagePts{
		ListeSC* points;
	} NuagePts;
	
	// Constructeur et Destructeur
	/** Creation d'un nuage de points
	  * @return un nuage de points pret a l'emploi
	  */
	NuagePts creerNuagePts( );
	
	/** Suppression d'un nuage de points
	  * @param liste le nuage de points a supprimer
	  */
	void freeNuagePts( NuagePts* liste );

	
	// Methode de lecture / d'ecriture de liste dans un fichier
	/** Lecture d'un nuage de points depuis un fichier
	  * @param nomFichier nom et emplacement du fichier ou lire
	  * @return le nuage de points lu
	  */
	NuagePts lireNuagePts( char* nomFichier );
	
	/** Ecriture d'un nuage de points dans un fichier
	  * @param nomFichier nom et emplacement du fichier ou ecrire
	  * @param liste nuage de points a ecrire
	  */
	void ecrireNuagePts( char* nomFichier, NuagePts liste );


	// Methode d'affichage	
	/** Affichage d'un nuage de points
	  * @param liste le nuage de points a afficher
	  */
	void afficherNuagePts( NuagePts liste );
	
#endif
