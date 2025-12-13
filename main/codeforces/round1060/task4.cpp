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
      vvi to(n+1, vi());
      int U, V;
      FL(i,0,n-1){
        cin >> U >> V;
        to[U].pb(V);
        to[V].pb(U);
      }
      // keep odd and even in mind when cutting
      vb done(n+1, false);
      vi ind(n + 1, 0);
      FL(i,1,n+1){
        for (auto v: to[i]){
          ind[v]++;
        }
      }
      done[n] = true;
      // first need to find where is n

      set<int> st[2];
      bool inpr;
      auto f = [&](auto &&slf, int u, int d, int p)->void{
        if (p != -1 && to[u].size() == 1){
          st[d].insert(u);
        }
        if (u == 1) inpr = d;
        for (auto v: to[u]){
          if (v == p) continue;
          slf(slf, v, !d, u);
        }
      };
      f(f, n, 0, -1);
      cout << 3 * n << endl;
      int i = 0;
      while (i < 3 * n){
        if (st[!inpr].size() == 0){
          cout << 1 << endl;
          i++;
        } else {
          int vl = *st[!inpr].begin();
          for (auto v: to[vl]){
            if (done[v]) continue;
            ind[v]--;
            if (ind[v] == 1)
              st[inpr].insert(v);
          }
          st[!inpr].erase(vl);
          cout << 2 << " " << vl << endl;
          done[vl] = true;
          cout << 1 << endl;
          i+=2;
        }
        inpr = !inpr;
      }
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

