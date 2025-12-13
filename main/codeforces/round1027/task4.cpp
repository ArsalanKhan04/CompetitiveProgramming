
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



int main() {

  ios_base::sync_with_stdio(false);
#ifdef KRAKAR
    ifstream fileIn("input.txt"); 
    cin.rdbuf(fileIn.rdbuf()); 
    ofstream fileOut("output.txt"); 
    cout.rdbuf(fileOut.rdbuf()); 
    auto _clock_start = chrono::high_resolution_clock::now();
#else
    cin.tie(0);
#endif

    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int n;
      cin >> n;
      vpii a(n);
      FL(i, 0, n)
        cin >> a[i].F >> a[i].S;
      if (n == 1){
        cout << 1 << endl;
        continue;
      }
      set<pair<ll, ll>> st1;
      set<pair<ll, ll>> st2;
      FL(i, 0, n){
        st1.insert({a[i].F, a[i].S});
        st2.insert({a[i].S, a[i].F});
      }
      ll ans = 1e9 * (ll)1e9;
      ll ars;
      FL(i, 0, n){
        st1.erase({a[i].F, a[i].S});
        st2.erase({a[i].S, a[i].F});
        ll x1 = (*st1.begin()).F;
        ll x2 = (*st1.rbegin()).F;
        ll y1 = (*st2.begin()).F;
        ll y2 = (*st2.rbegin()).F;
        ars = (y2 - y1 + 1) * (x2 - x1 + 1);
        if (ars < n){
          ars = min(ars + y2 - y1 + 1, ars + x2 - x1 + 1);
        }
        ans = min(ans, ars);
        st1.insert({a[i].F, a[i].S});
        st2.insert({a[i].S, a[i].F});
      }
      cout << ans << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

