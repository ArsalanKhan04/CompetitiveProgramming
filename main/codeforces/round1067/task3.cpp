
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
      ll n, k;
      cin >> n >> k;
      vll a(n + 1);
      vll b(n + 1);
      FL(i, 1, n + 1)
        cin >> a[i];
      FL(i, 1, n+1) cin >> b[i];
      if (k & 1){
        vll prv(n + 1, 0);
        vll nxt(n + 2, 0);
        ll cr = 0;
        FL(i,1,n+1){
          cr += a[i];
          cr = max(cr, 0LL);
          prv[i] = cr;
        }
        cr = 0;
        for (int i = n; i>0; i--){
          cr += a[i];
          cr = max(cr, 0LL);
          nxt[i] = cr;
        }
        ll mx = -1e9-3;
        FL(i,1,n+1){
          mx = max(mx, a[i]+b[i]+prv[i-1]+nxt[i+1]);
        }
        cout << mx << endl;

      } else {
        ll mx = *max_element(a.begin()+1, a.end());
        ll cr = 0;
        FL(i,1,n+1){
          cr += a[i];
          mx = max(cr, mx);
          cr = max(cr, 0LL);
        }
        cout << mx << endl;
      }

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

