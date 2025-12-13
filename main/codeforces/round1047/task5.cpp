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
      int n, k;
      cin >> n >> k;
      vi a(n + 1);
      FL(i, 1, n + 1)
        cin >> a[i];
      vi c(n + 1);
      FL(i, 1, n + 1)
        c[a[i]]++;
      int mn0 = n;
      FL(i, 0, n + 1){
        if (c[i] == 0) {
          mn0 = i;
          break;
        }
      }
      ll cc = 0;
      FL(i, 0, n + 1){
        if (c[i] > 1 || i > mn0){
          cc+=c[i];
          c[i] = 0;
        }
      }
      c[mn0] = cc;
      k--;
      ll ans = 0;
      if (k == 0){
        FL(i, 0, n + 1){
          ans += i * (ll)c[i];
        }
        cout << ans << endl;
        continue;
      }
      int mn1 = -1;
      bool fl = false;
      FL(i, 0, n + 1){
        if (c[i] != 1){
          mn1 = i;
          if (c[i] == 0){
            fl = true;
          } else {
            fl = false;
          }
          break;
        }
      }
      FL(i, 0, mn1){
        ans += i;
      }
      dbg(mn0, mn1, fl);
      ll cnt = n - mn1;
      if (fl){
        if (k & 1){
          cout << ans + (cnt * mn1) << endl;
        } else {
          cout << ans + (cnt * (mn1+1)) << endl;
        }
      } else {
        if (k & 1){
          cout << ans + (cnt * (mn1+1)) << endl;
        } else {
          cout << ans + (cnt * mn1) << endl;
        }
      }


    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

