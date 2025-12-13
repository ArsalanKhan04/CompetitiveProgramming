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
    // cin >> TCS;
    while(TCS--){
      int n, k;
      cin >> n >> k;
      n++;
      if (n == 1){
        cout << 0 << endl;
        continue;
      }
      vll a(n + 2), b(n+2), c(n+2);
      vb bb(n+2, true), cc(n+2, true);
      FL(i, 1, n + 1)
        cin >> a[i];
      b[1] = a[1] / -2;
      if (abs(a[1]) & 1) bb[1] = false;
      FL(i, 2, n){
        b[i] = (a[i] - b[i-1]) / -2;
        if (abs(a[i]-b[i-1]) & 1) bb[i] = false;
        bb[i] = bb[i] & bb[i-1];
      }
      ll an = 0;
      if (abs(b[n-1]) <= k && abs(b[n-1]) != 0 && bb[n-1]){
        int vl = b[n-1];
        if (abs(vl) <= k) an++;
      }
      c[n] = a[n];
      FFE(i, n-1, 2){
        c[i] = a[i] + 2 * c[i+1];
        if (abs(c[i]) > 1e15) {
          cc[i] = false;
          c[i] = 0;
        }
        cc[i] = cc[i] & cc[i+1];
      }
      ll vl = c[2]*-2;
      if (abs(vl) <= k && cc[2]) an++;
      FL(i, 2, n){
        dbg(vl, c[i+1], b[i-1], cc[i+1], bb[i-1]);
        vl = c[i+1]*-2+b[i-1];
        if (abs(vl) <= k && cc[i+1] && bb[i-1])
          an++;
      }
      cout << an << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

