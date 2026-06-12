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

struct pt{
  int ind;
  ll x, y;
  ll cst;
};


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
      vector<pt> pts(n);
      FL(i,0,n) cin >> pts[i].x;
      FL(i,0,n) cin >> pts[i].y;
      FL(i,0,n) {
        pts[i].ind = i;
        cin >> pts[i].cst;
      }

      const int mx = 1<<4;
      ll dp[mx] = {0};
      FL(i,1,mx)dp[i]=(ll)-1e18;
      ll ndp[mx] = {0};

      int xts[] = {-1, 0, 1, 0};
      int yts[] = {0, -1, 0, 1};

      FL(i,0,n){
        dbg(i);
        FL(j,0,mx) ndp[j]=(ll)-1e18;
        FL(msk,0,mx){
          for (int pr_msk=msk;; pr_msk=(pr_msk-1)&msk){
            if (msk == pr_msk){
              ndp[msk]=max(dp[msk] + pts[i].cst, ndp[msk]);
            } else {
              int dmsk = msk ^ pr_msk;
              ll nvl = dp[pr_msk];
              FL(ind,0,4){
                if ((1<<ind) & dmsk){
                  nvl += 2*xts[ind]*pts[i].x;
                  nvl += 2*yts[ind]*pts[i].y;
                }
              }
              ndp[msk]=max(ndp[msk],nvl);
            }
            if (pr_msk==0) break;
          }
        }
        FL(j,0,mx) dp[j]=ndp[j];
        dbg(dp[15]);
      }
      cout << dp[15] << endl;

      
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

