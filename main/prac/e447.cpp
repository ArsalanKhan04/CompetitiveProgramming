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
#define sz(x) x.size()

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define condprt(x) cout << ((x) ? "YES" : "NO") << endl



vi val, comp, z, cont;
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
	Time = ncomps = 0;
	FL(i,0,n) if (comp[i] < 0) dfs(i, g, f);
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

    vi seq;
    int zz = 1;

    seq.pb(0);
    while (seq.back() < 100000001){
      seq.pb(zz + seq.back());
      zz++;
    }
    zz = 1;
    vll seq2(seq.size());
    seq2[0] = seq[0];
    while (zz < seq.size()){
      seq2[zz] = seq[zz] + seq2[zz-1];
      zz++;
    }

    int n, m;
    cin >> n >> m;
    vvi to(n);
    vector<array<int, 3>> edgs;
    int x, y, w;
    FL(i, 0, m){
      cin >> x >> y >> w;
      x--; y--;
      to[x].pb(y);
      edgs.pb({x, y, w});
    }
    int s;
    cin >> s;
    scc(to, [](vi&){});
    vector<vector<pair<int, ll>>> toN(ncomps);
    vll wgts(ncomps, 0);
    for (auto [X, Y, W]: edgs){
      if (comp[X] == comp[Y]){
        auto itr = upper_bound(ALL(seq), W);
        itr--;
        int nz = itr - seq.begin();
        wgts[comp[X]] += (ll) (nz + 1) * (ll) W - seq2[nz];
      } else {
        toN[comp[X]].pb({comp[Y], W});
      }
    }
    vll dp(ncomps, -1);

    auto dfs = [&](auto&& slf, auto u)->ll{
      if (dp[u] != -1) return dp[u];
      ll mx = 0;
      for (auto [v, ww]: toN[u]){
        mx = max(mx, (ll)slf(slf, v) + (ll)ww);
      }
      return dp[u] = mx + (ll)wgts[u];
    };

    s--;
    ll ans = dfs(dfs, comp[s]);
    cout << ans << endl;

#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

