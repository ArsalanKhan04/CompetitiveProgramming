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
      vi a(n + 1);
      FL(i, 1, n + 1)
        cin >> a[i];
      vi c(n + 1), d(n+1);
      FL(i,2,n+1) c[i] = a[i-1] > a[i];
      FL(i,2,n+1) d[i] = a[i-1] < a[i];
      FL(i,2,n+1){
        c[i]+=c[i-1];
        d[i]+=d[i-1];
      }
      if (c[n] == 0){
        cout << 0 << endl;
        continue;
      }
      if (d[n] == 0){
        cout << 1 << endl;
        continue;
      }
      int mn = 1e9;
      FL(i,1,n){
        dbg(i, c[i], d[i]);
        dbg(c[n] - c[i+1], d[n]-d[i+1]);
        if (c[i] == 0 && c[n] - c[i+1] == 0 
            && a[n] <= a[1]){
          mn = min(mn, n-i);
          mn = min(mn, i + 2);
        }
        if (d[i] == 0 && d[n] - d[i+1] == 0 &&
            a[n] >= a[1]){
          mn = min(mn, n-i+1);
          mn = min(mn, i + 1);
        }
      }
      if (mn == 1e9){
        cout << -1 << endl;
      } else {
        cout << mn << endl;
      }
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

