#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);

    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];

    // Initialize dp table
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // Base case
    for (int i = 0; i < N; ++i) {
        dp[i][i] = (a[i] == b[i]) ? 1 : 0;
    }

    // Fill dp table for subarrays of length > 1
    for (int length = 2; length <= N; ++length) {
        for (int i = 0; i <= N - length; ++i) {
            int j = i + length - 1;
            dp[i][j] = (a[i] == b[j]) + (a[j] == b[i]) + dp[i + 1][j - 1];
        }
    }

    // Calculate prefix sums for pref[i]
    vector<int> pref(N, 0);
    pref[0] = dp[0][0];
    for (int i = 1; i < N; ++i) {
        pref[i] = pref[i - 1] + dp[i][i];
    }

    // Result array to count occurrences of c cows being checked
    vector<int> result(N + 1, 0);

    // Calculate the total answer for each subarray (i, j)
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            int cows_checked = (i > 0 ? pref[i - 1] : 0) + (pref[N - 1] - pref[j]) + dp[i][j];
            result[cows_checked]++;
        }
    }

    // Output results
    for (int i = 0; i <= N; ++i) {
        cout << result[i] << "\n";
    }
}

int main() {
    solve();
    return 0;
}
