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

    vi sgs(31, 0);
    FL(i, 2, 31){
      sgs[i] = (i * (i-1))/2;
    }
    vvi dp(31, vi(436, -1));
    dp[0][0] = 0;
    FL(i, 0, 31){
      FL(j, 0, 435){
        if (dp[i][j] != -1){
          FL(x, 1, 31){
            if (i + x < 31 && j + sgs[x] < 436)
              dp[i+x][j+sgs[x]] = x;
          }
        }
      }
    }
    dbg("HERE");

    auto f = [&](int n, int k)->vi{
      vi an;
      k = (n*(n-1))/2 - k;
      if (dp[n][k] == -1) return an;
      int i = n;
      int j = k;
      int mxvl = n;
      while (dp[i][j] != 0){
        int vl = dp[i][j];
        i-=vl;
        j-=sgs[vl];
        int lf = mxvl - vl+1;
        FL(vv, lf, mxvl+1){
          an.push_back(vv);
        }
        mxvl-=vl;
      }
      FFE(vv, mxvl, 1){
        an.push_back(vv);
      }
      return an;
    };

    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int n, k;
      cin >> n >> k;
      vi an = f(n, k);
      if (an.size() == 0) {
        cout << 0 << endl;
        continue;
      }
      for (auto x: an){
        cout << x << " ";
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

