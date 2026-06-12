#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define FL(i,x,y) for(int i=x; i<y; i++)
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define ll long long int
#define vll vector<ll>

int main(){
  int tcs; cin >> tcs; while (tcs--){
    int n; cin >> n;
    vll a(n+2); FL(i,1,n+1) cin>>a[i];
    auto b=a;
    for (int i=n; i>=1; i--){
      b[i]+=b[i+1];
    }
    vector<pair<long long, long long>> bp;
    FL(i,1,n+1){
      bp.pb({b[i], i});
    }
    sort(ALL(bp));
    vi ans(n+1);
    int ind=1;
    for (auto [ky, vl]: bp){
      ans[vl]=ind++;
    }
    FL(i,1,n+1){
      cout << ans[i] << " ";
    }
    cout << endl;
  }




}
