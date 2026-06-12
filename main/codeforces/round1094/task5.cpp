#include <bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define ll long long int
#define FL(i,x,y) for(int i=x; i<y; i++)
#define endl "\n"; cout.flush()


int n; int x;
ll chck(){
  ll cvl = (1LL<<n) - 1;
  for (int i=n-1; i>=0; i--){
    cvl -= (1LL<<i);
    cout << "Q " << cvl+1 << endl;
    cin >> x;
    if (x == 1){
      cvl += (1LL<<i);
    }
  }
  return cvl;
}

int main(){
  int tcs; cin>>tcs; while(tcs--){
    cin >> n;
    cout << 0 << endl;
    ll nm = (1LL<<n) -1;
    cout << "I " << 0 << endl;
    cin >> x; ll avl;
    if (x==1){
      cout << "I " << nm << endl;
      cin >> x;
      avl = chck();
      cout << "A 1 " << avl << endl;
      continue;
    }
    avl = chck();
    if (avl == nm){
      ll avl1 = (avl-1)&avl;
      cout << "I " << avl1 << endl;
      cin >> x;
      if (x == 3){
        cout << "A 3 " << avl << endl;
      } else {
        cout << "A 2 " << avl << endl;
      }
    } else {
      cout << "I " << nm << endl;
      cin >> x;
      cout << "Q " << nm << endl;
      cin >> x;
      if (x == 1){
        cout << "A 2 " << avl << endl;
      } else {
        cout << "A 3 " << avl << endl;
      }
    }
  }
}
