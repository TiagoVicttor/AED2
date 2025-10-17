#include <iostream>
#include <vector>
using namespace std;

void buscarSequencias(const vector<vector<int>>& piramide, int i, int j, int somaAtual, int S, int vector<int>& caminho, vector<vector<int>>& solucoes){
	if (i>= (int)piramide.size() || j>= (int)piramide[i].size()){
		return;
	}
	somaAtual += piramide[i][j];
	caminho.push_back(piramide[i][j]);
	
	if(somaAtual > S){
		caminho.pop_back();
		return;
	} 
	
	if (i == (int)piramide.size() - 1) {
        	if (somaAtual == S){
            		solucoes.push_back(caminho);
    		}
    	}else{
    		 buscarSequencias(piramide, i + 1, j, somaAtual, S, caminho, solucoes);
        	buscarSequencias(piramide, i + 1, j + 1, somaAtual, S, caminho, solucoes);
        }
        
        caminho.pop_back();
}

int main(){
	vector<vector<int>> piramide {{5},{3,8},{2,4,6},{1,2,7,3}};
	
	int S = 16;
	
	vector<vector<int>> solucoes;
	vector<int> caminho;
	
	buscaSequencias(piramide,0,0,0,S,caminho,solucoes);
	
	if(solucoes.empty()){
		cout << "Nenhuma solucao emcontrada" << endln;
	} else {
		cout << "Solucoes encontradas:\n";
		for (auto& seq : solucoes){
			cout << "[";
			for (int v : seq){
				cout << v << " ";
			}
			cout << "]\n";
		}
	}
	return 0;
}
