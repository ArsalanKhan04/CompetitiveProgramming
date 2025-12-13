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
      int n,m;
      cin >> n>>m;
      vi b(n);
      FL(i, 0, n) cin>>b[i];
      vector<vpii> to(n);
      int U, V, W;
      FL(i,0,m){
        cin >> U >> V >> W;
        U--;
        V--;
        to[U].pb({V, W});
      }
      FL(i, 0, n) sort(ALL(to[i]));

      auto dk = [&](int x){
        priority_queue<pair<int, int>> q;
        q.push({0, 0});
        vector<int> ds(n, -1);
        ds[0] = min(b[0], x);
        FL(i, 0, n){
           for (auto [v, w]: to[i]){
              if (w <= ds[i]){
                ds[v] = max(ds[i] + b[v], ds[v]);
                ds[v] = min(ds[v], x);
              }
           }
        }
        return ds[n-1]>-1;
      };

      int lw = 1; int hg = 1e9 + 3;
      while (lw <= hg){
        int md = lw + (hg - lw) / 2;
        if (dk(md)){
          hg = md - 1;
        } else {
          lw = md + 1;
        }
      }
      if (lw == 1e9 + 4){
        cout << -1 << endl;
        continue;
      }
      cout << lw << endl;


    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

