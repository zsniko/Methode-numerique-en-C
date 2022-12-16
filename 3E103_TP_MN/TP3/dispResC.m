clear variables;
close all;
clc;

%% Lecture des integrales classiques
formatSpec = '%d%f%f%f%f%[^\n\r]';    % Format de chaque ligne du fichier (1 entier suivi de 4 double)
filename = 'resultats/intClassique.txt';
delimiter = ' ';
fileID = fopen(filename,'r');	% Ouverture du fichier
dataArray = textscan(fileID, formatSpec, 'Delimiter', delimiter, 'MultipleDelimsAsOne', true,  'ReturnOnError', false);     % Lecture des colonnes
fclose(fileID);                 % Fermeture du fichier
    % Valeur des integrales
N = dataArray{:, 1};
iR = dataArray{:, 2};
iM = dataArray{:, 3};
iT = dataArray{:, 4};
iS = dataArray{:, 5};
    % Affichage des integrales (convergence)
figure; hold on;
    plot( N, iR, '-o', 'linewidth', 2 );
    plot( N, iM, '-s', 'linewidth', 2 );
    plot( N, iT, '-^', 'linewidth', 2 );
    plot( N, iS, '-*', 'linewidth', 2 );
hold off;
legend( 'Rectangle', 'Milieu', 'Trapeze', 'Simpson' );

%% Lecture des integrales de quadrature gaussienne
formatSpec = '%d%f%f%f%f%f%[^\n\r]';    % Format de chaque ligne du fichier (1 entier suivi de 4 double)
filename = 'resultats/intQuadra.txt';
delimiter = ' ';
fileID = fopen(filename,'r');	% Ouverture du fichier
dataArray = textscan(fileID, formatSpec, 'Delimiter', delimiter, 'MultipleDelimsAsOne', true,  'ReturnOnError', false);     % Lecture des colonnes
fclose(fileID);                 % Fermeture du fichier
    % Valeur des integrales
N = dataArray{:, 1};
iGLe = dataArray{:, 2};
iGT1 = dataArray{:, 3};
iGT2 = dataArray{:, 4};
iGLa = dataArray{:, 5};
iGHe = dataArray{:, 6};
    % Affichage des integrales (convergence)
figure; hold on;
    plot( N, iGLe, '-o', 'linewidth', 2 );
    plot( N, iGT1, '-s', 'linewidth', 2 );
    plot( N, iGT2, '-^', 'linewidth', 2 );
    plot( N, iGLa, '-*', 'linewidth', 2 );
    plot( N, iGHe, '-x', 'linewidth', 2 );
hold off;
legend( 'G-Legendre', 'G-Tchebychev 1', 'G-Tchebychev 2', 'G-Laguerre', 'G-Hermite' );