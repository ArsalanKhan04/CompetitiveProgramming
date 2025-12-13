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

#define INF ((ll)1e17 + 1) 
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
    dbg(INF);
    while(testcases--){
      int n, m;
      cin >> n >> m;
      vll a(n + 1), b(m + 1);
      FL(i, 0, n){
        cin >> a[i + 1];
      }
      FL(i, 0, m){
        cin >> b[i + 1];
      }
      dbg(b[1]);
      vll empt(n + 1, INF);
      vll empt2(n + 1, 0);
      vll dp(n + 1, INF);
      vll ndp(n + 1, INF);
      vll rem(n + 1, 0);
      dp[0] = 0;
      FL(i, 1, m + 1){
        FL(j, 1, n + 1){
          if (b[i] < a[j]){
            continue;
          }
          if (rem[j-1] >= a[j]){
            ndp[j] = ndp[j-1];
            rem[j] = rem[j-1] - a[j];
          } else {
            ndp[j] = ndp[j-1] + (m - i);
            rem[j] = b[i] - a[j];
          }
          if (ndp[j] >= dp[j-1] + (m - i)){
            ndp[j] = dp[j-1] + (m - i);
            rem[j] = b[i] - a[j];
          }
        }
        FL(j, 1, n + 1){
          dp[j] = min(dp[j], ndp[j]);
        }
        ndp.assign(ALL(empt));
        rem.assign(ALL(empt2));
      }
      if (dp[n] >= INF)
        cout << -1 << endl;
      else
        cout << dp[n] << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

