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

class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
      int n = grid.size();
      int m = grid[0].size();
      vector<vvll> dp(n, vvll(m, vll(16, 0)));      
      FL(i, 0, n){
        FL(j, 0, m){
          if (i == 0 && j == 0) {
            dp[i][j][grid[i][j]]++;
            continue;
          }
          FL(x, 0, 16){
            if (i != 0){
              dp[i][j][x ^ grid[i][j]] += dp[i-1][j][x];
              dp[i][j][x^grid[i][j]] = dp[i][j][x ^ grid[i][j]] MOD;
            }
            if (j != 0){
              dp[i][j][x ^ grid[i][j]] += dp[i][j-1][x];
              dp[i][j][x^grid[i][j]] = dp[i][j][x ^ grid[i][j]] MOD;
            }
          }
        }
      }
      return dp[n-1][m-1][k];
    }
};
