#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cout << "Crianças: ";
	cin >> n;
	cout << "Doces: ";
	cin >> m;
	
	vector<int> necessidades(n);
	vector<int> doces(m);
	
	cout << "Necessidades das crianças: ";
	for(int i = 0; i < n; i++){
		cin >> necessidades[i];
	}
	
	cout << "Valores calóricos dos doces: ";
	for(int j = 0; j < m; j++){
		cin >> doces[j];
	}
	
	sort(necessidades.begin(), necessidades.end());
	sort(doces.begin(), doces.end());
	
	int i = 0, j = 0;
	int satisfeitas = 0;
	
	while(i < n && j < m){
		if(doces[j] >= necessidades[i]){
			cout << "A Criança que precisava de " << necessidades[i] << " recebeu doce com " << doces[j] << " calorias" << endl;
			satisfeitas++;
			i++;
			j++;
		}else{
			j++;
		}
	}
	
	cout << "Crianças satisfeitas: " << satisfeitas << endl;
	return 0;
}
