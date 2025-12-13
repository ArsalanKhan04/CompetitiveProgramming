#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int
#define FL(i, a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
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


#define sz(g) g.size()

/**
 * Author: Lukas Polacek
 * Date: 2009-10-28
 * License: CC0
 * Source: Czech graph algorithms book, by Demel. (Tarjan's algorithm)
 * Description: Finds strongly connected components in a
 * directed graph. If vertices $u, v$ belong to the same component,
 * we can reach $u$ from $v$ and vice versa.
 * Usage: scc(graph, [\&](vi\& v) { ... }) visits all components
 * in reverse topological order. comp[i] holds the component
 * index of a node (a component only has edges to components with
 * lower index). ncomps will contain the number of components.
 * Time: O(E + V)
 * Status: Bruteforce-tested for N <= 5
 */
vi val, comp, z, cont;
vector<array<ll, 2>> cur_size;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
  cur_size = vector<array<ll, 2>>();
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

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
      int n, m;
      cin >> n >> m;
      vi a(n);
      FL(i, 0, n)
        cin >> a[i];
      vvi to(n, vi());
      int U, V;
      FL(i, 0, m){
        cin >> U >> V;
        U--; V--;
        to[U].pb(V);
      }
      scc(to, [&](vi& aa){
        ll sm = 0;
        for (auto x: aa){
          sm += a[x];
        }
        cur_size.push_back({(ll)aa.size(), -1 *sm});
          });
      for (auto[xx, yy]:cur_size){
        dbg(xx, yy);
      }
      vb vis(n, false);
      vector<set<int>> to2(ncomps);
      vi ind(ncomps);
      auto f = [&](auto &&slf, int u)->void{
        if (vis[u]) return;
        vis[u] = true;
        for (auto v: to[u]){
          if (comp[v] != comp[u] && 
              to2[comp[u]].find(comp[v]) == to2[comp[u]].end()){
            to2[comp[u]].insert(comp[v]);
            ind[comp[v]]++;
          }
          slf(slf, v);
        }
      };
      FL(i, 0, n){
        f(f, i);
      }
      vi q;
      FL(i, 0, ncomps){
        if (ind[i] == 0){
          q.pb(i);
        }
      }
      dbg(ncomps);
      array<ll, 2> ans = {-1, -1};
      vector<array<ll, 2>> dp(ncomps, {0, 0});
      auto f2 = [&](auto &&slf, int u)->void{
        dbg(u);
        if (dp[u][0] > 0){
          return;
        }
        for (auto v: to2[u]){
          slf(slf, v);
          dp[u] = max(dp[u], dp[v]);
        }
        dp[u][0] += cur_size[u][0];
        dp[u][1] += cur_size[u][1];
        if (dp[u] > ans) ans = dp[u];
        dbg(u, dp[u][0], dp[u][1]);
      };
      for (auto x:q){
        f2(f2, x);
      }
      cout << ans[0] << " " << ans[1] * -1 << endl;


    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

