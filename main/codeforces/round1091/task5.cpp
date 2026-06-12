#include <bits/stdc++.h>
using namespace std;


#define vi vector<int>
#define vvi vector<vi>


int main(){
  int tcs; cin>>tcs;
  while(tcs--){
    int n;
    cin >> n;
    vi p(n), d(n);
    for(int i=0; i<n; i++) cin>>p[i];
    for(int i=0; i<n; i++) cin>>d[i];

    vi ord; int cnt,rm,ix; bool fl=true;
    for (int i=n-1; i>=0; i--){
      cnt=0;
      for (auto x: ord){
        if (p[x]>p[i]) cnt++;
      }
      if (cnt<d[i]){
        fl=false;break;
      }
      rm=cnt-d[i]; ix=0;
      for (auto x: ord){
        if (rm==0){
          break;
        }
        if (p[x]>p[i]) rm--;
        ix++;
      }
      ord.insert(ord.begin()+ix,i);
    }
    if(!fl){
      cout << -1 << endl; continue;
    }
    vi q(n);
    int ind=1;
    for (auto x: ord){
      q[x]=ind++; 
    }
    for (auto x: q){
      cout << x << " ";
    }
    cout << endl;

  }
}
