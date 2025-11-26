#include <iostream>
#include <vector>
using namespace std;

long long mergeCount(vector<int>& v, int l, int m, int r) {
    vector<int> left(v.begin() + l, v.begin() + m + 1);
    vector<int> right(v.begin() + m + 1, v.begin() + r + 1);

    int i = 0, j = 0, k = l;
    long long inv = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            v[k++] = left[i++];
        } else {
            v[k++] = right[j++];
            inv += (left.size() - i); // elementos restantes são inversões
        }
    }

    while (i < left.size()) v[k++] = left[i++];
    while (j < right.size()) v[k++] = right[j++];

    return inv;
}

long long countInv(vector<int>& v, int l, int r) {
    if (l >= r) return 0;

    int m = (l + r) / 2;
    return countInv(v, l, m)
         + countInv(v, m + 1, r)
         + mergeCount(v, l, m, r);
}

int main() {
    vector<int> A = {2, 4, 1, 3, 5};
    cout << countInv(A, 0, A.size() - 1) << endl;
    return 0;
}
