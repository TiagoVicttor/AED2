#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

/* --------------------- MERGE SORT --------------------- */

void merge(vector<int>& v, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m + 1;

    while (i <= m && j <= r) {
        if (v[i] <= v[j]) temp.push_back(v[i++]);
        else temp.push_back(v[j++]);
    }

    while (i <= m) temp.push_back(v[i++]);
    while (j <= r) temp.push_back(v[j++]);

    for (int k = 0; k < temp.size(); k++)
        v[l + k] = temp[k];
}

void mergeSort(vector<int>& v, int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;
    mergeSort(v, l, m);
    mergeSort(v, m + 1, r);
    merge(v, l, m, r);
}

/* --------------------- QUICK SORT --------------------- */

int particiona(vector<int>& v, int l, int r) {
    int pivo = v[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (v[j] <= pivo) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[r]);
    return i + 1;
}

void quickSort(vector<int>& v, int l, int r) {
    if (l < r) {
        int p = particiona(v, l, r);
        quickSort(v, l, p - 1);
        quickSort(v, p + 1, r);
    }
}

/* --------------------- FUNÇÃO PRINCIPAL --------------------- */

int main() {
    string nomeArquivo;
    cout << "Nome do arquivo de entrada: ";
    cin >> nomeArquivo;

    ifstream arq(nomeArquivo);
    if (!arq) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    vector<int> dados;
    int x;

    while (arq >> x) {
        dados.push_back(x);
    }
    arq.close();

    if (dados.empty()) {
        cout << "Arquivo vazio ou inválido!" << endl;
        return 1;
    }

    vector<int> copiaMerge = dados;
    vector<int> copiaQuick = dados;

    /* ---------- Tempo Merge Sort ---------- */
    auto inicioMerge = high_resolution_clock::now();
    mergeSort(copiaMerge, 0, copiaMerge.size() - 1);
    auto fimMerge = high_resolution_clock::now();

    auto tempoMerge = duration_cast<microseconds>(fimMerge - inicioMerge).count();

    /* ---------- Tempo Quick Sort ---------- */
    auto inicioQuick = high_resolution_clock::now();
    quickSort(copiaQuick, 0, copiaQuick.size() - 1);
    auto fimQuick = high_resolution_clock::now();

    auto tempoQuick = duration_cast<microseconds>(fimQuick - inicioQuick).count();

    /* ---------- Saída ---------- */

    cout << "\nLista ordenada (pelo Merge Sort): ";
    for (int n : copiaMerge) cout << n << " ";
    cout << "\n\n";

    cout << "Tempo Merge Sort: " << tempoMerge << " microssegundos\n";
    cout << "Tempo Quick Sort: " << tempoQuick << " microssegundos\n";

    return 0;
}
