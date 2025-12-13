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


constexpr int mxv = 1e6 + 1;

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

    vb prims(mxv, true);
    for (int i = 2; i < mxv; i++){
      if (prims[i]){
        for (int j = 2 * i; j < mxv; j+=i){
          prims[j] = false;
        }
      }
    }
    vi ps;
    FL(i, 2, mxv) if (prims[i]) ps.pb(i);

    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int x, y, k;
      cin >> x >> y >> k;
      int xsz = lower_bound(ALL(ps), x) - ps.begin() + 1;
      int ysz = lower_bound(ALL(ps), y) - ps.begin() + 1;
      dbg(xsz, ysz);
      vi a(xsz, 0);
      vi b(ysz, 0);
      FL(i, 0, xsz){
        while (!(x % ps[i])){
          x/=ps[i];
          a[i]++;
        }
        if (x == 1) break;
      }
      FL(i, 0, ysz){
        while (!(y % ps[i])){
          y/=ps[i];
          b[i]++;
        }
        if (y == 1) break;
      }
      int oprs = 0;
      bool flag = true;
      FL(i, 0, min(xsz, ysz)){
        int df = abs(a[i] - b[i]);
        if (df != 0 && ps[i] > k){
          flag = false;
          break;
        }
        oprs += df;
      }
      if (xsz < ysz) {
        swap(xsz, ysz);
        swap(a, b);
      }
      FL(i, min(xsz, ysz), xsz){
        if (a[i] && ps[i] > k){
          flag = false;
          break;
        }
        oprs += a[i];
      }
      if (flag){
        cout << oprs << endl;
      } else {
        cout << -1 << endl;
      }
      dbg(ps.size());
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

