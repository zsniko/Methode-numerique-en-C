clear variables;
close all;
clc;

formatSpec = '%f%f%[^\n\r]';    % Format de chaque ligne du fichier (2 double)

%% Lecture des donnees non interpolees
% filenameD = 'data/ex1.txt';
% filenameD = 'data/ex2.txt';
 filenameD = 'data/ex4.txt';
delimiter = ' ';
fileID = fopen(filenameD,'r');	% Ouverture du fichier
dataArray = textscan(fileID, formatSpec, 'Delimiter', delimiter, 'MultipleDelimsAsOne', true,  'ReturnOnError', false);     % Lecture des colonnes
fclose(fileID);                 % Fermeture du fichier
    % Coordonnees des points avant interpolation
xD = dataArray{:, 1};
yD = dataArray{:, 2};

%% Lecture des donnees interpolees
filenameI = 'data/interpolation.txt';
delimiter = ' ';
fileID = fopen(filenameI,'r');	% Ouverture du fichier
dataArray = textscan(fileID, formatSpec, 'Delimiter', delimiter, 'MultipleDelimsAsOne', true,  'ReturnOnError', false);     % Lecture des colonnes
fclose(fileID);                 % Fermeture du fichier
    % Coordonnees des points avant interpolation
xI = dataArray{:, 1};
yI = dataArray{:, 2};


%% Affichage des nuages de points
figure; hold on;
    plot( xI, yI, '-', 'linewidth', 2 );
    plot( xD, yD, 'o', 'linewidth', 2 );
hold off;
legend( 'Interpolation', 'Donnees' );


%% Lecture de la verite de terrain
if( strcmp( filenameD, 'data/ex4.txt' ) )
	filename = 'data/fonction.txt';
	delimiter = ' ';
	fileID = fopen(filename,'r');	% Ouverture du fichier
	dataArray = textscan(fileID, formatSpec, 'Delimiter', delimiter, 'MultipleDelimsAsOne', true,  'ReturnOnError', false);     % Lecture des colonnes
	fclose(fileID);                 % Fermeture du fichier
		% Coordonnees des points avant interpolation
	xF = dataArray{:, 1};
	yF = dataArray{:, 2};
		% Affichage
	hold on; plot( xF, yF, '-', 'linewidth', 2 ); hold off;
	legend( 'Fonction' );
end
