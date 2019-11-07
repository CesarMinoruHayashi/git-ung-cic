#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

/**VARIAVEIS PUBLICAS**/
int onibA[42], onibB[42], onibC[42];
int i;
float total, valor, caixa = 0;

void esvaziarOnibus(){
	for(i=0; i<42; i++){
		onibA[i] = 0;
		onibB[i] = 0;
		onibC[i] = 0;
	}
}

void mostrarOnibus(int tmpOnib[]){
	char status[10];
		
	for(i=0; i<42; i++){
		if(tmpOnib[i] == 0){
				strcpy(status,"Vazio");
			}else{
				strcpy(status,"Ocupado");
			}//fechando else
			
		if(i % 2 == 0){				
		
			printf("POLTRONA[%d] = %s\t", i+1, status);		
		}else{
			printf("POLTRONA[%d] = %s\n", i+1, status);
		}		
		
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

bool efetuarVenda(int tmpOnib[], int tmpPolt){
	if(tmpOnib[tmpPolt - 1] == 1){
		return false;		
	}else{
		if(tmpPolt < 10){
			total = valor * 1.25;
		}else{
			total = valor;
		}
			caixa += total;
			printf("Total a pagar: R$ %.2f\n",total);
			tmpOnib[tmpPolt - 1] = 1; //poltrona ocupada 
			return true;
		}		
	}	

int main(){

	int opcao, polt;
	char codOnibus;
	bool statusVenda;
	
	setlocale(LC_ALL,"");
	esvaziarOnibus();
	
	do{
	
		printf("**PROGRAMA AG�NCIA DE VIAGENS **\n\n");
		opcao = montarMenu();
	
		switch(opcao){
			
			case 1:
				printf("Entre com o destino: ");
				scanf("%s", &codOnibus);
				printf("Entre com o n�mero da poltrona:");
				scanf("%d", &polt);
				
				if(codOnibus == 'a'){
					valor = 75;
					statusVenda = efetuarVenda(onibA,polt);					
				}else if(codOnibus == 'b'){
					valor = 90;
					statusVenda = efetuarVenda(onibB,polt);					
				}else if(codOnibus == 'c'){
					valor = 250;
					statusVenda = efetuarVenda(onibC,polt);					
				}else{
					printf("Destino Inv�lido.");
					break;
				}
				
				if(statusVenda == true)
					printf("Venda Efetuada!!");
				else
					printf("Poltrona Ocupada!!");
					
				_sleep(1500);
				//venda
				break;
			case 2:
				system("cls");
				printf("\nEntre com o c�digo do onibus: ");
				scanf("%s", &codOnibus);
				printf("\n\n");				
				if(codOnibus == 'a'){
					printf("## ONIBUS A - Destino -> Rio de Janeiro ##\n\n");
					mostrarOnibus(onibA);
				}else if(codOnibus == 'b'){
					printf("## ONIBUS B - Destino -> Belo Horizonte ##\n\n");
					mostrarOnibus(onibB);
				}else if(codOnibus == 'c'){
					printf("## ONIBUS C - Destino -> Acre ##\n\n");
					mostrarOnibus(onibC);
				}else{
					printf("C�digo Inv�lido.\n");					
				}
				
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
