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
    cin >> TCS;
    while(TCS--){
      int n;
      cin >> n;
      vi a(n);
      int U, V;
      vector<set<int>> to(n);
      FL(i, 0, n - 1){
        cin >> U >> V;
        U--; V--;
        to[U].insert(V);
        to[V].insert(U);
      }



      vector<array<int, 3>> sol;

      vector<bool> remd(n, true);

      auto dfs1 = [&](auto&& slf, int u, int p, int d)->pii{
        pii ans = {d, u};
        for (auto v: to[u]){
          if (v == p) continue;
          auto tmp= slf(slf, v, u, d + 1);
          ans = max(ans, tmp);
        }
        return ans;
      };


      stack<int> trem;
      auto rem = [&](auto&& slf, int u, int v, int p)->bool{
        // dbg("Going in: ", u);
        if (u == v){
          remd[u] = false;
          trem.push(u);
          return true;
        }
        bool cr = false;
        for (auto vv: to[u]){
          if (vv == p){
            continue;
          }
          cr |= slf(slf, vv, v, u);
          if (cr) break;
        }
        if (cr){
          remd[u] = false;
          trem.push(u);
        }
        return cr;
      };


      int u = 0;
      while (u < n){
        if (!remd[u]) {
          u++;
          continue;
        }
        pii ff = dfs1(dfs1, u, -1, 0);
        pii ss = dfs1(dfs1, ff.S, -1, 0);
        int dd = ss.F + 1;
        if (ff.S < ss.S) swap(ff.S, ss.S);
        sol.push_back({dd, ff.S, ss.S});
        rem(rem, ss.S, ff.S, -1);
        while (!trem.empty()){
          int ttt = trem.top();
          trem.pop();
          for (auto vvv: to[ttt]){
            to[vvv].erase(ttt);
          }
        }
      }


      sort(RALL(sol));

      for (auto ss: sol){
        cout << ss[0] << " " << ss[1] + 1 << " " << ss[2] + 1 << " ";
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

