#include <bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define ll long long int
#define vll vector<ll>


vll Pi(string s){
  int n = s.size();
  vll pi(n, 0);
  for (int i=1; i<n; i++){
    int j = pi[i-1];
    while (s[j]!=s[i] && j > 0){
      j=pi[j-1];
    }
    if (s[j]==s[i]){
      pi[i]=j+1;
    }
  }
  return pi;
}

int main(){
  int tcs; cin >> tcs; while(tcs--){
    int n,q; cin >> n >> q;
    string s; cin >> s;
    int li, ri;
    while (q--){
      cin >> li >> ri; li--;
      string t = s.substr(li, ri-li);
      int m = t.size();
      auto pi = Pi(t);
      for (int i=1; i<m; i++){
        while (pi[i]>0 && pi[pi[i]-1]) {
          pi[i]=pi[pi[i]-1];
        }
      }
      vll dp(m,1);
      for (int i=1; i<m; i++){
        if (pi[i]==0) dp[i]=1;
        else if (pi[i]) dp[i]=dp[i-pi[i]]+1;
      }
      cout << accumulate(dp.begin(), dp.end(), 0LL) << endl;
    }
  }
}
