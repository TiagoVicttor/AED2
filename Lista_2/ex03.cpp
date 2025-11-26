#include <iostream>
#include <vector>
using namespace std;

// Função que simula a resposta do oráculo
bool inimigoEntre(const vector<int>& A, int i, int j) {
    for (int k = i; k <= j; k++)
        if (A[k] == 1) return true;
    return false;
}

int buscaGuardiao(const vector<int>& A) {
    int l = 0, r = A.size() - 1;

    while (l < r) {
        int m = (l + r) / 2;

        cout << "Pergunta: inimigo entre " << l << " e " << m << "?\n";

        if (inimigoEntre(A, l, m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    return l;  // posição única
}

int main() {
    // 0 = vazio, 1 = inimigo
    vector<int> territorio = {0,0,0,1,0,0,0};

    int pos = buscaGuardiao(territorio);
    cout << "O inimigo esta na posicao: " << pos << endl;

    return 0;
}
