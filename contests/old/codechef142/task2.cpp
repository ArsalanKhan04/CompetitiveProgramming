#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int
#define MOD % 1000000008
#define FL(i, a, b) for (int i = a; i < b; i++)
#define FE(i, a, b) for (int i = a; i <= b; i++)
#define FF(i, a, b) for (int i = a; i > b; i--)
#define FFE(i, a, b) for (int i = a; i >= b; i--)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'


bool isprime(ll x) {
  if (x == 2 || x == 3)
    return true;
  for (int i = 3; i * i <= x; i++)
    if (x % i > 0)
      return false;
  return true;
}



ull func(ull x){
  if (x == 1 || x == 2) 
    return 6;
  ull num = x > 3 ? 2 * x : 10;
  ull y = 1;
  int count = 0;
  cout <<"num - " << num << endl;
  for (ull i = x + !(x % 2); i < num; i+= 2){
    cout << "here " << endl;
    if (isprime(i)) {
      y *= i;
      cout << "I "  << i << endl;
      num = i * 2;
      count++;
    }
    if (count == 2){
      break;
    }
  }
  return y;
}


void prll_vec(const vector<ll>& vec, ll n) {
    for (ll i = 1; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}


int main() {
  ull t;
  cin >> t;
  FL(i, 0, t) {
    ull x;
    cin >> x;
    cout << func(x) << endl;
  }

  
}
