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
#define vvvi vector<vvi>
#define vvvll vector<vvll>

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


const int md = 1e9 + 7;


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

    string s; cin >> s;
    int d; cin >> d;
    int n; n=s.size();
    s = "%" + s;
    vvvll dp(n + 1, vvll(d, vll(2,0)));
    dp[0][0][1] = 1;
    FL(i, 1, n + 1){
      FL(j, 0, d){
        FL(x, 0, 10){
          dp[i][(x+j)%d][0] += dp[i-1][j][0];
          dp[i][(x+j)%d][0] %= md;
          if (x < s[i]-'0')
            dp[i][(x+j)%d][0] += dp[i-1][j][1];
          dp[i][(x+j)%d][0] %= md;
        }
        dp[i][(j+s[i]-'0')%d][1] += dp[i-1][j][1];
        dp[i][(j+s[i]-'0')%d][1] %= md;
      }
    }
    cout << (dp[n][0][0] + dp[n][0][1] + md - 1) % md << endl;
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

