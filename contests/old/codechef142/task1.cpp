#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int
#define MOD % 1000000007
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


ll func(ll n, vector<ll> arr){
  cout << log2(0) << endl;
  sort(ALL(arr), greater<ll>());
  ll num = 0;
  ll msb;
  ll temp;
  ll count = 0;
  FL(i, 0, n - 1){
    msb = log2(arr[i+1]);
    temp = arr[i] >> (msb + 1);
    if (log2(temp + 1) - (ll)log2(temp + 1) > 0){
      count = i + 1;
    } else {
      arr[i+1] |= arr[i];
    }
  }
  temp = arr[n-1];
  if (log2(temp + 1) - (ll)log2(temp + 1) > 0)
    return n;

  return count;

    
}


void prll_vec(const vector<ll>& vec, ll n) {
    for (ll i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}


int main() {
  ll t;
  cin >> t;
  FL(i, 0, t) {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    FL(i, 0, n)
      cin >> arr[i];

    cout << func(n, arr) << endl;
  }

  
}
