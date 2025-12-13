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
      vvi a(2, vi(n));
      FL(i, 0, n)
        cin >> a[0][i];
      FL(i, 0, n)
        cin >> a[1][i];
      vector<vpii> b(2*n+1);
      FL(i,0,n){
        b[a[0][i]].pb({0, i});
        b[a[1][i]].pb({1, i});
      }

      set<int> zrs;
      set<int> ons;

      FL(i,0,n){
        zrs.insert(i);
        ons.insert(i);
      }

      int l = 1;
      int r = 1;

      ll ans = 0;
      while (l <= 2 * n){

        int up = 0, dn = 0;
        if (zrs.empty()) up = n;
        else up = *zrs.begin();
        
        if (ons.empty()) dn = n;
        else dn = n - 1 - *ons.rbegin();

        if (up + dn < n + 1){
          if (r > 2*n) break;
          for (auto br: b[r]){
            if (br.F == 1){
              ons.erase(br.S);
            } else {
              zrs.erase(br.S);
            }
          }
          r++;
          continue;
        }
        dbg(l, r, 2*n);
        ans += 2 * n - r + 2;
        for (auto bl: b[l]){
          if (bl.F == 1){
            ons.insert(bl.S);
          } else {
            zrs.insert(bl.S);
          }
        }
        l++;
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

