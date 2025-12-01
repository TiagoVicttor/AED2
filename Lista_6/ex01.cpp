#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> piramide;
vector<vector<bool>> visitado;
vector<int> caminho;
vector<vector<int>> solucoes;
int S;

void backtrack(int i, int j, int soma) {
    int linhas = piramide.size();

    if (i >= linhas || j < 0 || j >= piramide[i].size()) 
        return;

    if (visitado[i][j]) 
        return;

    int valor = piramide[i][j];

    if (soma + valor > S) 
        return; // poda

    // marca
    visitado[i][j] = true;
    caminho.push_back(valor);

    // chegamos no nível final
    if (i == linhas - 1) {
        if (soma + valor == S) {
            solucoes.push_back(caminho);
        }
    } else {
        // desce para esquerda e direita
        backtrack(i + 1, j, soma + valor);
        backtrack(i + 1, j + 1, soma + valor);
    }

    // desfaz
    caminho.pop_back();
    visitado[i][j] = false;
}

int main() {
    int n;
    cout << "Quantidade de linhas da piramide: ";
    cin >> n;

    piramide.resize(n);
    visitado.resize(n);

    cout << "Digite os valores da piramide:\n";
    for (int i = 0; i < n; i++) {
        piramide[i].resize(i + 1);
        visitado[i].resize(i + 1, false);
        for (int j = 0; j < i + 1; j++) {
            cin >> piramide[i][j];
        }
    }

    cout << "Digite o valor da chave secreta S: ";
    cin >> S;

    backtrack(0, 0, 0);

    if (solucoes.empty()) {
        cout << "Nenhuma solucao\n";
    } else {
        cout << "\nSolucoes encontradas:\n";
        for (auto &c : solucoes) {
            for (int x : c) cout << x << " ";
            cout << endl;
        }
    }

    return 0;
}
