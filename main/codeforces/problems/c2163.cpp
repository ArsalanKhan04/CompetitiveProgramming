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
      int n;
      cin >> n;
      vvi a(3, vi(n));
      FL(i, 0, n){
        cin >> a[0][i];
        cin >> a[1][i];
      }
      // num -> index
      vector<vpii> b(2*n+1); // num -> vector of location/ (row, col)
      FL(i,0,n){
        b[a[0][i]].pb({0, i});
        b[a[1][i]].pb({1, i});
      }
      set<int> st[2];
      FL(i,0,n){
        st[0].insert(i); // upper row indices
        st[1].insert(i); // lower row indices
        st[0].insert(n);
        st[1].insert(-1);
      }

      ll ans = 0;
      int l = 1;
      int r = 1;
      while (l <= 2*n){
        int sz0 = *st[0].begin();
        int sz1 = n - 1 - *st[1].rbegin();
        if (sz0+sz1<=n){
          if (r > 2*n) break; // can I even increment r? is that possible?
                              // If not, just break the loop
          for (auto [k, v]: b[r]){ // increment r, add values of current r
                                   // then increment
            st[k].erase(v);
          }
          r++;
          continue;
        }
        // being here means that sz0+sz1>n
        dbg(l, r);
        ans += 2*n-r+2;
        for (auto [k, v]: b[l]){
          st[k].insert(v);
        }
        l++;
      }
      cout << ans << endl;


    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

