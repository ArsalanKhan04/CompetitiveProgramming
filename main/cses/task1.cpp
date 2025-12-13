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
    int n, q;
    cin >> n >> q;
    vi p(n + 1, -1);
    int u, v;
    FL(i, 2, n + 1){
      cin >> v;
      p[i] = v;
    }
    p[1] = -1;
    int nm = log2(n) + 5;
    vvi dp(n + 1, vi(log2(n) + 5, -1));
    FL(i, 1, n + 1){
      dp[i][0] = p[i];
    }
    FL(i, 1, n + 1){
      FL(j, 1,(int)log2(n) + 5){
        if (dp[i][j-1] > 0 && dp[i][j-1] <= n){
          assert(dp[i][j-1] > 0);
          dp[i][j] = dp[dp[i][j-1]][j-1];
        } else {
          dp[i][j] = -1;
        }
      }
    }
    int x, k;
    while (q--){
      cin >> x >> k;
      u = 0;
      int curr = x;
      while (k){
        if (k & 1){
          curr = dp[curr][u];
        }
        u++; k>>=1;
        if (curr == -1) break;
      }
      cout << curr << endl;
    }

#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

