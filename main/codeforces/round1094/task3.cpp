#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long int
#define FL(i,x,y) for(int i=x; i<y; i++)
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

int main(){
  int tcs; cin >> tcs; while(tcs--){
    int n; cin >> n; vi a(n+1,0);
    FL(i,1,n+1) cin>>a[i];
    auto b=a; sort(ALL(b));
    int md=b[(n+1)/2];

    vi l(n+1,0); vi g(n+1,0);
    FL(i,1,n+1){
      l[i]=l[i-1]; g[i]=g[i-1];
      if (a[i]<=md) l[i]++; else l[i]--;
      if (a[i]>=md) g[i]++; else g[i]--;
    }
    vi dp(n+1, -100000);
    dp[0]=0;
    FL(i,1,n+1){
      FL(j,0,i){
        if (l[i]-l[j]>0 && g[i]-g[j]>0 && (i-j)&1){
          dp[i]=max(dp[i], dp[j]+1);
        }
      }
    }
    cout << dp[n] << endl;
  }
}
