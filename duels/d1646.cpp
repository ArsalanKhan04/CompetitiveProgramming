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
#define pii pair<ll, ll>
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
    // cin >> TCS;
    while(TCS--){
      int n;
      cin >> n;
      vvi to(n, vi());
      int U,V;
      FL(i,0,n-1){
        cin>>U>>V; U--; V--;
        to[U].pb(V); to[V].pb(U);
      }
      if (n == 2){
        cout << "2 2\n1 1" << endl;
        continue;
      }
      vector<vpii> dp(n, vpii(2, {0, 0}));
      // dp[i][0] means including 
      // dp[i][1] means excluding
      //

      vector<vector<vpii>> chld(n, vector<vpii>(2, vpii()));

      auto f = [&](auto&& slf, int u, int p)->void{
        
        pii cr_inc = {0, 0};
        pii n_inc = {0, 0};
        for (auto v: to[u]){
          if (v == p) continue;
          slf(slf, v, u);
          cr_inc.F += dp[v][1].F;
          cr_inc.S += dp[v][1].S;
          chld[u][0].pb({v, 1});

          if (dp[v][1].F > dp[v][0].F){
            n_inc.F += dp[v][1].F;
            n_inc.S += dp[v][1].S;
            chld[u][1].pb({v, 1});
          } else if (dp[v][1].F < dp[v][0].F){
            n_inc.F += dp[v][0].F;
            n_inc.S += dp[v][0].S;
            chld[u][1].pb({v, 0});
          } else {
            n_inc.F += dp[v][0].F;
            if (dp[v][0].S < dp[v][1].S){
              n_inc.S += dp[v][0].S;
              chld[u][1].pb({v, 0});
            } else {
              n_inc.S += dp[v][1].S;
              chld[u][1].pb({v, 1});
            }
          }
        }
        n_inc.S++;
        cr_inc.S+=to[u].size();
        cr_inc.F++;
        dp[u][0] = cr_inc;
        dp[u][1] = n_inc;
      };

      vll xa(n, 0);

      auto g = [&](auto &&slf, int u, int pr, int p)->void{
        if (pr == 0){
          xa[u] = to[u].size();
        } else {
          xa[u] = 1;
        }
        for (auto [v, pr2]: chld[u][pr]){
          if (v==p) continue;
          slf(slf, v, pr2, u);
        }
      };

      f(f, 0, -1);
      if (dp[0][0].F == dp[0][1].F){
        if (dp[0][0].S < dp[0][1].S){
          cout << dp[0][0].F << " " << dp[0][0].S << endl;
          g(g, 0, 0, -1);
        } else {
          cout << dp[0][1].F << " " << dp[0][1].S << endl;
          g(g, 0, 1, -1);
        }
      } else if (dp[0][0].F > dp[0][1].F){
          cout << dp[0][0].F << " " << dp[0][0].S << endl;
          g(g, 0, 0, -1);
      } else {
          cout << dp[0][1].F << " " << dp[0][1].S << endl;
          g(g, 0, 1, -1);
      }

      FL(i,0,n){
        cout << xa[i] << " ";
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

