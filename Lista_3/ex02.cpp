#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int>& v, int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;
    mergeSort(v, l, m);
    mergeSort(v, m + 1, r);

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

int main() {
    int n;
    cout << "Quantidade de pilotos: ";
    cin >> n;

    vector<int> tempos(n);
    cout << "Tempos: ";
    for (int i = 0; i < n; i++)
        cin >> tempos[i];

    mergeSort(tempos, 0, n - 1);

    cout << "Tempos ordenados: ";
    for (int t : tempos)
        cout << t << " ";
    cout << endl;

    return 0;
}
