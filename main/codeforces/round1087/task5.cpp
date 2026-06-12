#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long int
#define vll vector<ll>

vll Z(string s){
  int n=s.size();
  vll z(n, 0); z[0]=n;
  ll l,r; l=0; r=1;
  for (int i=1; i<n; i++){
    z[i]=max(min(z[i-l], r-i), 0LL);
    int j=z[i];
    while(j < n-i && s[j]==s[i+j]){
      z[i]++; j++;
    }
    if (i+j>r){
      l=i; r=i+j;
    }
  }
  return z;
}

ll an(string s){
  int n=s.size();
  auto z = Z(s);
  vll dp(n,1);
  vll rm(n+1,-1);
  vll cnt(n+1, 0);
  cnt[1]=1;
  ll M=1;

  auto mprv=[&cnt, &M](ll vl){cnt[vl]--; while (M>1 && !cnt[M]) M--;};
  auto mpad=[&cnt, &M](ll vl){cnt[vl]++; if (vl>M) M=vl;};

  for(int i=1; i<n; i++){
    if (rm[i] != -1) mprv(rm[i]);
    if (z[i]>0){
      ll rmi=i+z[i];
      mpad(dp[i-1]+1);
      if (rm[rmi]!=-1){
        mprv(rm[rmi]);
      }
      rm[rmi]=dp[i-1]+1;
    }
    dp[i]=M;
  }
  ll sm=accumulate(dp.begin(), dp.end(), 0LL);
  return sm;
}

int main(){
  int tcs; cin>> tcs; while(tcs--){
    int n,q; cin >> n >> q;
    string s; cin >> s;
    // cout << s << endl;
    int li,ri;
    while (q--){
      cin>>li>>ri; li--;
      string t = s.substr(li, ri-li);
      cout << (ll)an(t) << endl;
    }
  }
}
