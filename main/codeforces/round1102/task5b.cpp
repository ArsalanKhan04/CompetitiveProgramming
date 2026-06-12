#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int
#define FL(i, a, b) for (int i = a; i < b; i++)
#define FE(i, a, b) for (int i = a; i <= b; i++)
#define FF(i, a, b) for (int i = a; i > b; i--)
#define FFE(i, a, b) for (int i = a; i >= b; i--)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>
#define vpii vector<pii>
#define vll vector<ll>
#define vvll vector<vll>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define vll vector<ll>
#define vvll vector<vll>
#define endl '\n'
#define REMAX(a, b) a = max((a), (b))
#define REMIN(a, b) a = min((a), (b))

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define condprt(x) cout << ((x) ? "YES" : "NO") << endl


int main(){
  
  map<vi, ll> mp;

  // do permutation of 3
  vi perm3(3), perm4(4), perm5(5);
  iota(ALL(perm3), 1); iota(ALL(perm4), 1);
  iota(ALL(perm5), 1);

  auto f = [mp](vi cur){
    int n = cur.size();
    vi a(n, 0);
    FL(i,0,n){
      FL(j,0,i+1){
        FL(k,i,n){
          bool fl = true;
          FL(cr,j,k+1){
            if (cr == i) continue;
            if (cur[cr] < cur[i]) fl = false;
          }
          a[i]+=fl;
        }
      }
    }
    return a;
  };

  while (true){
    mp[f(perm3)]++;
    if (!next_permutation(ALL(perm3))) break;
  }
  while (true){
    mp[f(perm4)]++;
    if (!next_permutation(ALL(perm4))) break;
  }
  while (true){
    mp[f(perm5)]++;
    if (!next_permutation(ALL(perm5))) break;
  }

  cout << mp.size() << endl;
  freopen("input1.txt", "w", stdout);

  cout << mp.size() << endl;
  for (auto [ky, vl]: mp){
    cout << ky.size() << endl;
    for (auto x: ky){
      cout << x << " ";
    }
    cout << endl;
  }
  freopen("output1.txt", "w", stdout);

  for (auto [ky, vl]: mp){
    cout << vl << endl;
  }






}
