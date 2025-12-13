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

/*
 * Algorithm: 
 * First of all, assign all nodes as l_i
 * then calculate differences of each vertex
 * make a directed graph
 * from each node that only has incoming edge, increase its value to minimize the size of incoming edges
 * do topo sort to get the new size yay
 */


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
    cin >> TCS;
    while(TCS--){
      int n;
      cin >> n;
      
      vpii lr(n);
      vi siz(n);
      FL(i, 0, n){
        cin >> lr[i].F >> lr[i].S;
        siz[i] = lr[i].F;
      }
      vvi ug(n, vi());
      {
        int u, v;
        FL(i, 0, n - 1){
          cin >> u >> v;
          u--; v--;
          ug[u].pb(v);
          ug[v].pb(u);
        }
      }
      auto f = [&](auto &&slf, int u, int p)->ll{
        ll curr = 0; int vv = 0;
        if (ug[u].size() == 1 && p != -1) return 0;
        for (auto v: ug[u]){
          if (v == p) continue;
          curr += slf(slf, v, u);
          vv = max(vv, siz[v]);
        }
        vv = min(vv, lr[u].S); vv = max(vv, lr[u].F);
        siz[u] = vv;
        for (auto v: ug[u]){
          if (v==p) continue;
          curr += max(0, siz[v] - siz[u]);
        }
        return curr;
      };
      ll ans = f(f, 0, -1);
      cout << ans + siz[0] << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

