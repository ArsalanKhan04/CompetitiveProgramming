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
      int n, q;
      cin >> n >> q;
      vi a(q);
      vb b(q, false);
      vector<set<int>> vs(n + 1);
      FL(i, 0, q){
        int x; char y;
        cin >> x >> y;
        a[i] = x;
        b[i] = y=='+';
        vs[x].insert(i);
      }

      vi s(n + 1);
      vvi sol(n + 1, vi(n + 1, 0));
      ll sm = 0;
      FL(i, 1, n + 1){
        vi h(2, 1);
        for (int ind: vs[i]){
          if (b[ind]){
            h[1]++;
          } else {
            h[0]++;
          }
        }
        s[i] = h[1];
        sm += s[i];
      }
      FL(i, 1, n + 1){
        FL(j, 1, n + 1){
          if (i == j) continue;
          vi l(2, 1);
          vi h(2, 2);
          for (int ind = 0; ind < q; ind++){
            if (a[ind] == j){
              if (b[ind]){
                h[1]++;
              } else {
                h[0]++;
              }
            } else if (a[ind] == i){
              if (b[ind]){
                l[1]++;
                if (h[0] == l[1]){
                  h[0]++;
                  h[1]++;
                }
              } else {
                l[0]++;
              }
            }
          }
          sol[i][j] = h[1];
        }
      }
      FL(i, 1, n + 1){
        FL(j, 1, n + 1){
          if (i == j) continue;
          sol[i][j] = s[i] + s[j] - sol[i][j];
        }
      }

      // dbg(sol[2][3]);
      int bmx = (1 << n);
      vvi dp(bmx, vi(n + 1, 0));
      FL(i, 0, bmx){
        FL(j, 1, n + 1){
          int cr = (1 << (j - 1));
          if (!(i & cr)) continue;
          int p = 1; int x = i;
          while (x){
            if (x & 1 && p!=j){
              int prv =i ^ (1 << (j - 1));
              dp[i][j] = max(dp[i][j], dp[prv][p] + sol[p][j]);
            }
            x >>= 1;
            p++;
          }
        }
      }

      cout << sm - *max_element(ALL(dp[bmx-1])) << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

