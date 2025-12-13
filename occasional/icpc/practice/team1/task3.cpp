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


constexpr int inf = 1e9;

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
      vi a(n + 1);
      FL(i, 1, n + 1)
        cin >> a[i];
      vll c(n + 1, 0);
      FL(i, 1, n + 1){
        c[i] += a[i] + c[i-1];
      }
      vi d(n + 1, 0);
      FL(i, 2, n + 1){
        if (a[i] != a[i-1]){
          d[i] = 1;
        }
      }
      FL(i, 1, n + 1){
        d[i] += d[i-1];
      }
      
      auto f = [&](int l, int r, ll sz)->bool{
        if (c[r] - c[l-1] <= sz) return false;
        if (d[r] - d[l] == 0) return false;
        return true;
      };
      auto fr = [&](int l, int r, ll sz)->int{
        if (f(l, r, sz) == false) return -1;
        int lo = l;
        int hi = r;
        int md;
        while (lo <= hi){
          md = lo + (hi - lo) / 2;
          if (f(l, md, sz)){
            hi = md - 1;
          } else {
            lo = md + 1;
          }
        }
        return lo - l + 1;
      };
      auto fl = [&](int l, int r, ll sz)->int{
        if (f(l, r, sz) == false) return -1;
        int lo = l;
        int hi = r;
        int md;
        while (lo <= hi){
          md = lo + (hi - lo) / 2;
          if (f(md, r, sz)){
            lo = md + 1;
          } else {
            hi = md - 1;
          }
        }
        return r - hi + 1;
      };

      vi ans(n + 1, inf);
      FL(i, 1, n + 1){
        if (i > 1){
          if (a[i - 1] > a[i]) ans[i] = 1;
        }
        if (i > 2){
          int vl = fl(1, i - 1, a[i]);
          if (vl != -1){
            ans[i] = min(ans[i], vl);
          }
        }
        if (i < n){
          if (a[i] < a[i + 1]) ans[i] = 1;
        }
        if (i < n - 1){
          int vr = fr(i + 1, n, a[i]);
          if (vr != -1){
            ans[i] = min(ans[i], vr);
          }
        }
      }
      FL(i, 1, n + 1){
        cout << (ans[i] == inf ? -1 : ans[i]) << " \n"[i==n];
      }



    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

