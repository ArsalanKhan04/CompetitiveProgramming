#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int md=1e9+7;

int main(){
  int tcs; cin >> tcs;
  while (tcs--){
    int n,q; cin>>n>>q;
    //cout << n << " " << q << endl;
    int li,ri;
    vector<array<int,2>> to(n+1);
    for(int i=1; i<n+1; i++){
      cin>>li>>ri;
      to[i]={li,ri};
    }
    vector<ll> dp1(n+1), dp2(n+1);
    auto f1=[&](auto&& slf, int u)->void{
       if (!to[u][0]) {
          dp1[u]=1;
          return;
       }
       slf(slf,to[u][0]); slf(slf,to[u][1]);
       dp1[u]=dp1[to[u][0]]+dp1[to[u][1]]+3;
    };
    f1(f1,1);


    auto f2=[&](auto&& slf, int u, ll prv)->void{
      dp2[u]=prv+dp1[u];
      if (to[u][0]){
        slf(slf,to[u][0],dp2[u]); slf(slf,to[u][1],dp2[u]);
      }
    };
    f2(f2,1,0);

    vector<vector<int>> bl(n+1, vector<int>(23,0));

    auto f3=[&](auto &&slf, int u, int k)->void{
      if (k==0){
        if (to[u][0]){
          bl[to[u][0]][k]=u; bl[to[u][1]][k]=u;
        }
      } else {
        bl[u][k]=bl[bl[u][k-1]][k-1];
      }
      if (to[u][0]){
        slf(slf, to[u][0], k); slf(slf, to[u][1], k);
      }
    };
    //cout << "Trying f3" << endl;
    for (int k=0; k<23; k++){
      f3(f3, 1, k);
    }

    vector<int> eul;
    vector<int> eind(n+1,-1);
    auto f4=[&](auto &&slf, int u)->void{
      eul.push_back(u);
      //cout << u << endl;
      //cerr << to[u][0] << endl;
      if (to[u][0]){
        slf(slf, to[u][0]);
        eul.push_back(u);
        slf(slf, to[u][1]);
        eul.push_back(u);
      }
      return;
    };
    //cout << "Trying f4" << endl;
    f4(f4,1);
    //cout << "eul size" << eul.size() << endl;
    for (int i=0; i<eul.size(); i++){
      //cout << eul[i] << " eindsize " << eind.size() << endl;
      if (eind[eul[i]]==-1) eind[eul[i]]=i;
      //cout << "NEXT" << endl;
    }
    /*

    while (q--){
      int v,k; cin>>v>>k;
      cerr << v << " " << k << endl;
      int cr=v;
      for (int pw=22;pw>=0;pw++){
        int pr=bl[cr][pw];
        if (dp2[v]-dp2[pr] <= k){
          k-=dp2[v]-dp2[pr];
          cr=pr;
        }
      }
      int cind=eind[cr];
      cout << eul[cind+k] << endl;
    }
    */


    while (q--){
      int v,k; cin>>v>>k;
      int cr=v;
      //cout << "Cr: " << cr << endl;
      for (int pw=22;pw>=0;pw--){
        int pr=bl[cr][pw];
        //cout << "pr: " << pr << endl;
        //cout << dp2.size() << endl;
        if (dp2[cr]-dp2[pr] <= k){
          k-=dp2[cr]-dp2[pr];
          cr=pr;
        }
      }
      int cind=eind[cr];
      cout << eul[cind+k] << " ";
    }
    cout << endl;


  }

}
