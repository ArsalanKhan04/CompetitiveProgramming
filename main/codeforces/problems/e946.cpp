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
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
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

  int t;
  cin >> t;
  FL(et, 0, t) {
    ll m, x;
    cin >> m >> x;
    vector<pair<ll, ll>> h(m + 1);
    int n1, n2;
    int h1sum = 0;
    FL(i, 1, m + 1) {
      cin >> n1 >> n2;
      h1sum += n2;
      h[i] = mp(n1, n2);
    }

    vector<vector<ll>> dp(m + 1, vector<ll>(h1sum + 1, -1));
    dp[0][0] = 0;
    FL(i, 1, m+1){
      FL(j, 0, h1sum + 1){
        dp[i][j] = dp[i-1][j] >= 0 ? dp[i-1][j] + x : -1;
        if (h[i].S <= j && h[i].F <= dp[i - 1][j-h[i].S]){
          dp[i][j] = max(dp[i - 1][j-h[i].S] - h[i].F + x, dp[i][j]);
        }
      }
    }

    ll mx = 0;
    FF(j, h1sum, 0){
      FF(i, m, 0){
        if (dp[i][j] >= 0){
          mx = j;
          break;
        }
      }
      if (mx > 0)
        break;
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

