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
      int n, k;
      cin >> n >> k;
      vi a;
      int y = n;
      while (y) {
        a.pb(y&1);
        y/=2;
      }
      int m = a.size();
      a.pb(0);
      reverse(ALL(a));

      vvi dp(m+1, vi(m+1, -1));
      dp[0][0] = 0;

      vi prf = a;
      FL(i,1,m+1) {
        prf[i] = !prf[i];
        prf[i] += prf[i-1];
      }

      auto f = [&](auto &&slf, int right_index, int cost){
        if (right_index == -1) return 0;
        if (dp[right_index][cost] != -1) return dp[right_index][cost];
        dp[right_index][cost] = slf(slf, right_index-1,cost);
        for (int left_index = 0; left_index < right_index; left_index++){
          int num_zrs = prf[right_index] - prf[left_index];
          int seg_cost = num_zrs + 1;
          int seg_score = right_index - left_index;
          if (seg_cost <= cost){
            dp[right_index][cost] = max(dp[right_index][cost],
                slf(slf, left_index, cost-seg_cost) + seg_score);
          }
        }
        return dp[right_index][cost];
      };

      // memoization

      /*
      for (int right_index = 1; right_index < m + 1; right_index++){
        for (int cost = 0; cost < m + 1; cost++){
          dp[right_index][cost] = dp[right_index-1][cost];
          for (int left_index = 0; left_index < right_index; left_index++){
            // seg is [) (left_index, right_index]
            // We calculate no of 0s in segment using prefix sum
            int num_zrs = prf[right_index] - prf[left_index];
            int seg_cst = num_zrs + 1;
            int seg_score = right_index - left_index;
            if (seg_cst <= cost){
              dp[right_index][cost] = max(dp[right_index][cost],
                  dp[left_index][cost-seg_cst] + seg_score);
            }
          }
        }
      }
      */


      ll an = 0;
      for (int cost_used = 0; cost_used < min(k+1, m+1); cost_used++){
        int remaining_cost = k - cost_used;
        an = max(an,
            f(f, m, cost_used) + (ll) (k - cost_used));
      }
      cout << an << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

