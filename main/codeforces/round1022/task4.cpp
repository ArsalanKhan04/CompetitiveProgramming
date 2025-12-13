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
    auto _clock_start = chrono::high_resolution_clock::now();
#else
    cin.tie(0);
#endif

    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int n, k;
      cin >> n >> k;
      vi a(k + 1);
      vi b(k + 1);
      int nm;
      FL(i, 0, k){
        cout << "? " << i + 1 << endl;
        cout.flush();
        cin >> nm;
        a[nm] = i;
      }
      FL(i, 0, k){
        cout << "? " << n - i << endl;
        cout.flush();
        cin >> nm;
        b[nm] = (n - i - 1) % k;
      }
      int df = -1;
      FL(i, 1, k + 1){
        if (a[i] != b[i]){
          df = b[i];
          break;
        }
      }
      if (n == 2 * k){
        cout << "! " << k << " " << k << endl;
        cout.flush();
        continue;
      }
      if (df == -1){
        cout << "! " << -1 << endl;
        cout.flush();
        continue;
      }

      int lw = 1;
      int hg = (n + k - 1) / k - 1;
      //cerr << "Low: " << lw << "   =High: " << hg << endl;
      while (lw <= hg){
        int md = lw + (hg - lw) / 2;
        cout << "? " << md * k + 1 + df << endl;
        cout.flush();
        cin >> nm;
        if (a[nm] == df){
          lw = md + 1;
        } else {
          hg = md - 1;
        }
      }
      //cerr << "Low: " << lw << " High: " << hg << endl;
      int st = lw * k + 1 + df - k;
      int ans;
      vb d(k + 1, false), e(k + 1, false);
      FL(i, 0, k + 1){
        cout << "? " << st + i << endl;
        cout.flush();
        cin >> nm;
        /*
        cerr << "Number: " << nm << endl;
        cerr << "A[nm]: " << a[nm] << endl;
        cerr << "B[nm]: " << b[nm] << endl;
        cerr << "st + i - 1: " << st + i - 1 << endl;
        */
        if (a[nm] == (st + i - 1) % k && (st + i) <= n - k){
          d[i] = true;
        }
        if (b[nm] == (st + i - 1) % k && st + i > k){
          e[i] = true;
        }
      }
      /*
      cout << "D[i]: ";
      FL(i, 0, k + 1){
        cout << d[i] << " ";
      }
      cout << endl;
      cout << "E[i]: ";
      FL(i, 0, k + 1){
        cout << e[i] << " ";
      }
      cout << endl;
      */
      FL(i, 1, k + 1){
        if (d[i-1] == 0) d[i] = 0;
      }
      for (int i = k - 1; i>=0; i--) if (e[i+1] == 0) e[i] = 0;
      FL(i, 0, k + 1){
        if (d[i] && e[i] && i < k && e[i+1] && !d[i+1]){
          ans = -1;
          break;
        }
        if (e[i] && !d[i]){
          ans = st + i;
          break;
        }
      }
      if (ans == -1){
        cout << "! " << -1 << endl;
        cout.flush();
        continue;
      }
      cout << "! " << ans - 1 << " " << n - ans + 1 << endl;
      cout.flush();
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}
