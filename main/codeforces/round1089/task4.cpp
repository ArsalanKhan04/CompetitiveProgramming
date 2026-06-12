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
    
    // first 30 primes
    vi prms = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677};


    int pn = 30;

    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int n;
      cin >> n;
      vll a(n+1), bb(n+1);
      FL(i, 1, n+1)
        cin >> a[i];
      FL(i,1,n+1) cin >> bb[i];

      vll b(n+1, 1), c(n+1, 1);
      FL(i,1,n){
        b[i] = gcd(a[i], a[i+1]);
      }
      FL(i,2,n+1) c[i]=gcd(a[i], a[i-1]);

      vll d(n+1, 1);
      FL(i,1,n+1) d[i] = lcm(b[i], c[i]);

      /*
      FL(i,1,n+1) cerr << d[i] << " ";
      cerr << endl;
      */

      vvi dp(n+1, vi(pn, 0));

      FL(i,1,n+1){
        dp[i][0]=dp[i-1][0];
        if (d[i] > bb[i]){ // no change in this case
          d[i] = a[i];
          // if (i==n) dbg(a[i]);
          FL(k,0,pn){
            ll pvl = d[i-1] * prms[k];
            if (gcd(pvl, d[i]) == gcd(d[i], d[i-1])){
              dp[i][0] = max(dp[i][0], dp[i-1][k]);
            }
          }
          continue;
        }
        if (d[i] != a[i]) dp[i][0]++; // increase coz changed
        FL(j,0,pn){ 
          ll nvl = d[i] * prms[j];
          if (nvl > bb[i]) continue;
          FL(k, 0, pn){
            ll pvl = d[i-1] * prms[k];
            // if (i==5) dbg(j, k, nvl, pvl, prms[j]);
            // if (gcd(pvl, d[i]) % prms[j]){
            if (gcd(pvl, nvl) == gcd(d[i], d[i-1])){
              int inc = nvl != a[i];
              // dbg(inc, pvl, d[i], nvl);
              // if (i==5) dbg(inc);
              dp[i][j] = max(dp[i][j], dp[i-1][k] + inc);
            }
          }
        }
      }

        /*
      FL(i,1,n+1) cerr << d[i] << " ";
      cerr << endl;
      cerr << endl;
      FL(j,0,3){
        FL(i,1,n+1) cerr << dp[i][j] << " ";
        cerr << endl;
      }
      */

      int ans = *max_element(ALL(dp[n]));
      cout << ans << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

