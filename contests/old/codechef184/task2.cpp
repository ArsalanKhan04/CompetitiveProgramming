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

    vll a(2e5 + 1);
    vll b(2e5 + 1);
    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int n;
      cin >> n;
      ll invs = 0;
      int cmx = 1;
      ll sz = 1;
      a[0] = 1;
      b[0] = 1;
      vll ans(n);
      FL(i, 0, n){
        int x; cin >> x;
        if (x == 1){
          invs += sz;
          b[cmx] = b[cmx-1] + 1;
          a[cmx++] = 1;
          sz++;
        } else {
          invs *= 2;
          FL(j, 1, cmx){
            invs += a[j] * b[j-1];
            dbg(j, a[j], b[j-1]);
          }
          FL(j, 0, cmx){
            a[j] *= 2;
            if (j != 0)
              b[j] = a[j] + b[j-1];
            else b[j] = a[j];
          }
          sz *= 2;
        }
        ans[i] = invs;
      }
      FL(i, 0, n) cout << ans[i] << " \n"[i==n-1];
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

