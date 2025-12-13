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


constexpr ll inf = 1e17 + 13;

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
    // cin >> TCS;
    while(TCS--){
      int n, m;
      cin >> n >> m;
      vector<vector<array<ll, 2>>> a(n, vector<array<ll, 2>>());
      int A, B, C;
      FL(i, 0, m){
        cin >> A >> B >> C;
        A--;
        B--;
        a[A].pb({B, C});
        a[B].pb({A, C});
      }
      vvll dp(n, vll(n, inf));
      ll K, T;
      cin >> K >> T;
      vll airp(K);
      vb is_ap(n, false);
      FL(i, 0, K){
        cin>>airp[i];
        airp[i]--;
        is_ap[airp[i]] = true;
      }
      for (auto i: airp){
        for (auto j: airp){
          if (i == j) continue;
          dp[i][j] = T;
          dp[j][i] = T;
        }
      }
      FL(i, 0, n){
        for (auto [v, w]: a[i]){
          dp[i][v] = min(dp[i][v], w);
        }
      }
      FL(i, 0, n){
        dp[i][i] = 0;
      }
      FL(k, 0, n){
        FL(i, 0, n){
          FL(j, 0, n){
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
          }
        }
      }
      ll fans = 0;
      FL(i, 0, n){
        FL(j, 0, n){
          if (dp[i][j] != inf){
            fans += dp[i][j];
          }
        }
      }
      vll d_airp(n, inf);
      FL(i, 0, n){
        FL(j, 0, n){
          if (d_airp[i] > dp[i][j] && is_ap[j]){
            d_airp[i] = dp[i][j];
          }
        }
      }
      int q;
      cin >> q;
      ll x, y, t;
      while (q--){
        cin >> x;
        if (x == 3){
          cout << fans << endl;
        } else if (x == 2){
          cin >> y;
          y--;
          airp.pb(y);
          is_ap[y] = true;
          // update if destination is y
          for (auto i: airp){
            if (dp[i][y] > T){
              if (dp[i][y] != inf)
                fans -= (dp[i][y]) * 2;
              dp[i][y] = T;
              dp[y][i] = T;
              fans += dp[i][y]*2;
            }
          }
          for (auto i: airp){
            FL(j, 0, n){
              if (dp[y][j] > dp[y][i] + dp[i][j]){
                if (dp[y][j] != inf)
                  fans -= 2*dp[y][j];
                dp[y][j] = dp[y][i] + dp[i][j];
                dp[j][y] = dp[y][j];
                fans += 2*dp[y][j];
              }
            }
          }
          FL(i, 0, n){
            FL(j, 0, n){
              if (dp[i][j] > dp[i][y] + dp[y][j]){
                if (dp[i][j] != inf)
                  fans -= 2*dp[i][j];
                dp[i][j] = dp[i][y] + dp[y][j];
                dp[j][i] = dp[i][j];
                fans += 2*dp[i][j];
              }
            }
          }
          FL(i, 0, n){
            FL(j, 0, n){
              if (d_airp[i] > dp[i][j] && is_ap[j]){
                d_airp[i] = dp[i][j];
              }
            }
          }
        } else if (x == 1){
          int y1, y2;
          cin >> y1 >> y2 >> t;
          y1--; y2--;
          a[y1].pb({y2, t});
          a[y2].pb({y1, t});
          if (dp[y1][y2] > t){
            dbg(fans);
            if (dp[y1][y2] != inf)
              fans -= (dp[y1][y2]) * 2;
            dp[y1][y2] = t;
            dp[y2][y1] = t;
            fans += t * 2;
            dbg(fans);
          }
          FL(i, 0, n){
            FL(j, 0, n){
              ll cd = dp[i][y1] + dp[y1][y2] + dp[y2][j];
              if (dp[i][j] > cd){
                if (dp[i][j] != inf)
                  fans -= 2*dp[i][j];
                dp[i][j] = cd;
                dp[j][i] = cd;
                fans += 2*dp[i][j];
              }
            }
          }
        }
      }



    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

