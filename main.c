#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Figure.h"


void menu(){

	int opc = 0;
	int qntd = 0;
 	char matrix[row][column];

	printf("\nPROGRAMA GERADOR DE OBRA DE ARTE: \n");
	printf("==================================\n");
	printf("Escolha o tipo de figura basica a ser usada para criar a obra: \n");
	printf("1 - asterisco simples. \n");
	printf("2 - simbolo de soma com asteriscos. \n");
	printf("3 - letra X com asteriscos. \n");
	printf("4 - figuras aleatorias. \n");
	printf("5 ou qualquer outro numero - opcao de obra de arte criada pelo aluno. \n");

	printf("\nDigite o tipo de figura basica desejada: ");
	scanf("%d", &opc);

	printf("\nDigite a quantidade de figuras ( menor ou igual a zero para aleatorio): ");
	scanf("%d", &qntd);

	if( qntd <= 0 ){

		srand(time(NULL));
		qntd = ( rand() % 100 );

	}
	else if( qntd > 100 ){

		qntd = 100;
	}



	switch(opc){

		case 1:
			do{
				createBorder( matrix );
				createFigureAsterisk( matrix, qntd );	
				printMatrix( matrix );
				printf("\nDeseja continuar gerando novas pinturas ? \n");
				printf("1 - SIM\n2 - NAO\n");					
				scanf("%d",&opc);
			}while( opc == 1);
			break;
		case 2:
			do{
				createBorder( matrix );
				createFigurePlusSimbol( matrix, qntd );
				printMatrix( matrix );
				printf("\nDeseja continuar gerando novas pinturas ? \n");
				printf("1 - SIM\n2 - NAO\n");					
				scanf("%d",&opc);
			}while( opc == 1);
			break;
		case 3:
			do{
				createBorder( matrix );
				createFigureX( matrix, qntd );
				printMatrix( matrix );
				printf("\nDeseja continuar gerando novas pinturas ? \n");
				printf("1 - SIM\n2 - NAO\n");					
				scanf("%d",&opc);
			}while( opc == 1);
			break;
		case 4:
			do{
				createBorder( matrix );
				createRandomPicture( matrix, qntd );
				printMatrix(matrix);
				printf("\nDeseja continuar gerando novas pinturas ? \n");
				printf("1 - SIM\n2 - NAO\n");					
				scanf("%d",&opc);
			}while( opc ==1 );
			break;
		default:
			do{
				createBorder( matrix );
				createShipPicture( matrix, qntd );
				printMatrix(matrix);
				printf("\nDeseja continuar gerando novas pinturas ? \n");
				printf("1 - SIM\n2 - NAO\n");					
				scanf("%d",&opc);
			}while( opc == 1);
		}

}


int main(){

	menu();

	return(0);
}