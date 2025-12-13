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
      vector<vector<array<int, 2>>> to(n, vector<array<int, 2>>());
      int U, V, X, Y;
      FL(i, 0, n-1){
        cin >> U >> V >> X >> Y;
        U--; V--;
        to[U].pb({V, X-Y}); // if positive then pu > pv
        to[V].pb({U, Y-X}); // if positive pv > pu
      }
      vi sz(n, 0);
      auto f1 = [&](auto &&slf, int u, int p)->void{
        for (auto [v, x]: to[u]){
          if (v==p) continue;
          slf(slf, v, u);
          sz[u] += sz[v];
        }
        sz[u] += 1;
      };
      vi st(n, -1);
      vi fn(n, -1);
      st[0] = 0;
      f1(f1, 0, -1);
      FL(i, 0, n){
        cerr << sz[i] << " ";
      }
      cerr << endl;
      auto f2 = [&](auto &&slf, int u, int p)->void{
        dbg(u, st[u], sz[u]);
        int ng = 0;
        int ps = 0;
        for (auto [v, x]: to[u]){
          if (v == p) continue;
          if (x > 0){
            st[v] = ng + st[u];
            ng+=sz[v];
            slf(slf, v, u);
          }
        }
        for (auto [v, x]: to[u]){
          if (v == p) continue;
          if (x <= 0){
            st[v] = ng+ps+st[u]+1;
            ps+=sz[v];
            slf(slf, v, u);
          }
        }
        fn[u]=st[u]+ng+1;
      };
      f2(f2, 0, -1);
      FL(i,0,n){
        cout << fn[i] << " ";
      }
      cout << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

