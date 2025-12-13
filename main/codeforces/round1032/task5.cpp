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


const int inf = 1e9;

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
      int ln, rn; cin>>ln>>rn;
      vi a, b;
      while (ln){
        a.pb(ln % 10);
        b.pb(rn % 10);
        ln /= 10;
        rn /= 10;
      }
      a.pb(0);
      b.pb(0);
      reverse(ALL(a));
      reverse(ALL(b));
      int n = a.size() - 1;
      auto f = [&](int i, int j){
        return (a[i] == j) + (b[i] == j);
      };
      vector<vvi> dp(4, vvi(n + 1, vi(10, inf)));

      dp[3][0][0] = 0;
      FL(i, 1, n + 1){
        FL(j, 0, 10){
          FL(k, 0, 10){
            dp[0][i][j] = min(dp[0][i-1][k] + f(i, j), dp[0][i][j]);
            if (a[i] == j && b[i] == j){
              dp[3][i][j] = min(dp[3][i-1][k] + 2, dp[3][i][j]);
            } else if (a[i] == j && j < b[i]){
              dp[1][i][j] = min(dp[3][i-1][k] + 1, dp[1][i][j]);
            } else if (j > a[i] && j == b[i]){
              dp[2][i][j] = min(dp[3][i-1][k] + 1, dp[2][i][j]);
            } else if (j > a[i] && j < b[i]){
              dp[0][i][j] = min(dp[3][i-1][k], dp[0][i][j]);
            }
            if (j > a[i]){
              dp[0][i][j] = min(dp[1][i-1][k] + f(i, j), dp[0][i][j]);
            } else if (j == a[i]){
              dp[1][i][j] = min(dp[1][i-1][k] + f(i, j), dp[1][i][j]);
            }
            if (j < b[i]){
              dp[0][i][j] = min(dp[2][i-1][k] + f(i, j), dp[0][i][j]);
            } else if (j == b[i]){
              dp[2][i][j] = min(dp[2][i-1][k] + f(i, j), dp[2][i][j]);
            }
          }
        }
      }
      int ans = inf;
      FL(l, 0, 4){
        FL(j, 0, 10){
          ans = min(ans, dp[l][n][j]);
        }
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

