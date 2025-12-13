#include <bits/stdc++.h>

using namespace std;
#define ll int64_t

/*
brute force over all [l, r] but how to avoid n^3?
[l, r] depends on [l + 1, r - 1]
the answer for [l + 1, r - 1] in reverse would be the same
our new addition to the answer is only based on a[l] and a[r]
mat[i][j] tell the answer if we reverse [i, j]
mat[i][j] = mat[i + 1][j - 1] + (b[j] == a[i]) + (a[j] == b[i]);
total will be pref[i - 1] + pref[n - 1] - pref[j] + dp[i][j]
*/

int32_t main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	vector<vector<int>> dp(n, vector<int>(n));
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	vector<int> pref(n + 1);
	pref[0] = (a[0] == b[0]);
	for(int i = 1; i < n; i++){
		pref[i] = pref[i - 1] + (a[i] == b[i]);
	}
	for(int i = 0; i < n; i++){
		dp[i][i] = (a[i] == b[i]);
		if(i + 1 < n){
			dp[i][i + 1] = (a[i] == b[i + 1]) + (a[i + 1] == b[i]);
		}
	}
	for(int k = 2; k < n; k++){
		for(int i = 0; i + k < n; i++){
			int j = i + k;
			dp[i][j] = dp[i + 1][j - 1] + (a[i] == b[j]) + (a[j] == b[i]);
		}
	}
	vector<ll> cnt(n + 1, 0);
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			int cur = (i > 0 ? pref[i - 1] : 0) + pref[n - 1] - pref[j] + dp[i][j];
      assert(cur <= n);
			// cout << i << " " << j << " " << cur << '\n';
			cnt[cur]++;
		}
	}	
	for(int i = 0; i <= n; i++){
		cout << cnt[i] << '\n';
	}
}
