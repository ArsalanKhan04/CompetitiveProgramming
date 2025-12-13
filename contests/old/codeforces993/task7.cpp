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
      int n;
      cin >> n;
      vi a(n + 1);
      vvi b(n + 1, vi());
      FL(i, 1, n + 1){
        cin >> a[i];
        b[a[i]].pb(i);
      }



      vb cycles(n + 1, false);
      vi vis(n + 1, false);
      vb vis2(n + 1, false);
      auto dfs1 = [&](auto &&self, int x)->bool{
        if (vis2[x])
          return false;
        if (vis[x]){
          cycles[x] = true;
          return cycles[x];
        }
        vis[x] = true;
        bool ahd = self(self, a[x]);
        vis[x] = false;
        vis2[x] = true;
        if (ahd){
          if (cycles[x] == true){
            return false;
          }
          cycles[x] = true;
          return true;
        } else {
          return false;
        }
      };
      FL(i, 1, n + 1){
        dfs1(dfs1, i);
        cerr << cycles[i] << " \n"[i==n];
      }


      int mx = 0;
      vi sz(n + 1, -1);
      auto dfs = [&](auto &&self, int x)->int{
        if (cycles[x]) return 0;
        if (sz[x] != -1) return sz[x];
        int f_sz = 0;
        for(int y: b[x]){
          f_sz += self(self, y);
        }
        f_sz += 1;
        sz[x] = f_sz;
        REMAX(mx, f_sz);
        return f_sz;
      };
      FL(i, 1, n + 1){
        dfs(dfs, i);
      }
      cout << mx + 2 << endl;
      



    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

