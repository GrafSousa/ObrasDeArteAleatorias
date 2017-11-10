#include "Figure.h"

void createBorder( char matrix[row][column] ){

	int countRow = 0;
	int countColumn = 0;
	
	for( countRow = 0; countRow < row; countRow++ ){

		for( countColumn = 0 ; countColumn < column; countColumn++){

			if( countRow == 0 || countRow == row - 1 ){
				matrix[countRow][countColumn] = '-';	
			}
			else if(( countRow != 0 && countColumn == 0) || ( countRow != (row - 1) && countColumn == column - 1 ) ){
				matrix[countRow][countColumn] = '|';
			}
			else
				matrix[countRow][countColumn] = ' ';	
		}
	}
	
}

void createFigureAsterisk( char matrix[row][column], int qntd){

	int count = 0;
	int positionRow = 0;
	int positionColumn = 0;

	//qntd = setMaxQntd(qntd);

	srand(time(NULL));

	for( count  = 0; count < qntd; count++ ){

		do{
			positionRow = ( rand() % row );
			positionColumn = ( rand() % column );

		}while( positionRow == 0 || positionRow == row - 1  ||  positionColumn == 0 || positionColumn == column - 1 
			|| matrix[positionRow][positionColumn] == '*');

		matrix[positionRow][positionColumn] = '*';
	}

	//printMatrix(matrix);
}

void createFigurePlusSimbol( char matrix[row][column], int qntd ){

	int count = 0;
	int exit = 0;
	int positionRow = 0;
	int positionColumn = 0;

	//qntd = setMaxQntd(qntd);

	srand(time(NULL));

	for( count = 0; count < qntd; count++ ){

		do{
			positionRow = ( rand() % row );
			positionColumn = ( rand() % column );
			exit++;

		}while( (positionRow == 0 || positionRow == row - 1 || positionColumn == 0 || positionColumn == column - 1 
			|| (positionRow -1 ) == 0 || (positionRow + 1) == row - 1 || ( positionColumn - 1 ) == 0 || (positionColumn + 1) == column - 1
			|| matrix[positionRow][positionColumn] == '*' || matrix[positionRow -1 ][positionColumn] == '*' || matrix[positionRow + 1 ][positionColumn] == '*'
			|| matrix[positionRow][positionColumn - 1] == '*' || matrix[positionRow][positionColumn + 1] == '*')
			&& exit < 100);

		if( exit == 100 ){
			break;
		}
		else{

			exit = 0;
			matrix[positionRow][positionColumn] = '*';
			matrix[positionRow][positionColumn - 1] = '*';
			matrix[positionRow][positionColumn + 1] = '*';
			matrix[positionRow - 1][positionColumn] = '*';
			matrix[positionRow + 1][positionColumn] = '*';	
		}
		
	}

	//printMatrix(matrix);
}

void createFigureX( char matrix[row][column], int qntd ){

	int count = 0;
	int exit = 0;
	int positionRow = 0;
	int positionColumn = 0;

	//qntd = setMaxQntd(qntd);

	srand(time(NULL));

	for( count = 0; count < qntd; count++ ){

		do{
			positionRow = ( rand() % row );
			positionColumn = ( rand() % column );
			exit++;

		}while(( positionRow == 0 || positionRow == row - 1 || positionColumn == 0 || positionColumn == column - 1 
			|| (positionRow -1 ) == 0 || (positionRow + 1) == row - 1 || ( positionColumn - 1 ) == 0 || (positionColumn + 1) == column - 1
			|| matrix[positionRow][positionColumn] == '*' || matrix[positionRow -1 ][positionColumn -1] == '*' || matrix[positionRow - 1 ][positionColumn + 1] == '*'
			|| matrix[positionRow + 1][positionColumn + 1] == '*' || matrix[positionRow + 1][positionColumn - 1] == '*')
			&& exit < 100);

		if( exit == 100 ){
			
			break;
		}
		else{

			exit = 0;
			matrix[positionRow][positionColumn] = '*';
			matrix[positionRow - 1][positionColumn - 1] = '*';
			matrix[positionRow - 1][positionColumn + 1] = '*';
			matrix[positionRow + 1][positionColumn + 1] = '*';	
			matrix[positionRow + 1][positionColumn - 1] = '*';
		}
	}

	//printMatrix(matrix);
}

void createRandomPicture( char matrix[row][column], int qntd ){

	int count = 0;
	int positionRow = 0;
	int positionColumn = 0;
	int randomPicture = 0;

	//qntd = setMaxQntd(qntd);

	srand(time(NULL));

	for( count = 0; count < qntd; count++ ){

		randomPicture = ( rand() % 3 );

		if( randomPicture == 0 ){
			createFigureAsterisk( matrix, 1);
		}
		else if( randomPicture == 1){
			createFigurePlusSimbol( matrix, 1);
		}
		else if( randomPicture == 2 ){
			createFigureX( matrix, 1);
		}
	}

}

void createShipPicture( char matrix[row][column], int qntd ){
	int count = 0;
	int exit = 0;
	int positionRow = 0;
	int positionColumn = 0;

	//qntd = setMaxQntd(qntd);

	srand(time(NULL));

	for( count = 0; count < qntd; count++ ){

		do{
			positionRow = ( rand() % row );
			positionColumn = ( rand() % column );
			exit++;

		}while(( positionRow == 0 || positionRow == row - 1 || positionColumn == 0 || positionColumn == column - 1 
			|| (positionRow -1 ) == 0 || (positionRow + 1) == row - 1 || ( positionColumn - 1 ) == 0 || (positionColumn + 1) == column - 1
			|| matrix[positionRow][positionColumn] == '*' || matrix[positionRow][positionColumn -1] == '*' || matrix[positionRow][positionColumn + 1] == '*'
			|| matrix[positionRow - 1][positionColumn] == '*' || matrix[positionRow + 1][positionColumn - 1] == '*' || matrix[positionRow + 1][positionColumn + 1] == '*')
			&& exit < 100);

		exit = 0;
		matrix[positionRow][positionColumn] = '*';
		matrix[positionRow][positionColumn - 1] = '*';
		matrix[positionRow][positionColumn + 1] = '*';
		matrix[positionRow - 1][positionColumn] = '*';
		matrix[positionRow + 1][positionColumn - 1] = '*';
		matrix[positionRow + 1][positionColumn + 1] = '*';
	}
}

void printMatrix( char matrix[row][column]){

	int countRow = 0;
	int countColumn = 0;

	for( countRow = 0; countRow < row; countRow++ ){
		for( countColumn = 0; countColumn < column; countColumn++ ){

			printf("%c ", matrix[countRow][countColumn] );
		} 
		printf("\n");
	}
}
/*
int setMaxQntd( int qntd ){

	//Calcula o perímetro - 4 das bordas
	if( qntd > ( row * column ) -  ( (2 * ( row + column) ) - 4 ) ){
		
		return qntd = ( row * column ) - ( (2 * ( row + column)  ) - 4 );
	}
	else{

		return qntd;
	}
}
*/