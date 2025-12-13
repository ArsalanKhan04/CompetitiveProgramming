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
      int n, q;
      cin >> n >> q;
      vi a(n + 1, 0);
      FL(i, 1, n + 1)
        cin >> a[i];
      vvi prv(31, vi(n + 1));
      FL(i, 0, 31){
        prv[i][0] = 0;
        int prev = 0;
        FL(j, 1, n + 1){
          if (a[j] & (1 << i)){
            prev = j;
          }
          prv[i][j] = prev;
        }
      }
      vi suf(n + 2);
      suf[n + 1] = 0;
      FFE(i, n, 0){
        suf[i] = a[i] ^ suf[i+1];
      }
      int x;
      int ptr;
      while (q--){
        cin >> x;
        int y = x;
        int mn = 0;
        ptr = n;
        int ans = 0;
        FFE(v, 30, 0){
          if ((x & (1 << v)) == 0){
            mn = max(mn, prv[v][ptr]);
          } else {
            ptr = max(mn, prv[v][ptr]);
            if (ptr!=0)
              mn = max(mn, prv[v][ptr-1]);
            x = y ^ suf[ptr+1];
          }
          if (ptr == mn || a[ptr] > x){
            break;
          }
          x = y ^ suf[ptr];
          ptr--;
        }
        cout << n - ptr << " ";
      }
      cout << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}
