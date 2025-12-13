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

    dbg (31 - __builtin_clz(3));
    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int n, q;
      cin >> n >> q;
      vi a(n + 1);

      FL(i, 1, n + 1)
        cin >> a[i];
      

      auto f = [](int x){
        int vl = __builtin_popcount(x);
        if (vl == 1){
          return 0;
        } else if (vl == 2 && (x&1)) {
          return 1;
        }
        return 2;
      };

      vi c(n + 1, 0);
      vi d(n + 1,0), e(n+1,0);
      FL(i, 1, n + 1){
        c[i] = 31 - __builtin_clz(a[i]);
        if (f(a[i]) == 1){
          d[i] = 1;
        } else if (f(a[i]) == 2) {
          e[i] = 1;
        }
      }
      FL(i, 1, n + 1){
        c[i] += c[i-1];
        d[i] += d[i-1];
        e[i] += e[i-1];
      }

      int l, r;
      while (q--){
        cin >> l >> r;

        int cd = c[r] - c[l-1];
        int dd = d[r] - d[l-1];
        int ed = e[r] - e[l-1];
        dbg(l, r, cd, dd, ed);

        int an = cd + ed + (dd / 2);
        cout << an << endl;
      }

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

