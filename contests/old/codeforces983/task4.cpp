
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int
#define MOD % 1000000007
#define FL(i, a, b) for (int i = a; i < b; i++)
#define FE(i, a, b) for (int i = a; i <= b; i++)
#define FF(i, a, b) for (int i = a; i > b; i--)
#define FFE(i, a, b) for (int i = a; i >= b; i--)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
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

#define REMAX(a, b) a = max((a), (b))
#define REMIN(a, b) a = min((a), (b))

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define INF int(1e9) + 9
 
#define endl '\n'
 
#define condprt(x) cout << ((x) ? "YES" : "NO") << endl



int main() {

  ios_base::sync_with_stdio(false);
#ifdef KRAKAR
    auto _clock_start = chrono::high_resolution_clock::now();
#else
    cin.tie(0);
#endif

    int testcases = 1;
    cin >> testcases;
    while(testcases--){
      int n;
      cin >> n;
      vi p(n, 0);
      p[1] = 0;
      int mx = 3;
      int r;
      while (mx < n - 1){
        cout << "? " << 1 << " " << mx << endl;
        cout.flush();
        cin >> r;
        if (r == -1)
          return 0;
        if (!r)
          break;
        mx++;
      }
      p[mx] = 1;
      FL(i, 2, mx){
        p[i] = 0;
      }
      int bg = 2;
      int curr = mx + 1;
      vi chn(n, 0);
      FL(i, 0, n){
        chn[i] = i;
      }
      vi sz(n, 0);
      int x = 0;
      int c_mx = 0;
      while (curr < n){
        cout << "? " << curr << " " << bg << endl; 
        cout.flush();
        cin >> r;
        if (r == -1)
          return 0;
        if (!r){
          p[curr] = chn[bg];
          chn[bg] = curr;
          sz[bg]++;
          c_mx = max(c_mx, sz[bg]);
          curr++;
          continue;
        }
        bg++;
        while (true){
          if (bg == mx) {
            bg = 2;
            x = c_mx;
          }
          if (sz[bg] == x)
            break;
          bg++;
        }
      }
      while (curr < n){
        p[curr] = chn[bg]; 
        chn[bg] = curr;
        curr++;
      }
      cout << "! ";
      FL(i, 1, n){
        cout << p[i] << " \n"[i==n-1];
      }
      cout.flush();

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

