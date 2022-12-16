#include "integrale.h"

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
	double fEval( double x, int type ) {
		double res = 0;
		switch( type ) {
			case 1:
				res = 1;
				break;
			case 2:
				res = sin(x);
				break;
			case 3:
				res = sqrt(x);
				break;
			case 4:
				res = exp( -x * x / 2 );
				break;
		}
		return res;
	}

	// Exercice 1: Methodes Classiques
	/** Calcul de l'integrale de f selon une methode classique
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeIntegrale choix de la methode d'integration
	  * 	(1 = rectangle, 2 = point milieu, 3 = trapeze, 4 = Simpson)
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre a et b
	  */
	double intClassic( Integrale I, int typeIntegrale, int typeFonction ) {
		double res = 0;
		switch( typeIntegrale ) {
			case 1:
				res = intRectangle( I, typeFonction );
				break;
			case 2:
				res = intMilieu( I, typeFonction );
				break;
			case 3:
				res = intTrapeze( I, typeFonction );
				break;
			case 4:
				res = intSimpson( I, typeFonction );
				break;
		}
		return res;
	}

	/** Calcul de l'integrale de f selon la methode des rectangles
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre a et b
	  */
	double intRectangle( Integrale I, int typeFonction ) {
        
		// Parametres de l'Integrale
		double a = I.borneInf;
		double b = I.borneSup;
		int N = I.nbIntervalles;
		// Autres variables
		double h = (b - a) / N;
		double res = 0; // initialisation a 0
		double x = a;
		int i;

		for( i = 0; i < N; i++ ) {
			res += fEval( x, typeFonction ) * h;
			x += h;
		}
		return res;
	}

	/** Calcul de l'integrale de f selon la methode du point milieu
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre a et b
	  */
	double intMilieu( Integrale I, int typeFonction ) {
		
        // Parametres de l'Integrale
        double a = I.borneInf;
        double b = I.borneSup;
        int N = I.nbIntervalles;
        // Autres variables
        double h = (b - a) / N;
        double res = 0;
        double x = a + h/2; // il suffit de changer le point de depart
        int i;

        for( i = 0; i < N; i++ ) {
            res += fEval( x, typeFonction ) * h;
            x += h; // x = x + h
        }
        return res;
		
	}

	/** Calcul de l'integrale de f selon la methode des trapezes
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre a et b
	  */
	double intTrapeze( Integrale I, int typeFonction ) {
		
        // Parametres de l'Integrale
        double a = I.borneInf;
        double b = I.borneSup;
        int N = I.nbIntervalles;
        // Autres variables
        double h = (b - a) / N;
        double res = 0;
        double x = a + h; // il suffit de changer le point de depart
        int i;

        for( i = 1; i < N; i++ ) {
            res += fEval( x, typeFonction ) * h;
            x += h; // x = x + h
        }
        
        res += (fEval(a, typeFonction) + fEval(b, typeFonction)) * h/2;
        
        return res;

	}

	/** Calcul de l'integrale de f selon la methode de Simpson
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre a et b
	  */
	double intSimpson( Integrale I, int typeFonction ) {
        
        // Parametres de l'Integrale
        double a = I.borneInf;
        double b = I.borneSup;
        int N = I.nbIntervalles;
        // Autres variables
        double h = (b - a) / N;
        double res = 0;
        
        double x = a + h;
        int i;

        for( i = 1; i < N; i++ ) {
            res += 2*fEval( x, typeFonction ) ;
            x += h; // x = x + h
        }

        
        x = a + h/2; // il suffit de changer le point de depart

        for( i = 0; i < N; i++ ) {
            res += 4*fEval( x, typeFonction ) ;
            x += h; // x = x + h
        }
        
        
        res += fEval(a, typeFonction) + fEval(b, typeFonction);
        
        res = res * h/6;
        
        return res;
	}

	// Exercice 2: Methodes de Quadrature de Gauss
	/** Calcul de l'integrale de f selon une methode de quadrature de Gauss
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeIntegrale choix de la ponderation (0 = G-Legendre,
	  * 	1 = G-Tchebychev Type 1, 2 = G-Tchebychev Type 2,
	  * 	3 = G-Laguerre, 4 = G-Hermite)
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre a et b
	  */
	double intQuadrature( Integrale I, int typeIntegrale, int typeFonction ) {
		int N = I.nbIntervalles;
		if( N > NB_PTS_MAX_QUADRATURE_G ) {
			N = NB_PTS_MAX_QUADRATURE_G;
			printf( "Erreur: Nombre d'intervalles demandes trop grand. On fera avec N = %d.\n", N );
		}

		double res = 0;
		switch( typeIntegrale ) {
			case 0:		// G-Legendre
				res = intGLegendre( I, typeFonction );
				break;
			case 1:		// G-Tchebychev type 1
				res = intGTchebychev( I, typeFonction, 1 );
				break;
			case 2:		// G-Tchebychev type 2
				res = intGTchebychev( I, typeFonction, 2 );
				break;
			case 3:		// G-Laguerre
				res = intGLaguerre( I, typeFonction );
				break;
			case 4:		// G-Hermite
				res = intGHermite( I, typeFonction );
				break;
		}
		return res;
	}


	/** Calcul de l'integrale de f selon la methode de quadrature gaussienne
	  * Cas de Gauss-Legendre: [-1;1] avec w = 1
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre a et b
	  */
	double intGLegendre( Integrale I, int typeFonction ) {
		// Parametres de l'Integrale
		double a = I.borneInf;
		double b = I.borneSup;
		int N = I.nbIntervalles;
		// Autres variables
		int n;
		double Xi[N], Wi[N];
		readXiWi( "/Users/nikosoung/Desktop/Informatique/TP/TP3/data/GLegendreXi.txt", "/Users/nikosoung/Desktop/Informatique/TP/TP3/data/GLegendreWi.txt", N, Xi, Wi );

		double res = 0;
		double scale = (b - a ) / 2;
		double dec = (b + a ) / 2;
		for( n = 0; n < N; n++ ) {
			// Changement de variables (de [-1; 1] vers [a; b])
			double x = scale * Xi[n] + dec;
			// Calcul de la somme ponderee
			res += scale * fEval( x, typeFonction ) * Wi[n];
		}
		return res;
	}

	/** Calcul de l'integrale de f selon la methode de quadrature gaussienne
	  * Cas de Gauss-Tchebychev 1: ]-1;1[ avec w = 1 / sqrt(1-x^2)
	  * Cas de Gauss-Tchebychev 2: ]-1;1[ avec w = sqrt(1-x^2)
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeFonction choix de la fonction a integrer
	  * @param type type de la fonction de ponderation (1 ou 2)
	  * @return la valeur de l'integrale de f entre a et b
	  */
	double intGTchebychev( Integrale I, int typeFonction, int type ) {
		/* A completer */
        // Parametres de l'Integrale
        double a = I.borneInf;
        double b = I.borneSup;
        int N = I.nbIntervalles;
        // Autres variables
        int n;
        double Xi[N], Wi[N];
        
        if(type == 1)
        readXiWi( "/Users/nikosoung/Desktop/Informatique/TP/TP3/data/GTchebychev1Xi.txt", "/Users/nikosoung/Desktop/Informatique/TP/TP3/data/GTchebychev1Wi.txt", N, Xi, Wi );
        else if(type == 2)
        readXiWi( "/Users/nikosoung/Desktop/Informatique/TP/TP3/data/GTchebychev2Wi.txt", "/Users/nikosoung/Desktop/Informatique/TP/TP3/data/GTchebychev2Wi.txt", N, Xi, Wi );
            

        double res = 0;
        double scale = (b - a ) / 2;
        double dec = (b + a ) / 2;
        for( n = 0; n < N; n++ ) {
            // Changement de variables (de [-1; 1] vers [a; b])
            double x = scale * Xi[n] + dec;
            // Calcul de la somme ponderee
            res += scale * fEval( x, typeFonction ) * Wi[n];
        }
        return res;
	}

	/** Calcul de l'integrale de f selon la methode de quadrature gaussienne
	  * Cas de Gauss-Laguerre: [0;+inf[ avec w = exp(-x)
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre a et +inf
	  * @remark I.borneSup correspond dans ce cas a un facteur d'echelle (i.e. exp(-x/b))
	  */
	double intGLaguerre( Integrale I, int typeFonction ) {
		/* A completer */
		return 0;
	}

	/** Calcul de l'integrale de f par quadrature gaussienne
	  * Cas de Gauss-Hermite: ]-inf;+inf[ avec w = exp(-x^2)
	  * @param I structure contenant les parametres de l'Integrale
	  * @param typeFonction choix de la fonction a integrer
	  * @return la valeur de l'integrale de f entre -inf et +inf
	  * @remark I.borneSup correspond dans ce cas a un facteur d'echelle
	  *  et I.borneInf a un decalage (i.e. exp(-(x-a)^2/b))
	  */
	double intGHermite( Integrale I, int typeFonction ) {
		/* A completer */
		return 0;
	}


	/** Lecture des points Xi et ponderations Wi pour le calcul d'une
	  * Integrale par quadrature gaussienne
	  * @param fNameXi nom du fichier contenant les points de quadrature
	  * @param fNameWi nom du fichier contenant les ponderations
	  * @param N nombre de points de quadrature
	  * @param Xi tableau contenant les points de quadrature
	  * @param Wi tableau contenant les ponderations
	  */
	void readXiWi( char* fNameXi, char* fNameWi, int N, double* Xi, double* Wi ) {
		int n, p;
		// On ouvre les fichiers de poids et de points
		FILE* File1 = fopen( fNameXi, "r" );
		FILE* File2 = fopen( fNameWi, "r" );
		// On recupere les points d'integration et les poids
		for( n = 0; n < N; n++ ) {
			for( p = 0; p <= n; p++ ) {
				fscanf( File1, "%lf", &Xi[p] );
				fscanf( File2, "%lf", &Wi[p] );
			}
		}
		// On ferme les fichiers
		fclose( File1 );
		fclose( File2 );
	}
