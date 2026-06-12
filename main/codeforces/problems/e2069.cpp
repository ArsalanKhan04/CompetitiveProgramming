#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long int
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

int main(){
  int tcs; cin >> tcs; while (tcs--){
    string s; cin >> s; int n = s.size();
    int a,b,ab,ba; cin>>a>>b>>ab>>ba;
    vi db[2]={vi(), vi()}; int x=0; // ab, ba
    int lf=0;
    // cout << s << endl;
    for (int i=1; i<=n; i++){
      // cout << i << "-i, " << " ";
      if (i < n && s[i]!=s[i-1]){
        continue;
      } else {
        // cout << lf << " ";
        if (lf == i-1){
          if (s[lf]=='A') a--; else b--;
        } else {
          int ind[2]; ind[0]=s[lf]-'A'; ind[1]=s[i-1]-'A';
          if (ind[0]==ind[1]){
            if(ind[0]) b--; else a--;
            x+=(i-lf)/2;
          } else {
            // cout << "ind1: " << ind[1] << endl;
            db[ind[0]].pb((i-lf)/2);
            /*
            */
          }
        }
        lf=i;
      }
      // cout << endl;
    }
    if (a < 0 || b < 0){
      cout << "NO" << endl; continue;
    }
    sort(ALL(db[0])); sort(ALL(db[1]));
    // 01 or ab - db[0]
    // cout << db[0].size() << " " << db[1].size() << endl;
    int pab=0, pba=0;
    // cout << a << " " << b << endl;
    for (auto cr: db[0]){
      if (cr+pab<=ab) pab+=cr;
      else {
        int toad=cr-1;
        toad-=ab-pab; pab=ab;
        pba+=toad; a--; b--; // also the toll for this
      }
    }
    // cout << a << " " << b << " " << pab << " " << pba << endl;
    for (auto cr: db[1]){
      if (cr+pba<=ba) pba+=cr;
      else {
        int toad=cr-1;
        toad-=ba-pba; pba=ba;
        pab+=toad; a--; b--; // the toll for this as well here too
      }
    }
    // cout << a << " " << b << " " << pab << " " << pba << endl;

    // in this case now, either 1 overflows and 1 is full, both overflow
    // it can't be that one is less and the other overflows
    // as when a fills up, only then it start overflowing to b
    // full one overflows to other
    //

    int ex= max(x+pab+pba-(ab+ba), 0);
    a-=ex; b-=ex;
    if (a < 0 || b < 0){
      cout << "NO" << endl;
    } else cout << "YES" << endl;



  }
}
