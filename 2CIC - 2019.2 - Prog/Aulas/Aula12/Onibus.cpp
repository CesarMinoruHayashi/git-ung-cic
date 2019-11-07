#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

/**VARIAVEIS PUBLICAS**/
int onibA[42], onibB[42], onibC[42];
int i;

void esvaziarOnibus(){
	for(i=0; i<42; i++){
		onibA[i] = 0;
		onibB[i] = 0;
		onibC[i] = 0;
	}
}

void mostrarOnibus(int tmpOnib[]){
	char status[10];
	system("cls");
	
	for(i=0; i<42; i++){
		if(tmpOnib[i] == 0){
			strcpy(status,"Vazio");
		}else{
			strcpy(status,"Ocupado");
		}//fechando else
		
		printf("POLTRONA[%d] = %s\n", i, status);		
	}//fechando for
	
	getch();
	system("cls");
}//fechando mostrarOnibus

int montarMenu(){
	
	int menu; //op��o escolhida
	
	printf("Entre com a op��o desejada: \n\n");
	printf("1 - Realizar Venda\n");
	printf("2 - Visualizar Frotas\n");
	printf("3 - Relat�rio de Vendas\n");
	printf("4 - Sair\n\n");
	
	printf("Op��o: ");
	scanf("%d", &menu);
	
	return menu;
}

int main(){

	int opcao;
	char codOnibus;
	
	setlocale(LC_ALL,"");
	esvaziarOnibus();
	
	do{
	
		printf("**PROGRAMA AG�NCIA DE VIAGENS **\n\n");
		opcao = montarMenu();
	
		switch(opcao){
			
			case 1:
				//venda
				break;
			case 2:
				printf("\nEntre com o c�digo do onibus: ");
				scanf("%s", &codOnibus);
				
				if(codOnibus == 'a')
					mostrarOnibus(onibA);
				else if	(codOnibus == 'b')
					mostrarOnibus(onibB);
				else if	(codOnibus == 'c')
					mostrarOnibus(onibB);
				else
					printf("C�digo Inv�lido.\n");					
				break;
			case 3:
				//relatorio
				break;
			case 4:
				break;
			default:
				printf("## Op��o Inv�lida! ##");
				_sleep(1500);
				break;
		}		
	
		system("cls");
	
	}while(opcao != 4);

	
	
}
