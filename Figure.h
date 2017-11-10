#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define row 20
#define column 80

void createBorder( char matrix[row][column] );
void createFigureAsterisk( char matrix[row][column], int qntd );
void createFigurePlusSimbol( char matrix[row][column], int qntd );
void createFigureX( char matrix[row][column], int qntd );
void createRandomPicture( char matrix[row][column], int qntd );
void createShipPicture( char matrix[row][column], int qntd );
void printMatrix( char matrix[row][column]);
int setMaxQntd( int qntd );