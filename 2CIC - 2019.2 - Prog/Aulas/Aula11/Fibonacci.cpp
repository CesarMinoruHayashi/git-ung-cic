#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	int num, i;
	int a = 0, b = 1, prox, resp;
	
	setlocale(LC_ALL,"");
	
	printf("***SEQU�NCIA DE FIBONACCI ***\n");
	
	printf("Entre com o elemento: ");
	scanf("%d", &num);
	
	//Constru��o do algoritmo
	
	if(num == 1){
		resp = a;
	}else if(num == 2){
		resp = b;
	}else{		
		for(i=3; i<=num; i++){
			prox = a + b;
			a = b;
			b = prox;
		}//fechando for		
		resp = prox;	
	}
	
	printf("\nO (%d) elemento da sequ�ncia �: %d",num, resp);
	
	printf("\n\n");
	system("pause");
	
	
}
