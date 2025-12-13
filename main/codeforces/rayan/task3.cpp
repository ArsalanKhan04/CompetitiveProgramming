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
    ifstream fileIn("input.txt"); 
    cin.rdbuf(fileIn.rdbuf()); 
    ofstream fileOut("output.txt"); 
    cout.rdbuf(fileOut.rdbuf()); 
    auto _clock_start = chrono::high_resolution_clock::now();
#else
    cin.tie(0);
#endif

    int testcases = 1;
    cin >> testcases;
    while(testcases--){
      int n, m;
      cin >> n >> m;
      vector<vector<char>> mz(n, vector<char>(m));
      vvi vis(n, vi(m, false));
      vvi st(n, vi(m, false));

      string s;
      FL(i, 0, n){
        cin >> s;
        FL(j, 0, m){
          mz[i][j] = s[j];
        }
      }
      auto dfs = [&](auto &&self, int x, int y)->bool{
        dbg(x, y);
        if (vis[x][y] == 2){
          return st[x][y];
        }
        if (vis[x][y] == 1){
          vis[x][y] = 2;
          st[x][y] = true;
          return st[x][y];
        }
        bool final = false;
        vis[x][y] = 1;
        if (x==0 && y==2){
          dbg("m");
        }
        if (y != 0 && (mz[x][y] == 'L' || mz[x][y] == '?')){
          final = final || self(self, x, y - 1);
        } 
        if (x==0 && y==2){
          dbg(final);
        }
        if (x==0 && y==2){
          dbg("m");
        }
        if (x != 0 && (mz[x][y] == 'U' || mz[x][y] == '?')){
          final = final || self(self, x-1, y);
        }
        if (x==0 && y==2){
          dbg(final);
        }
        if (x==0 && y==2){
          dbg("m");
        }
        if (y != m-1 && (mz[x][y] == 'R' || mz[x][y] == '?')){
          final = final || self(self, x, y + 1);
        } 
        if (x==0 && y==2){
          dbg(final);
        }
        if (x==0 && y==2){
          dbg("m");
        }
        if (x != n-1 && (mz[x][y] == 'D' || mz[x][y] == '?')){
          final = final || self(self, x+1, y);
        }
        if (x==0 && y==2){
          dbg(final);
        }
        st[x][y] = final;
        vis[x][y] = 2;
        return st[x][y];
      };
      ll ans = 0;
      FL(i, 0, n){
        FL(j, 0, m){
          dfs(dfs, i, j);
          ans+=st[i][j];
          //cerr << st[i][j] << " ";
        }
        //cerr << endl;
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

