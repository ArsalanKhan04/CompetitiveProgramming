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
#define vi vector<ll>
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
#define INF 200000

string nk = "narek";

bool pres(char c){
  FL(i, 0, 5)
    if (nk[i] == c)
      return true;
  return false;
}


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
    int n, m;
    cin >> n >> m;
    ll maxscore = 0;
    string s;
    vi dp(5, -1 * INF);
    dp[0] = 0;

    while(n--){
      vi ndp(ALL(dp));
      cin >> s;
      dbg(s);
      FL(i, 0, 5){
        int cnt = i;
        int score = 0;
        FL(j, 0, m){
          if (!pres(s[j]))
            continue;
          if (s[j] == nk[cnt]){
            cnt = (cnt + 1) % 5;
            score++;
          } else {
            score--;
          }
        }
        if (dp[i] + score > dp[cnt]){
          ndp[cnt] = max(dp[i] + score, ndp[cnt]);
        }
      }
      dp = ndp;
    }

    FL(i, 0, 5){
      maxscore = max(maxscore, dp[i] - (2 * i));
    }
    cout << maxscore << endl;



  }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

