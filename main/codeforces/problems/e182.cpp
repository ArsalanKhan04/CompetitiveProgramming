#include <bits/stdc++.h>
#include <map>
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
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
#define pii pair<int, int>
#define vpii vector<pii>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
#define endl '\n'
 
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

  int t;
  cin >> t;
  FL(et, 0, t) {
    int n;
    cin >> n;
    vi cl(n);
    FL(i, 0, n){
      cin >> cl[i];
      --cl[i];
    }
    vvi adj(n);
    FL(i, 0, n - 1){
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    vector<map<int, ll>> tc(n, map<int, ll>());
    ll ans = 0;
    function <void(int, int)> dfs = [&](int u, int p){
      int bst = -1;
      for (int x: adj[u]){
        if (x == p)
          continue;
        dfs(x, u);
        if (bst == -1 || tc[bst].size() < tc[x].size()){
          bst = x;
        }
      }
      dbg(u);
      for (int x: adj[u]){
        if (x != p && x!=bst){
          for (const auto& [c, cnt]: tc[x]){
            if (c != cl[u]){
              ans += cnt * tc[bst][c];
            }
            tc[bst][c] += cnt;
          }
        }
      }
      dbg(bst);
      dbg(cl[u]);
      if (bst != -1){
        dbg(tc[bst][cl[u]]);
        ans += tc[bst][cl[u]];
        swap(tc[u], tc[bst]);
      }
      tc[u][cl[u]] = 1;

    };
    dfs(0, -1);
    cout << ans << endl;
  }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

