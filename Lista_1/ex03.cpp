#include <stdio.h>

int soma(int salarios[],int tamanho,int indice){
	if (indice >= tamanho){
		return 0;
	}
	else if(indice == tamanho - 1){
		return salarios[indice];
	}
	else{
		return (salarios[indice] + salarios [indice + 1]) + soma(salarios,tamanho, indice+2);
	}
}

int main(){
	int salarios [] = {2000,1500,4000,1200,1000};
	int tamanho = sizeof(salarios)/sizeof(salarios[0]);
	printf("A soma dos salarios eh: %d\n",soma(salarios,tamanho,0));
	
}
