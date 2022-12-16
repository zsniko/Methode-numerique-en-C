#include "nuageDePoints.h"

	// Constructeur et Destructeur
	/** Creation d'un nuage de points
	  * @return un nuage de points pret a l'emploi
	  */
	NuagePts creerNuagePts( ) {
		// On cree la structure
		NuagePts liste;
		// On initialise la tete de liste
		liste.points = creerListe( sizeof(Point) );
		return liste;
	}

	/** Suppression d'un nuage de points
	  * @param liste le nuage de points a supprimer
	  */
	void freeNuagePts( NuagePts* liste ) {
		freeListe( liste->points );
	}


	// Methode de lecture / d'ecriture de liste dans un fichier
	/** Lecture d'un nuage de points depuis un fichier
	  * @param nomFichier nom et emplacement du fichier ou lire
	  * @return le nuage de points lu
	  */
	NuagePts lireNuagePts( char* nomFichier ) {
		NuagePts res = creerNuagePts( );
		// Ouverture du fichier binaire en lecture
		FILE *fichier = fopen( nomFichier, "r" );
		if( fichier != NULL ) {		
			// Tant qu'on arrive a lire et stocker 2 float dans pt
			double x, y;
			while( fscanf( fichier, "%lf  %lf \n ", &x, &y ) == 2 ) {
				// On cree un nouveau point
				Point p = creerPoint( x, y );
				// On l'ajoute a la liste
				ajout( res.points, &p, 2 );
			}
			// On ferme le fichier
			fclose( fichier );
		} else
			printf( "Erreur de lecture" );
		return res;
	}

	/** Ecriture d'un nuage de points dans un fichier
	  * @param nomFichier nom et emplacement du fichier ou ecrire
	  * @param liste nuage de points a ecrire
	  */
	void ecrireNuagePts( char* nomFichier, NuagePts liste ) {
		// Si la liste n'est pas vide
		if( liste.points->root != NULL ) {
			printf( "Ecriture du nuage de points dans %s \n", nomFichier );
			// Ouverture du fichier texte en ecriture
			FILE *fichier = fopen( nomFichier, "w" );
			if( fichier != NULL ) {
				// On ecrit tous les points
				for( liste.points->current = liste.points->root; hasNext( liste.points ); getNext( liste.points ) ) {
					Point* pt = (Point*)(liste.points->current->data);	// On cast de void vers Point
					fprintf( fichier, "%e %e\n", pt->x, pt->y );		// On ecrit le point
				}
				// On ferme le fichier
				fclose( fichier );
			} else
				printf( "Erreur d'ecriture" );
		}
	}


	// Methode d'affichage
	/** Affichage d'un nuage de points
	  * @param liste le nuage de points a afficher
	  */
	void afficherNuagePts( NuagePts liste ) {
		afficherListe( liste.points );
	}
