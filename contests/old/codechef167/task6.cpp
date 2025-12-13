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
    while(testcases--){
      int n;
      cin >> n;
      string s;
      cin >> s;
      s = "%" + s;
      vll ca(n + 1);
      ca[0] = 0;
      FL(i, 1, n + 1){
        if (s[i] == '1'){
          ca[i] += 1;
        } else {
          ca[i] += -1;
        }
        ca[i] += ca[i-1];
      }
      vvll cp(2, vll(n + 1, 0));
      FL(i, 1, n + 1){
        if (s[i] == '1'){
          cp[1][i] += 1;
        } else {
          cp[0][i] += 1;
        }
        cp[0][i] += cp[0][i-1];
        cp[1][i] += cp[1][i-1];
      }
      vvll ccp(2, vll(n + 1, 0));
      FL(i, 1, n + 1){
        ccp[0][i] += cp[0][i];
        ccp[1][i] += cp[1][i];
        ccp[0][i] += ccp[0][i-1];
        ccp[1][i] += ccp[1][i-1];
      }
      map<int, int> mp;
      vll dp(n + 1, 0);
      dp[0] = 0;
      ll pr;
      FL(i, 1, n + 1){
        pr = mp[ca[i]];
        dbg(pr);
        if (pr > 0)
          dp[i] += dp[pr - 1] + ((i - pr + 1) / 2) * (pr - 1);
        else pr = 1;
        dp[i] += (i - pr + 1) * cp[s[i]-'0'][i] - (ccp[s[i]-'0'][i-1] - (pr >= 2 ? ccp[s[i]-'0'][pr-2]: 0));
        mp[ca[i-1]] = i;
      }
      ll ans = 0;
      FL(i, 1, n + 1) {
        cerr << dp[i] << " \n"[i==n];
        ans += dp[i];
      }
      cout << ans << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

