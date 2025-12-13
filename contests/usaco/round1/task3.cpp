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
      int n;
      cin >> n;
      vi a(n + 1), b(n + 1);
      FL(i, 1, n + 1)
        cin >> a[i];
      FL(i, 1, n + 1)
        cin >> b[i];
      vi c(n + 1, 0);
      FL(i, 1, n + 1){
        c[i] = a[i] == b[i];
        c[i] += c[i-1];
      }
      vvi d(2 * n + 3, vi(n/2 + 1));

      auto fll = [&](int cr, int l, int r){
        int st = (l != r);
        while (l > 0 && r <= n){
          if (st == 0){
            d[cr][st] = (a[l] == b[r]);
          } else {
            d[cr][st] = (a[l] == b[r]) + (a[r] == b[l]);
            d[cr][st] += d[cr][st-1];
          }
          l--; r++; st++;
        }
      };
      FL(i, 2, 2 * n + 1){
        fll(i, i/2, (i + 1)/ 2);
      }


      vi ans(n + 1, 0);
      int crt;
      int m1, m2, sz;
      FL(i, 1, n + 1){
        FL(j, i, n + 1){
          crt = c[i-1] + (c[n] - c[j]);
          sz = (j - i + 1);
          m1 = i + (sz - 1) / 2; m2 = i + sz / 2;
          crt += d[m1 + m2][sz/2];
          ans[crt]++;
        }
      }
      FL(i, 0, n + 1){
        cout << ans[i] << endl;
      }




    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

