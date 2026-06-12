#include <bits/stdc++.h>
#include <numeric>
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


    ll Fac[(int) 18];
    Fac[0]=1;
    FL(i,1,18){
      Fac[i] = Fac[i-1]*i;
    }

    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int n;
      cin >> n;
      int lines = ceil(log2(n+1));
      vector<string> inp(lines);
      FL(i,0,lines){
        cin >> inp[i];
      }
      sort(ALL(inp), [n](string fst, string scd){
        int sz1 = 0;
        int sz2 = 0;
        FL(i,0,n){
          sz1+=(fst[i]=='1'); 
          sz2+=(scd[i]=='1'); 
        }
        return sz1 < sz2;
      });
      vvi a(n+1, vi(lines));
      FL(j,0,lines){
        FL(i,1,n+1){
          a[i][j]=(inp[j][i-1]=='1');
        }
      }
      sort(ALL(a));

      bool fl = true;
      vb chk(n+1, false);
      FL(i,0,n+1){
        int vl = 0;
        FL(j,0,lines){
          vl = vl*2 + a[i][j];
        }
        // cout << vl << " ";
        if (vl > n){
          continue;
        }
        chk[vl]=true;
      }
      // cout  << endl;

      // cout << accumulate(ALL(chk), 0) << endl;

      if (accumulate(ALL(chk), 0) < n+1){
        cout << 0 << endl;
        continue;
      }

      vb done(lines, false);

      ll ans = 1;
      n++;
      FL(i,0,lines){
        if (done[i]) continue;
        done[i] = true;
        int cnt = 1;
        FL(j,i+1,lines){
          if (done[j]) continue;
          int md = 1<<(j+1);
          int inv = 1<<j;
          int inc = 1<<i;
          dbg(i, j, md, inv, inc, n%md);
          if (n % md <= inc || (n%md)+inc >= md){
            dbg("cnt inc");
            cnt++;
            done[j] = true;
          }
        }
        dbg(cnt, Fac[cnt]);
        ans *= Fac[cnt];
      }
      cout << ans << endl;





    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

