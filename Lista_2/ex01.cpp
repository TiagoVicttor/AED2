#include <iostream>
using namespace std;

void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        cout << "Mover disco 1 de " << origem << " para " << destino << endl;
        return;
    }

    hanoi(n - 1, origem, auxiliar, destino);
    cout << "Mover disco " << n << " de " << origem << " para " << destino << endl;
    hanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    int n = 3;  // número de discos
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
