#include <stdio.h>

int soma(int salarios[],int tamanho,int indice){
	if (indice == tamanho){
		return 0;
	}
	else{
		return salarios[indice] + soma(salarios,tamanho, indice+1);
	}
}

int main(){
	int salarios [] = {2000,1500,4000,1200};
	int tamanho = sizeof(salarios)/sizeof;
	printf("A soma dos salarios eh: %d\n",soma(salarios,tamanho,0));
	
}
