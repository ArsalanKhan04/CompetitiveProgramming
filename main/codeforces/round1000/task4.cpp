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
      int n, m;
      cin >> n >> m;
      vll a(n), b(m);
      FL(i, 0, n)
        cin >> a[i];
      FL(i, 0, m){
        cin >> b[i];
      }
      sort(ALL(a)); sort(ALL(b));
      if (n > m){
        swap(n, m);
        swap(a, b);
      }
      int l = 0, r = n - 1;
      vll a_ars(n / 2 + 1);
      while (l < r){
        a_ars[l + 1] = a[r] - a[l];
        l++; r--;
      }
      l = 0, r = m - 1;
      vll b_ars(m / 2 + 1);
      while (l < r){
        b_ars[l + 1] = b[r] - b[l];
        l++; r--;
      }
      vll a_ars_c(n / 2 + 1), b_ars_c(m / 2 + 1);
      FL(i, 1, m / 2 + 1){
        b_ars_c[i] += b_ars_c[i-1] + b_ars[i];
      }
      FL(i, 1, n / 2 + 1){
        a_ars_c[i] += a_ars_c[i-1] + a_ars[i];
      }

      vll ars(max(n, m), 0);
      /*
      int v = (n / 2) * 2;
      int mxr = 0;
      while (true){
        if (n - v > m / 2 || v < 0) break;
        ll curr = 0;
        curr += a_ars_c[v / 2];
        curr += b_ars_c[n - v];
        REMAX(mxr, v / 2 + (n - v));
        REMAX(ars[v / 2 + (n - v)], curr);
        v -= 2;
      }
      */

      for (ll y: a_ars){
        cerr << y << " ";
      }
      cerr << endl;
      for (ll y: b_ars){
        cerr << y << " ";
      }
      cerr << endl;
      int x = 1;
      int y = 1;
      int xr = n;
      int yr = m;
      int c = 1;
      while (true){
        if (xr - (2 * (x - 1)) >= 2 && yr - (2 * (y - 1)) >= 2){
          dbg(1);
          if (a_ars[x] > b_ars[y]){
            REMAX(ars[c], ars[c - 1] + a_ars[x]);
            x++;
            yr--;
          } else {
            REMAX(ars[c], ars[c - 1] + b_ars[y]);
            y++;
            xr--;
          }
        } else if (xr - (2 * (x - 1)) >= 2 && yr - (2 * (y - 1)) >= 1){
          dbg(2);
          REMAX(ars[c], ars[c - 1] + a_ars[x]);
          x++;
          yr--;
        } else if (yr - (2 * (y - 1)) >= 2 && xr - (2 * (x - 1))>= 1){
          dbg(3);
          REMAX(ars[c], ars[c - 1] + b_ars[y]);
          y++;
          xr--;
        } else if (xr - (2 * (x - 1)) >= 3 && y > 1){
          dbg(4);
          y--;
          xr++;
          ars[c] = ars[c-1] - b_ars[y] + a_ars[x];
          x++;
          ars[c] +=  a_ars[x];
          x++;
          yr--;
          yr--;
        } else if (yr - (2 * (y - 1)) >= 3 && x > 1){
          dbg(5);
          x--;
          yr++;
          ars[c] = ars[c-1] - a_ars[x] + b_ars[y];
          y++;
          ars[c] += b_ars[y];
          y++;
          xr--;
          xr--;
        } else {
          break;
        }
        c++;
      }
      cout << c - 1 << endl;
      FL(i, 1, c){
        cout << ars[i] << " ";
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

