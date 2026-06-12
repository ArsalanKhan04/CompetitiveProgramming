#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pii pair<int,int>


int main(){
  int tcs; cin>>tcs; while(tcs--){
    int n; cin >> n; 
    vvi to(n); int U,V;
    for(int i=0;i<n-1;i++){
      cin>>U>>V; U--; V--;
      to[U].pb(V); to[V].pb(U);
    }
    auto f=[&](auto &&slf, int u, int p)->pii{
      pii cr={u,0};
      for (auto v: to[u]){
        if (v==p) continue;
        pii nx = slf(slf, v, u);
        if (nx.second > cr.second){
          cr=nx;
        }
      }
      cr.second++;
      return cr;
    };
    auto cr1 = f(f, 0, -1);
    auto cr2 = f(f, cr1.first, -1);
    array<int, 3> ans = {-1, -1, -1};
    auto f2=[&](auto &&slf, int u, int p)->bool{
      int fls=-1, trw=-1;
      for (auto v: to[u]){
        if (v==p) continue;
        bool fl = slf(slf, v, u);
        if (fl){
          trw=v;
        } else fls=v;
      }
      if (fls != -1 && trw != -1){
        ans = {trw, u, fls};
        return true;
      } else if (trw != -1){
        return true;
      } 
      if (u==cr2.first) return true;
      return false;
    };

    f2(f2, cr1.first, -1);
    if (ans[0]==-1){
      cout << -1 << endl;
      continue;
    } else for (int i=0;i<3;i++) cout << ans[i] + 1<< " ";
    cout << endl;
  }
}

