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

    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int n;
      cin >> n;
      vi a(n);
      FL(i, 0, n)
        cin >> a[i];

      vi b(n+1, -1);
      vi nxt(n, n);
      vi nxt2(n, n);
      for (int i = n - 1; i >= 0; i--){
        if (b[a[i]] != -1){
          nxt[i] = b[a[i]];
        }
        b[a[i]] = i;
        if (b[a[i]-1] != -1){
          nxt2[i] = b[a[i]-1];
        }
      }

      vi dp(n+1, 0);

      vvi c(n + 1, vi());
      for (int i = 0; i < n + 1; i++){
        c[i].pb(n);
      }
      for (int i = n-1; i>=0; i--){
        c[a[i]].pb(i);
      }


      vi mx_dp(n + 1, 0);

      FL(i,1,n+1){
        int cnt = 0;
        for (auto x: c[i]){
          if (x == n){
            if (i > 1){
              dp[x] = max(dp[x], mx_dp[i-2]);
            }
            continue;
          }
          /*
          auto itr = lower_bound(ALL(tmp), x);
          if (itr != tmp.end()){
          */
          int y = nxt2[x];
          dp[x] = max(dp[x], dp[y]+1);
          //}
          dp[x] = max(dp[x], dp[nxt[x]]+1);
          mx_dp[i] = max(mx_dp[i], dp[x]);
        }
      }

      cout << n - *max_element(ALL(dp)) << endl;





    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

