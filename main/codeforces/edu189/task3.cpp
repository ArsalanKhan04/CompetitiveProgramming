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
      vvi a(n+1, vi(2));
      FL(j,0,2){
        string s; cin >> s;
        s="$"+s;
        FL(i, 1, n+1){
          a[i][j]=(s[i]=='R');
        }
      }
      vll dp(n+1, 1e9);
      dp[0]=0;
      FL(i,1,n+1){
        if (i >= 2){
          int ad=1e9;
          FL(msk1,0,4){
            int cr=0;
            int bt0=msk1 & 1; int bt1=msk1>>1;
            if (bt0!=a[i][0]) cr++; if (bt0!=a[i-1][0]) cr++;
            if (bt1!=a[i][1]) cr++; if (bt1!=a[i-1][1]) cr++;
            ad=min(ad,cr);
          }
          dp[i]=dp[i-2]+ad;
        }
        ll sec=dp[i-1];
        if (a[i][0]!=a[i][1]){
          sec+=1;
        }
        dp[i]=min(dp[i],sec);
      }
      cout << dp[n] << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

