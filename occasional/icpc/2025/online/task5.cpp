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

const int MOD = 998244353;

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
    ll n, m;
    cin >> n >> m;
    
    vll a(n + 1);
    FE(i, 1, n) cin >> a[i];

    vll id(n + 1);
    FE(i, 1, n) id[i] = i;

    sort(id.begin() + 1, id.end(), [&](ll aa, ll bb) {
      return a[aa] < a[bb];
    });

    sort(a.begin() + 1, a.end());

    vll p(n + 1);
    FE(i, 1, n) p[id[i]] = i;

    if (n == 2 && a[1] + 1 == a[2]) {
      cout << -1 << endl;
      continue;
    }

    vll ans(n + 1);
    vll b(n + 1);
    ll x;

    if (n % 2 == 1) {
      x = a[(n + 1) / 2];
      ans[(n + 1) / 2] = m;
    } else {
      x = a[n / 2] + 1;
    }

    FE(i, 1, n) b[i] = abs(a[i] - x);
    FE(i, 1, n / 2) {
      ans[i] = b[n - i + 1];
      ans[n - i + 1] = b[i];
    }

    if (n % 2 == 0 && a[n / 2] + 1 == a[n / 2 + 1]) {
      ll mid = n / 2;
      if (a[n / 2] * 2 <= m) {
        x = a[mid];
        FE(i, 1, n) b[i] = abs(a[i] - x);
        ans[mid] = m;
        FL(i, 2, mid) {
          ans[i] = b[n - i + 1];
          ans[n - i + 1] = b[i];
        }
        ans[1] = b[n] + 2;
        ans[mid + 1] = 2 * b[1];
        ans[n] = b[1];
      } else {
        x = a[mid + 1];
        FE(i, 1, n) b[i] = abs(a[i] - x);
        ans[mid + 1] = m;
        FL(i, 2, mid) {
          ans[i] = b[n - i + 1];
          ans[n - i + 1] = b[i];
        }
        ans[1] = b[n];
        ans[mid] = 2 * b[n];
        ans[n] = b[1] + 2;
      }
    }
    FE(i, 1, n) cout << ans[p[i]] << " ";
    cout << endl;
  }

#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}
