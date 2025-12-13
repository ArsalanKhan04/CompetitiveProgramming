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
      int n,m;cin>>n>>m;
      vvi a(n, vi(m));
      FL(i,0,n){
        FL(j,0,m){
          cin>>a[i][j];
        }
      }
      int mx = 0;
      FL(i, 0, n){
        FL(j,0,m) mx = max(mx, a[i][j]);
      }
      vi rw(n);
      vi cl(m);
      pii ai = {-1, -1}, bi = {-1, -1};
      FL(i,0,n){
        FL(j,0,m){
          if (a[i][j] == mx){
            if (ai.F == -1) ai.F = i, ai.S = j;
            if (i != ai.F && j != ai.S) bi = {i, j};
          }
        }
      }
      if (bi.F == -1) bi = ai;

      int xi = ai.F; int xj = bi.S;
      dbg(xi, xj);
      FL(i, 0, n){
        a[i][xj]--;
      }
      FL(j, 0, m){
        a[xi][j]--;
      }
      a[xi][xj]++;
      mx = 0;
      FL(i, 0, n){
        FL(j, 0, m){
          if (a[i][j] > mx) mx = a[i][j];
        }
      }
      FL(i, 0, n){
        a[i][xj]++;
      }
      FL(j, 0, m){
        a[xi][j]++;
      }
      a[xi][xj]--;

      xi = bi.F; xj = ai.S;
      dbg(xi, xj);
      FL(i, 0, n){
        a[i][xj]--;
      }
      FL(j, 0, m){
        a[xi][j]--;
      }
      a[xi][xj]++;
      int mx2 = 0;
      FL(i, 0, n){
        FL(j, 0, m){
          if (a[i][j] > mx2) mx2 = a[i][j];
        }
      }
      FL(i, 0, n){
        a[i][xj]++;
      }
      FL(j, 0, m){
        a[xi][j]++;
      }
      a[xi][xj]--;


      cout << min(mx, mx2) << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

