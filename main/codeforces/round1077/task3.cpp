#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define ll long long


int main(){
  int tcs; cin>>tcs; while(tcs--){
    int n,m,U,V; cin>>n>>m;    
    vi to(n+1); vvi rto(n);
    iota(to.begin(), to.end(), 1);
    for (int i=0; i<m; i++){
      cin>>U>>V;
      to[U]=max(to[U],V);
    }
    // cout << "HERE" << endl;

    for (int i=1; i<n; i++){
      // cout << n-to[i] << " " << n-i <<endl;
      rto[n-to[i]].push_back(n-i);
    }

    vi d(n), wgt(n);
    auto f1=[&](auto &&slf, int u, int dpt)->void{
      d[u]=dpt;
      for (auto v: rto[u]){
        slf(slf, v, dpt+1);
        wgt[u]+=wgt[v];
      }
      wgt[u]++;
    };
    f1(f1,0,0);
    // cout << "F1 done" << endl;

    ll an=0;
    vi dr = d;
    sort(dr.begin(), dr.end());

    // sum{min(dx,dy)}
    ll sz=n;
    for (int i=0; i<n;i++){
      sz--;
      an+=dr[i]*sz;
    }
    // cout << an << endl;

    // sum{d(lca(x,y))}
    auto f2=[&](auto &&slf, int u)->void{
      ll ps=0;
      for (auto v: rto[u]){
        slf(slf, v);
      }
      for (auto v: rto[u]){
        an -= ps*wgt[v]*d[u];
        // cout << ps << "*" << wgt[v] << "*" << d[u] << endl;
        // cout << an << endl;
        ps+=wgt[v];
      }
      an -= ps*d[u];
    };
    f2(f2, 0);
    // cout << "F2 done" << endl;

    /*
    for (int i=0; i<n;i++){
      cout << i << "-" << d[i] << " ";
    }
    cout << endl;
    */
    vector<map<int,int>> mp(n);
    auto f3=[&](auto &&slf, int u){
      if (rto[u].size()==0){
        mp[u][d[u]]++;
        return;
      }
      int vmx = rto[u][0];
      for (auto v: rto[u]){
        slf(slf, v);
        if (mp[v].size()>mp[vmx].size()){
          vmx=v;
        }
      }
      swap(mp[u], mp[vmx]);
      // cout << "u: " << u << endl;
      for (auto v: rto[u]){
        if (v==vmx){
          continue;
        }
        for (auto [ky, vl]: mp[v]){
          // cout << vl << " " << mp[u][ky] << " " << ky << " " << d[u] << endl;
          an+=(ll)vl*mp[u][ky]*ky;
          an-=(ll)vl*mp[u][ky]*d[u];
          mp[u][ky]+=vl;
        }
      }
      mp[u][d[u]]++;
    };

    f3(f3, 0);
    cout << an << endl;





  }
}
