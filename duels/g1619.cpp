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

struct DSU {
  vector<int> par, rnk, sz;
  int c;
  DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
    for (int i = 1; i <= n; ++i) par[i] = i;
  }
  int find(int i) {
    return (par[i] == i ? i : (par[i] = find(par[i])));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() {
    return c;    //connected components
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    else --c;
    if (rnk[i] > rnk[j]) swap(i, j);
    par[i] = j;
    sz[j] += sz[i];
    if (rnk[i] == rnk[j]) rnk[j]++;
    return j;
  }
};

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
      int n, k;
      cin >> n >> k;
      DSU dsu(n);
      int X, Y, T;
      map<int, vector<pii>> mp1;
      map<int, vector<pii>> mp2;
      vi tms(n + 1);
      FL(i, 1, n + 1){
        cin >> X >> Y >> T;
        mp1[X].pb({Y, i});
        mp2[Y].pb({X, i});
        tms[i] = T;
      }
      for (auto [x, vy]: mp1){
        sort(ALL(vy));
        for (int i = 1; i < vy.size(); i++){
          if (vy[i].F - vy[i-1].F <= k){
            dsu.merge(vy[i].S, vy[i-1].S);
          }
        }
      }
      for (auto [x, vy]: mp2){
        sort(ALL(vy));
        for (int i = 1; i < vy.size(); i++){
          if (vy[i].F - vy[i-1].F <= k){
            dsu.merge(vy[i].S, vy[i-1].S);
          }
        }
      }
      FL(i, 1, n + 1){
        int pr = dsu.find(i);
        tms[pr] = min(tms[pr], tms[i]);
      }
      set<pii> st;
      FL(i, 1, n + 1){
        int pr = dsu.find(i);
        st.insert({pr, tms[pr]});
      }
      vi tvs;
      for (auto [x, tt]: st){
        tvs.pb(tt);
      }
      sort(RALL(tvs));
      int ans = 0;
      FL(i, 0, tvs.size()){
        ans = max(ans, min(i, tvs[i]));
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

