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
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define REMIN(x, a) (x) = min((x), (a))

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
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

  int t;
  cin >> t;
  FL(et, 0, t) {
    int n;
    cin >> n;
    vi a(n + 1);
    FL(i, 1, n + 1){
      cin >> a[i];
    }
    vvi c(n + 1, vi());
    int num;
    FL(i, 2, n + 1){
      cin >> num;
      c[num].pb(i);
    }
    vi sum(n + 1, 0);
    FL(i, 1, n+1)
      for(int x: c[i])
        sum[i]+=a[x];
    
    vi depth(n + 1, 0);
    function<int(int)> dfs1 = [&](int v)->int{
      if (c[v].empty()){
        depth[v] = 1;
        return 1;
      }
      int mn = 5001;
      for(int x: c[v])
        REMIN(mn, dfs1(x));
      depth[v] = mn + 1;
      if (a[v] < sum[v]){
        depth[v] = 1;
        return 1;
      }
      return mn + 1;
    };
    
    function<int(int, int)> dfs2 = [&](int v, int inc)->int{
      if (c[v].empty()){
        a[v] += inc;
        return 0;
      }
      if (a[v] < sum[v]){
        a[v] += min(inc, sum[v] - a[v]);
        int mn = c[v][0];
        for(int x: c[v]){
          if (depth[mn] > depth[x]){
            mn = x;
          }
        }
        depth[v] += depth[mn];
        return inc - min(inc, sum[v] - a[v]);
      }
      if (a[v] > sum[v]){
        int inc2 = sum[v] - a[v];
        while (true){
          int mn = c[v][0];
          for(int x: c[v]){
            if (depth[mn] > depth[x]){
              mn = x;
            }
          }
          if (inc2 == 0){
            break;
          }
          inc2 = dfs2(mn, inc2);
        }
        depth[v] = depth[v] + depth[mn];
      }
    };

  }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

