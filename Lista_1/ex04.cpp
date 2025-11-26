#include <iostream>
#include <vector>
using namespace std;

/*
Busca um valor alvo no "muro", começando na posição s
e expandindo alternadamente 1 para esquerda, 1 para direita,
2 esquerda, 2 direita, etc.

Retorna o índice onde encontrou ou -1 se não encontrou.
*/
int buscaMuro(const vector<int>& muro, int s, int alvo) {
    int n = muro.size();

    // Verifica posição inicial
    if (muro[s] == alvo) return s;

    int k = 1; // raio inicial

    while (true) {
        bool movimentou = false;

        // Tenta s - k
        int esq = s - k;
        if (esq >= 0) {
            movimentou = true;
            if (muro[esq] == alvo) return esq;
        }

        // Tenta s + k
        int dir = s + k;
        if (dir < n) {
            movimentou = true;
            if (muro[dir] == alvo) return dir;
        }

        // Se não conseguiu checar nada, acabou o intervalo
        if (!movimentou) break;

        k++; // aumenta o raio
    }

    return -1; // não encontrado
}

int main() {
    vector<int> muro = {5, 3, 8, 10, 14, 7, 9};
    int s = 3;
    int alvo = 7;

    int pos = buscaMuro(muro, s, alvo);

    if (pos != -1)
        cout << "Elemento encontrado na posicao " << pos << endl;
    else
        cout << "Elemento nao encontrado no muro." << endl;

    return 0;
}
