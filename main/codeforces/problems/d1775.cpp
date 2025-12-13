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


    // doing sieve
    int mx = 3 * (1e5) + 1;
    vvi sv(mx + 1);
    FL(i, 2, mx + 1){
      sv[i].pb(i);
      if (sv[i].size() > 1) continue;
      for (int j = i + i; j < mx + 1; j+=i){
        sv[j].pb(i);
      }
    }

    int n;
    cin >> n;
    vi a(n);
    FL(i, 0, n){
      cin >> a[i];
    }
    int st, ed;
    cin >> st >> ed;
    if (st == ed){
      cout << 1 << endl;
      cout << st << endl;
      return 0;
    }
    vvi to(2 * mx + 1);
    FL(i, 0, n){
      for (int fc: sv[a[i]]){
        to[i + 1].pb(fc + mx);
        to[fc + mx].pb(i + 1);
      }
    }

    // now running bfs for answer
    queue<int> curr_v;
    curr_v.push(st);
    vi visited(2 * mx + 1);
    vi par(2 * mx + 1, -1);
    for (int u; !curr_v.empty(); curr_v.pop()){
      u = curr_v.front();
      if (u == ed) {
        break;
      }
      for (auto v: to[u]){
        if (visited[v]) continue;
        visited[v] = true;
        curr_v.push(v);
        par[v] = u;
      }
    }
    int curr = ed;
    if (par[curr] == -1){
      cout << -1 << endl;
      return 0;
    }
    vi ans;
    while (true){
      if (curr <= mx){
        ans.pb(curr);
      }
      if (curr == st){
        break;
      }
      curr = par[curr];
    }
    reverse(ALL(ans));
    cout << ans.size() << endl;
    for (int x: ans){
      cout << x << " ";
    }
    cout << endl;

#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

