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

    
    vvll sl(62, vll(62, -1));


    sl[0][0] = 0;
    FL(i, 1, 62){
      vvll sl2(62, vll(62, -1));
      FL(j, 0, 62){
        FL(k, 0, 62 - i){
          if (sl[j][k + i] == -1 && sl[j][k] != -1){
            sl2[j][k + i] = sl[j][k] + ((ll) 1 << i);
          } else if (sl[j][k] != -1){
            sl2[j][k + i] = min(sl[j][k] + ((ll) 1 << i), sl[j][k + i]);
          }
          if (sl[k + i][j] == -1 && sl[j][k] != -1){
            sl2[k+i][j] = sl[k][j] + ((ll) 1 << i);
          } else if (sl[j][k] != -1){
            sl2[k+i][j] = min(sl[k][j] + ((ll) 1 << i), sl[k+i][j]);
          }
        }
      }
      FL(j, 0, 62){
        FL(k, 0, 62){
          if (sl2[j][k] != -1)
            sl[j][k] = sl2[j][k];
        }
      }
    }
    for (int i = 61; i >= 1; i--){
      for (int j = 61; j >= 1; j--){
        if (sl[i][j] != -1 && sl[i-1][j-1] == -1){
          sl[i-1][j-1] = sl[i][j];
        } else if (sl[i][j] != -1){
          sl[i-1][j-1] = min(sl[i][j], sl[i-1][j-1]);
        }
      }
    }
    vvll sl2(62, vll(62, LONG_LONG_MAX));
    FL(i, 0, 62){
      FL(j, 0, 62){
        sl2[i][j] = sl[i][j];
      }
    }
    FL(i, 0, 62){
      for (int j = 60; j >= 0; j--){
        sl2[i][j] = min(sl2[i][j], sl2[i][j+1]);
      }
    }
    FL(i, 0, 62){
      for (int j = 60; j >= 0; j--){
        sl2[j][i] = min(sl2[j][i], sl2[j + 1][i]);
      }
    }
    
    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      ll x, y;
      cin >> x >> y;
      vll a, b;
      while (x > 0){
        a.pb(x & 1);
        x >>= 1;
      }
      while (y > 0){
        b.pb(y & 1);
        y >>= 1;
      }
      reverse(ALL(a));
      reverse(ALL(b));
      int c = 0;
      while (c < a.size() && c < b.size()){
        if (a[c] != b[c]){
          break;
        }
        c++;
      }
      int da, db;
      da = a.size() - c;
      db = b.size() - c;
      dbg(da, db);
      ll ans = min(sl[da][db], sl2[a.size()][b.size()]);
      cout << ans << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

