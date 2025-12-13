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
    //cin >> TCS;
    while(TCS--){
      int n,m;
      cin >> n >> m;
      vvi a(n + 1, vi(m + 1));
      string s;
      FL(i, 1, n + 1){
        cin >> s;
        s = "$" + s;
        FL(j, 1, m + 1){
          a[i][j] = s[j] == 'X';
        }
      }
      int cnt = 0;
      bool prv = false;
      int mnvl = min(n, m);
      dbg(n,m);
      FL(i, 1, n + 1){
        if (prv){
          mnvl = min(cnt, mnvl);
          cnt = 0;
          prv = false;
        }
        cnt = 0;
        prv = false;
        FL(j, 1, m + 1){
          if (a[i][j] == 1){
            cnt++;
            prv = true;
          } else if (prv){
            mnvl = min(cnt, mnvl);
            cnt = 0;
            prv = false;
          }
        }
      }
      FL(j, 1, m + 1){
        if (prv){
          mnvl = min(cnt, mnvl);
          cnt = 0;
          prv = false;
        }
        cnt = 0;
        prv = false;
        FL(i, 1, n + 1){
          if (a[i][j] == 1){
            cnt++;
            prv = true;
          } else if (prv){
            mnvl = min(cnt, mnvl);
            cnt = 0;
            prv = false;
          }
        }
      }
      if (prv){
        mnvl = min(cnt, mnvl);
        cnt = 0;
        prv = false;
      }
      if (!(mnvl & 1)){
        mnvl--;
      }


      vvi c = a;
      FL(i, 1, n + 1){
        FL(j, 1, m + 1){
          c[i][j] += c[i][j-1];
        }
      }
      FL(j, 1, m + 1){
        FL(i, 1, n + 1){
          c[i][j] += c[i - 1][j];
        }
      }

      auto f = [&](int u, int v, int k){
        dbg(u, v, k);
        int u2 = u - k;
        int v2 = v - k;
        ll sm = 0;
        sm += c[u][v];
        sm += c[u2][v2];
        sm -= c[u][v2];
        sm -= c[u2][v];
        return sm == k * k;
      };


      int df = (mnvl - 1) / 2;
      cout << df << endl;
      vector<string> ans(n + 1, "");
      vector<array<int, 2>> mvs = {{df, df}, {df, -df}, {-df, -df}, {-df, df}};
      FL(i, 1, n + 1){
        FL(j, 1, m + 1){
          dbg(i, j);
          bool fl = true;
          for (auto mv: mvs){
            if (i + mv[0] <= n && i + mv[0] >= 1 &&
                j + mv[1] <= m && j + mv[1] >= 1){
            } else {
              fl = false;
            }
          }
          if (fl && f(i + df, j + df, mnvl)){
            ans[i] += 'X';
          } else {
            ans[i] += '.';
          }
        }
      }
      dbg("OUT");
      FL(i, 1, n + 1){
        cout << ans[i] << endl;
      }
      dbg(mnvl);
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

