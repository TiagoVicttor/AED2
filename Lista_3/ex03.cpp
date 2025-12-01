#include <iostream>
#include <vector>
using namespace std;

bool buscaBinaria(const vector<int>& v, int alvo) {
    int l = 0, r = v.size() - 1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (v[m] == alvo) return true;
        else if (v[m] < alvo) l = m + 1;
        else r = m - 1;
    }

    return false;
}

int main() {
    int n;
    cout << "Quantidade de posições: ";
    cin >> n;

    vector<int> pos(n);
    cout << "Posições: ";
    for (int i = 0; i < n; i++)
        cin >> pos[i];

    int x;
    cout << "Verificar posição: ";
    cin >> x;

    if (buscaBinaria(pos, x))
        cout << "Tesouro encontrado!" << endl;
    else
        cout << "Nenhum tesouro nessa posição." << endl;

    return 0;
}
