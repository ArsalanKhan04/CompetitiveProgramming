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
#define vi vector<int>
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi a;
    int cnt = 1;
    FL(i, 1, n){
      if (s[i] != s[i-1]){
        a.pb(cnt);
        cnt = 0;
      }
      cnt++;
    }
    a.pb(cnt);
    int x = a.size();
    int ans = -1;
    int sum = 0;
    bool flag = true;
    if (a[x-1] > k)
      flag = false;
    if (a[0] > k){
      ans = a[0] - k;
      if (ans > 4){
        flag = false;
      } else if (ans < 4){
        if ((x & 1) == 0 || ans + a[x-1] != k)
          flag = false;
      } else if (ans == 4){
        if (x&1)
          flag = false;
        if (a[x-1] != k)
          flag = false;
      }
    }
    FL(i, 1, x - 1){
      if (a[i] != k)
        sum+=a[i]%k;
      sum+=a[i];
    }

    if (flag)
      cout << ans << endl;
    else
      cout << -1 << endl;

  }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

