#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int alvo = 7;
    vector<int> moedas = {1, 3, 4};

    // dp[i] = mínimo de moedas para somar exatamente i
    vector<int> dp(alvo + 1, INT_MAX);
    dp[0] = 0; // 0 moedas para fazer 0

    for (int i = 1; i <= alvo; i++) {
        for (int m : moedas) {
            if (i - m >= 0 && dp[i - m] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - m] + 1);
            }
        }
    }

    cout << "Menor numero de missoes: " << dp[alvo] << endl;

    return 0;
}
