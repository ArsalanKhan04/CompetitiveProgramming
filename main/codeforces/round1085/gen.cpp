#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    mt19937 rng(atoi(argv[1]));  // seed from command line for reproducibility
    auto rand_int = [&](int l, int r) {
        return uniform_int_distribution<int>(l, r)(rng);
    };

    int TCS = 1;
    cout << TCS << "\n";

    while (TCS--) {
        int n = rand_int(5, 10);
        cout << n << "\n";
        for (int i = 0; i < n; i++)
            cout << rand_int(0, 20) << " \n"[i == n-1];
    }

    return 0;
}
