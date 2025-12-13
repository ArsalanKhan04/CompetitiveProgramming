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
      vvi a(n + 1, vi());
      int x1, y1;
      FL(i, 1, n){
        cin >> x1 >> y1;
        a[x1].pb(y1);
        a[y1].pb(x1);
      }
      

      int lf1, lf2;
      int mxhgt = 0;
      auto dfs1 = [&](auto &&self, int u, int p, int hgt, int &mxhgtnd) -> void{
          if (hgt > mxhgt){
            mxhgt = hgt;
            mxhgtnd = u;
          }
          for (auto x : a[u]){
            if (x == p) continue;
            self(self, x, u, hgt + 1, mxhgtnd);
          }
      };
      dfs1(dfs1, 1, -1, 0, lf1);
      mxhgt = 0;
      dfs1(dfs1, lf1, -1, 0, lf2);

      vi pth;
      auto dfs2 = [&](auto &&self, int u, int dest, int p)->bool{
        if (u == dest){
          pth.pb(u);
          return true;
        }
        for (auto x: a[u]){
          if (x == p) continue;
          if (self(self, x, dest, u)){
            pth.pb(u);
            return true;
          }
        }
        return false;
      };
      dfs2(dfs2, lf1, lf2, -1);

      dbg(mxhgt);
      FL(i, 0, mxhgt + 1){
        cerr << pth[i] << " ";
      }
      cerr<< endl;
      cerr << lf1 << " " << lf2 << endl;
      
      int cnt = pth[(mxhgt + 1)/2];
      cerr << cnt << endl;

    
      vi dpth(n + 1, 0);
      auto dfs3 = [&](auto &&self, int u, int p)->void{
        if (a[u].size() == 1 && p!=-1){
          dpth[u] = 0;
        }
        for (int x: a[u]){
          if (x == p) continue;
          self(self, x, u);
          REMAX(dpth[u], dpth[x] + 1);
        }
      };

      dfs3(dfs3, cnt, -1);
      cerr << "dp: ";
      FL(i, 1, n + 1){
        cerr << dpth[i] << " ";
      }
      cerr << endl;



      vi ans(n + 1);
      int cr = 2 * n;
      ans[cnt] = 2;
      if (a[cnt].size() == n - 1){
        FL(i, 1, n + 1){
          if (i != cnt){
            ans[i] = (cr == 4 ? 1: cr);           
            cr -= 2;
          }
        }
        FL(i, 1, n + 1){
          cout << ans[i] << " \n"[i==n];
        }
        continue;
      }


      priority_queue<pii> pq;
      queue<int> q;
      vb visited(n + 1, false);
      visited[cnt] = true;
      for (int x: a[cnt]){
        pq.push({dpth[x], x});
      }
      while (!pq.empty()){
        auto [_, y] = pq.top();
        pq.pop();
        q.push(y);
      }
      
      while (!q.empty()){
        int u = q.front();
        q.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (int x : a[u]){
          q.push(x);
        }
        ans[u] = cr;
        cr-=2;
      }
      FL(i, 1, n + 1){
        cout << ans[i] << " \n"[i==n];
      }

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

