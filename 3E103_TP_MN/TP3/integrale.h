#ifndef _integrale_h_
#define _integrale_h_

	#include <math.h>
	#include <stdio.h>
	#include <stdlib.h>

	#define NB_PTS_MAX_QUADRATURE_G 20

	typedef struct {
		double borneInf;
		double borneSup;
		int nbIntervalles;
	} Integrale;
	
	/** Fonction calculant la valeur de f (fonction a integree)
	  * en un point x
	  * @param x un reel dans le domaine de definition de f
	  * @param type choix de la fonction a integrer
	  * 	1: f(x) = 1 (exercice 7.2 du TD3)
	  * 	2: f(x) = sin(x) (exercice 7.3 et 7.4 du TD3)
	  * 	3: f(x) = sqrt(x) (exercice 5.2 du TD3)
	  * 	4: f(x) = exp(-x^2 / 2) (exercice 7.1 du TD3)
	  * @return f(x)
	  */
	double fEval( double x, int type );
	
	
	// Exercice 1: Methodes Classiques
	/** Calcul de l'integrale de f selon une methode classique
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeIntegrale choix de la methode d'integration
	  * 	(1 = rectangle, 2 = point milieu, 3 = trapeze, 4 = Simpson)
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre a et b
	  */
	double intClassic( Integrale I, int typeIntegrale, int typeFonction );
	
	/** Calcul de l'integrale de f selon la methode des rectangles
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre a et b
	  */
	double intRectangle( Integrale I, int typeFonction );
	
	/** Calcul de l'integrale de f selon la methode du point milieu
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre a et b
	  */
	double intMilieu( Integrale I, int typeFonction );
	
	/** Calcul de l'integrale de f selon la methode des trapezes
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre a et b
	  */
	double intTrapeze( Integrale I, int typeFonction );
	
	/** Calcul de l'integrale de f selon la methode de Simpson
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre a et b
	  */
	double intSimpson( Integrale I, int typeFonction );

	// Exercice 2: Methodes de Quadrature de Gauss
	/** Calcul de l'integrale de f selon une methode de quadrature de Gauss
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeIntegrale choix de la ponderation (0 = G-Legendre,
	  * 	1 = G-Tchebychev Type 1, 2 = G-Tchebychev Type 2, 
	  * 	3 = G-Laguerre, 4 = G-Hermite)
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre a et b
	  */
	double intQuadrature( Integrale I, int typeIntegrale, int typeFonction );


	/** Calcul de l'integrale de f selon la methode de quadrature gaussienne
	  * Cas de Gauss-Legendre: [-1;1] avec w = 1
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre a et b
	  */
	double intGLegendre( Integrale I, int typeFonction );

	/** Calcul de l'integrale de f selon la methode de quadrature gaussienne
	  * Cas de Gauss-Tchebychev 1: ]-1;1[ avec w = 1 / sqrt(1-x^2)
	  * Cas de Gauss-Tchebychev 2: ]-1;1[ avec w = sqrt(1-x^2)
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeFonction choix de la fonction a integrer
	  * @param type type de la fonction de ponderation (1 ou 2)
	  * @return la valeur de l'integrale de f entre a et b
	  */
	double intGTchebychev( Integrale I, int typeFonction, int type );

	/** Calcul de l'integrale de f selon la methode de quadrature gaussienne
	  * Cas de Gauss-Laguerre: [0;+inf[ avec w = exp(-x)
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre a et +inf
	  * @remark I.borneSup correspond dans ce cas a un facteur d'echelle (i.e. exp(-x/b))
	  */
	double intGLaguerre( Integrale I, int typeFonction );
	
	/** Calcul de l'integrale de f par quadrature gaussienne
	  * Cas de Gauss-Hermite: ]-inf;+inf[ avec w = exp(-x^2)
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre -inf et +inf
	  * @remark I.borneSup correspond dans ce cas a un facteur d'echelle
	  *  et I.borneInf a un decalage (i.e. exp(-(x-a)^2/b))
	  */
	double intGHermite( Integrale I, int typeFonction );
	
	
	/** Lecture des points Xi et ponderations Wi pour le calcul d'une
	  * Integrale par quadrature gaussienne
	  * @param fNameXi nom du fichier contenant les points de quadrature
	  * @param fNameWi nom du fichier contenant les ponderations
	  * @param N nombre de points de quadrature
	  * @param Xi tableau contenant les points de quadrature
	  * @param Wi tableau contenant les ponderations
	  */
	void readXiWi( char* fNameXi, char* fNameWi, int N, double* Xi, double* Wi );
	
#endif
