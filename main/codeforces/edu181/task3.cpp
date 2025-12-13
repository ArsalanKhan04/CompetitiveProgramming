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
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#ifdef KRAKAR
#define dbg(...)                                                               \
  cerr << '[' << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):",             \
      dbg_out(__VA_ARGS__)
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
  while (TCS--) {
    ll a, b;
    cin >> a >> b;
    int vals[4] = {2, 3, 5, 7};
    auto f = [&](ll x) -> ll {
      ll ans = 0;
      FL(i, 0, 4) {
        ans += x / vals[i];
        FL(j, i + 1, 4) {
          ans -= (x / (vals[i] * vals[j]));
          FL(k, j + 1, 4) {
            ans += (x / (vals[i] * vals[j] * vals[k]));
            FL(l, k + 1, 4) {
              ans -= (x / (vals[i] * vals[j] * vals[k] * vals[l]));
            }
          }
        }
      }
      return ans;
    };
    cout << (b - a + 1) - (f(b) - f(a - 1)) << endl;
  }
#ifdef KRAKAR
  cerr << "Executed in "
       << chrono::duration_cast<chrono::milliseconds>(
              chrono::high_resolution_clock::now() - _clock_start)
              .count()
       << "ms." << endl;
#endif
  return 0;
}
