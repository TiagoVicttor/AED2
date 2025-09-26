#include<stdio.h>
#define MAX(a,b) ((a)>(b) ? (a) : (b))

int main(){
	int peso[] = {5,4,3,6};
	int valores[] = {10,7,4,12};
	int itens = 4;
	int capacidade = 10;
	
	int dp[itens+1][capacidade+1];
	
	for(int i=0; i<=itens; i++){
		for(int j=0; j<=capacidade; j++){
			if(i==0||j==0){
				dp[i][j] = 0;
			}else if(peso[i-1] <= j){
				 dp[i][j] = MAX(valores[i-#include<stdio.h>
#define MAX(a,b) ((a)>(b) ? (a) : (b))

int main(){
	int peso[] = {5,4,3,6};
	int valores[] = {10,7,4,12};
	int itens = 4;
	int capacidade = 10;
	
	int dp[itens+1][capacidade+1];
	
	for(int i=0; i<=itens; i++){
		for(int j=0; j<=capacidade; j++){
			if(i==0||j==0){
				dp[i][j] = 0;
			}else if(peso[i-1] <= j){
				 dp[i][j] = MAX(valores[i-1]+dp[i-1][j-peso[i-1]],dp[i-1][j]);
			}else{
				dp[i][j] == dp[i-1][j];
			}
		}
		
	} printf("valor maximo ataque: %d\n",dp[itens][capacidade]);
	
	int j = capacidade;
	printf("itens escolhidos:\n");
	for(int i = itens; i>0;i--){
		if(dp[i][j] != dp[i-1][j]){
			printf("Item %d (peso %d, valor %d)\n",i, peso[i-1],valores[i-1]);
			j -= peso[i-1]; 
		}
	}
	return 0;
	
}1]+dp[i-1][j-peso[i-1]],dp[i-1][j]);
			}else{
				dp[i][j] == dp[i-1][j];
			}
		}
		
	} printf("valor maximo ataque: %d\n",dp[itens][capacidade]);
	
	int j = capacidade;
	printf("itens escolhidos:\n");
	for(int i = itens; i>0;i--){
		if(dp[i][j] != dp[i-1][j]){
			printf("Item %d (peso %d, valor %d)\n",i, peso[i-1],valores[i-1]);
			j -= peso[i-1]; 
		}
	}
	return 0;
	
}
