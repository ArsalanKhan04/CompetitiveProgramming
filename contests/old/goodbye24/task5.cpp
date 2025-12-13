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
#define vll vector<ll>
#define vvll vector<vll>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define vll vector<ll>
#define vvll vector<vll>

#define REMAX(a, b) a = max((a), (b))
#define REMIN(a, b) a = min((a), (b))

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define INF int(1e9) + 9
 
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

    int testcases = 1;
    cin >> testcases;
    while(testcases--){
      int n;
      cin >> n;
      vvi a(n + 1, vi());
      vector<map<int, int>> cum_c(n + 1, map<int, int>());
      vector<map<int, int>> cum_b(n + 1, map<int, int>());
      int x, y;
      FL(i, 0, n - 1){
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
      }
      vi nds(n + 1, 0);
      FL(i, 1, n + 1){
        if (a[i].size() == 1){
          nds[a[i][0]] = 1;
        }
      }
      FL(i, 1, n + 1){
        if (a[i].size() == 1){
          nds[i] = 2;
        }
      }
      int bs = 0;
      int cs = 0;
      int as = 0;
      FL(i, 1, n + 1){
        if (nds[i] == 1) bs++;
        if (nds[i] == 0) cs++;
        if (nds[i] == 2) as++;
      }
      auto f1 = [&](auto && self, int u, int p){
        dbg(u);
        if (p != -1 && nds[u] == 2)
          return;
        int xx = 1;
        for (int v: a[u]){
          if (v == p){
            continue;
          }
          self(self, v, u);
          cum_c[u][v] += cum_c[v][0];
          cum_b[u][v] += (nds[v] != 2);
          cum_c[u][0] += cum_c[v][0];
          cum_b[u][0] += (nds[v] != 2);
          x++;
        }
        if (p != -1 && nds[p] != 2){
          cum_b[u][p]++;
          cum_b[u][0]++;
        }
        if (nds[u] == 0){
          cum_c[u][0]++;
        }  
      };
      auto f2 = [&](auto &&self, int u, int p){
        if (p != -1 && nds[u] == 2)
          return;
        if (p != -1){
          cum_c[u][p] += cum_c[p][0] - cum_c[u][0];
          cum_c[u][0] += cum_c[p][0] - cum_c[u][0];
        }
        for (int v: a[u]){
          if (v == p){
            continue;
          }
          self(self, v, u);
        }
      };
      dbg("Here");
      f1(f1, 1, -1);
      dbg("Here");
      f2(f2, 1, -1);

      ll ans = 0;
      FL(i, 1, n + 1){
        if (nds[i] != 1) continue;
        dbg(cum_c[i][0]);
        dbg(cum_b[i][0]);
        for (int u: a[i]){
          ans += ((ll)cum_c[i][0] - cum_c[i][u]) * (cum_b[i][u]);
        }
      }
      ans += (as * ((ll)bs + cs));
      cout << ans << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

