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


constexpr int inf = 1e9;

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
      int n, m, q;
      cin >> n >> m >> q;
      vvi e(m, vi(3));
      FL(i, 0, m){
        cin >> e[i][0] >> e[i][1] >> e[i][2];
        e[i][0]--;
        e[i][1]--;
      }
      sort(ALL(e), [](vi &a, vi &b){
        return a[2] < b[2];
          });
      vector<vvi> dp(n, vvi(n, vi(m + 1, inf)));
      FL(i, 0, n){
        dp[i][i][0] = 0;
      }
      for (auto edge: e){
        dp[edge[0]][edge[1]][0] = dp[edge[1]][edge[0]][0] = 1;
      }
      FL(k, 0, n){
        FL(i, 0, n){
          FL(j, 0, n){
            dp[i][j][0] = min(dp[i][k][0] + dp[k][j][0], dp[i][j][0]);
          }
        }
      }
      
      int p = 1;
      vi value(m + 1);
      for (auto edge: e){
        auto u = edge[0], v = edge[1], wt = edge[2];
        FL(i, 0, n){
          FL(j, 0, n){
            dp[i][j][p] = min({dp[i][j][p-1], 
                dp[i][u][p-1] + dp[v][j][p-1],
                dp[i][v][p-1] + dp[u][j][p-1]});
          }
        }
        value[p++] = wt;
      }

      while (q--){
        int a, b, k;
        cin >> a >> b >> k;
        a--; b--;    
        auto itr = lower_bound(RALL(dp[a][b]), k);
        itr--;
        p = dp[a][b].rend() - itr - 1;
        cout << value[p] << " ";
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

