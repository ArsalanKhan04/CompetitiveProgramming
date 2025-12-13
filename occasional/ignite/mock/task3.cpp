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
      int n,m;cin>>n>>m;
      vvi to(n);
      int U, V;
      FL(i,0,m){
        cin >> U >> V;
        U--; V--;
        to[U].pb(V);
        to[V].pb(U);
      }
      vi b(n, -1);
      vi vis(n, false);
      bool fl = true;
      auto f = [&](auto &&slf, int u, int c)->void{
        if (b[u] != -1 && b[u] != c){
          fl = false;
          return;
        }
        if (vis[u]) return;
        vis[u] = true;
        b[u] = c;
        for (auto v: to[u]){
          slf(slf, v, !c);
        }
      };
      FL(i, 0, n){
        if (!vis[i]) f(f, i, 0);
      }

      if (!fl){
        cout << -1 << endl;
        continue;
      }


      int s3=0;
      map<int, int> pr;
      vi vs3(n, false);
      auto f3 = [&](auto&& slf, int u)->void{
        if (vs3[u]) return;
        pr[u] = s3;
        vs3[u] = true;
        for (auto v: to[u]){
          slf(slf, v);
        }
      };
      FL(i, 0, n){
        if (!vs3[i]){
          f3(f3, i);
          s3++;
        }
      }

      vi an(s3, 0);
      auto f2 = [&](int x){
        vb vs(n, false);
        if (vs[x]) return 0;
        int vl = 0;
        queue<pii> q;
        q.push({x, 1});
        vs[x] = true;
        while (!q.empty()){
          auto [u, c] = q.front();
          vl = max(vl, c);
          q.pop();
          for (auto v: to[u]){
            if (!vs[v]){
              q.push({v, c+1});
              vs[v] = true;
            }
          };
        }
        an[pr[x]] = max(an[pr[x]], vl);
        return vl;
      };
      FL(i, 0, n){
        f2(i);
      }


      int vl = 0;
      for (auto vv: an){
        vl += vv;
      }
      cout << vl << endl;


    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

