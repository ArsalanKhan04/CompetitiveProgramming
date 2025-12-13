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
      int n, m;
      cin >> n >> m;
      vi a(n);
      FL(i, 0, n)
        cin >> a[i];

      vpii pr(m);
      vvi res(n);
      FL(i,0,m) {
        cin >> pr[i].F >> pr[i].S;
        pr[i].F--;
        pr[i].S--;
      }
      // at each number decrease it as much as possible -> as long 
      vvi b(n, vi(n)); // b[i] is the vector diff of each array - curr
      FL(i,0,n){
        FL(j, 0, n){
          b[i][j] = a[j] - a[i];
        }
      }
      int mnans = 0;
      int sl = 0;
      FL(i, 0, n){
        vi df(n+1, 0);
        FL(j, 0, m){
          auto p = pr[j];
          if (p.F <= i && p.S >= i){
            res[i].push_back(j);
            df[p.F]++;
            df[p.S+1]--;
          }
        }
        FL(j, 1, n+1){
          df[j] += df[j-1];
        }
        int sbvl = df[i];
        FL(j, 0, n){
          df[j] -= sbvl;
        }
        FL(j, 0, n){
          int vv = b[i][j] - df[j];
          if (vv > mnans){
            mnans = vv;
            sl = i;
          }
        }
      }
      cout << mnans << endl;
      cout << res[sl].size() << endl;
      for (auto r: res[sl]){
        cout << r+1 << " ";
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

