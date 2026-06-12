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
      int n, k; cin >> n >> k;
      string a[4];
      cin >> a[1] >> a[2];
      a[3] = a[1];
      FL(i,0,n) a[3][i] = ('0'+(a[1][i]!=a[2][i]));

      ll vl[4] = {0};
      FL(i,1,4){
        ll zrs, ons; zrs=ons=0;
        FL(j,0,n){
          if (a[i][j]=='1') ons++;
          else zrs++;
        }
        vl[i] = ons * zrs;
      }

      vector<vvll> dp(4, vvll(4, vll(k+1, -1))); 
      // lft, rgt, k

      auto f = [&](auto &&slf, int lft, int rgt, int kvl)->ll{
        if (dp[lft][rgt][kvl]==-1) {
          dp[lft][rgt][kvl]=vl[lft^rgt];
          if (kvl > 1){
            dp[lft][rgt][kvl]+=slf(slf, lft, lft^rgt, kvl-1) 
              + slf(slf, lft^rgt, rgt, kvl-1);
          }
        }
        return dp[lft][rgt][kvl];
      };

      cout << vl[1]+f(f, 1, 2, k) + vl[2] << endl;



    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

