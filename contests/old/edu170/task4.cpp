
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
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

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
    // cin >> testcases;
    while(testcases--){
      int n, m;
      cin >> n >> m;
      vi r(n);
      FL(i, 0, n){
        cin >> r[i];
      }
      vvi dp(m + 1, vi(m + 1, 0));
      vi a(m + 2, 0);
      vi b(m + 2, 0);
      int curr = 0;
      FL(i, 0, n){
        if (r[i] == 0){
          // we will update values of all i, j whose sum are curr
          FL(x, 0, curr + 1){
            dp[x][curr - x] += a[x];
            a[x+1] += a[x];
            a[x] = 0;
          }
          a[curr+1] = 0;
          FL(x, 0, curr + 1){
            dp[curr-x][x] += b[x];
            b[x+1] += b[x];
            b[x] = 0;
          }
          b[curr+1] = 0;
          curr++;
          FL(x, 0, curr + 1){
            if (x!=curr)
              dp[x][curr-x] = dp[x][curr-x-1];
            if (x!=0)
              dp[x][curr-x] = max(dp[x - 1][curr-x], dp[x][curr-x]);
          }
        } else {
          if (abs(r[i]) > curr)
            continue;
          if (r[i] > 0)
            a[r[i]]++;
          else
            b[abs(r[i])]++;
        }
      }
      FL(x, 0, curr + 1){
        if (x!=0){
          a[x] += a[x-1];
          a[x-1] = 0;
        }
        dp[x][curr - x] += a[x];
      }
      FL(x, 0, curr + 1){
        if (x!=0){
          b[x] += b[x-1];
          b[x-1] = 0;
        }
        dp[curr-x][x] += b[x];
      }
      int mx = 0;
      FL(i, 0, m + 1){
        mx = max(dp[i][m - i], mx);
      }
      cout << mx << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

