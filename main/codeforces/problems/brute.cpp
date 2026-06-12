#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

int main(){
  int tcs; cin >> tcs;
  int n; cin >> n;
  int c1,c2,c;
  c1=c2=c=0;
  auto g = [&](vi cr){
    vi br(n+1,0);
    for (int i=1; i<cr.size(); i++){
      br[cr[i]]+=i;
    }
    if (br==cr){
      if (cr.back()==n) {
        c1++;
      } else c2++;
      for (auto x: cr){
        cout << x << " ";
      }
      cout << endl;
    }
  };
  auto f=[&](auto &&slf, vi cr)->void{
    if (cr.size() < n+1){
      for (int i=0;i<=3*n;i++){
        if (i==0 && cr.size()==n) continue;
        if (cr.size()>0 && i>n) continue;
        cr.push_back(i);
        slf(slf, cr);
        cr.pop_back();
      }
    } else {
      g(cr);
    }
  };
  f(f, vi());
  c=c1+c2;
  cout << c1 << " " << c2 << " " << c << endl;
}
