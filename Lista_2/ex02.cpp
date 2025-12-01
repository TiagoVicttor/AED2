#include <iostream>
#include <vector>
using namespace std;

// Função que mescla duas metades do vetor e conta inversões
long long mesclarContar(vector<int>& v, int esq, int meio, int dir) {
    vector<int> esquerda(v.begin() + esq, v.begin() + meio + 1);
    vector<int> direita(v.begin() + meio + 1, v.begin() + dir + 1);

    int i = 0, j = 0, k = esq;
    long long inversoes = 0;

    while (i < esquerda.size() && j < direita.size()) {
        if (esquerda[i] <= direita[j]) {
            v[k++] = esquerda[i++];
        } else {
            v[k++] = direita[j++];
            inversoes += (esquerda.size() - i); // elementos restantes formam inversões
        }
    }

    while (i < esquerda.size()) v[k++] = esquerda[i++];
    while (j < direita.size()) v[k++] = direita[j++];

    return inversoes;
}

// Função principal que divide o vetor e conta inversões usando Merge Sort
long long contarInversoes(vector<int>& v, int esq, int dir) {
    if (esq >= dir) return 0;

    int meio = (esq + dir) / 2;
    return contarInversoes(v, esq, meio)
         + contarInversoes(v, meio + 1, dir)
         + mesclarContar(v, esq, meio, dir);
}

int main() {
    vector<int> A = {2, 4, 1, 3, 5};
    cout << contarInversoes(A, 0, A.size() - 1) << endl;
    return 0;
}
