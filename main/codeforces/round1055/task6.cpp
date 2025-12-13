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
      int n, z;
      cin >> n >> z;
      vi a(n + 1);
      FL(i, 1, n + 1)
        cin >> a[i];

      set<int> st;
      FL(i, 1, n + 1){
        auto itr = upper_bound(ALL(a), a[i] + z);
        itr--;
        int m = itr - a.begin();
        if (m != i){
          st.insert(i);
        }
      }

      // bin search to find value of k
      int q; cin >> q;
      while (q--){
        int l, r; cin >> l >> r;
        int lw = 0, hg = (n+100)/z;
        while (lw <= hg){
          int md = lw + (hg - lw) / 2;
          int vl = md * z + a[lw];
          auto itr = lower_bound(ALL(a), vl);
          int df = itr - a.begin();
          if (df < r){
            lw = md + 1;
          } else {
            hg = md - 1;
          }
        }
        ll ans = 0;
        int c_l = l;
        if (lw < sqrt(n)){
          while (c_l < r - 1){
            int cv = a[c_l] + z;
            auto itr = upper_bound(ALL(a), cv);
            itr--;
            int pnt = itr - a.begin();
            if (pnt > r) break;
            if (pnt > c_l + 1){
              ans += pnt - c_l - 1;
            }
            c_l = pnt;
          }
        } else {
          while (true){
            auto itr = st.lower_bound(c_l);
            if (itr == st.end()) break;
            c_l = *itr;
            if (c_l >= r) break;
            int cv = a[c_l] + z;
            auto it = upper_bound(ALL(a), cv);
            it--;
            int pnt = it - a.begin();
            if (pnt > r) break;
            if (pnt > c_l + 1){
              ans += pnt - c_l - 1;
            }
            c_l = pnt;
          }
        }
        cout << ans << endl;


      }
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

