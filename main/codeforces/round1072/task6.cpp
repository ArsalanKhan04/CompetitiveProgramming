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
      vvi to(n);
      int U, V;
      FL(i,0,n-1){
        cin>>U>>V; U--;V--;
        to[U].pb(V);
        to[V].pb(U);
      }
      vector<array<bool, 3>> tb(n, {false});
      auto f = [&](auto &&slf, int u, int p)->void{
        tb[u][1] = true;
        array<int, 3> cr = {0};
        for (auto v: to[u]){
          if (v==p) continue;
          slf(slf, v, u);
          cr[0] += tb[v][0];
          cr[1] += tb[v][1];
          cr[2] += tb[v][2];
          if (u == 0)
            FL(i,0,3){
              dbg(v, i, tb[v][i]);
            }
        }
        if (u == 0)
          dbg(cr[0], cr[1], cr[2]);
        if (cr[1])
          tb[u][cr[1]%3] = true;
        FL(i,1,min(3, cr[2])+1){
          tb[u][(cr[1]+i)%3] = true;
        }
        FL(i,1,min(3, cr[0])+1){
          tb[u][(cr[1]+i*2)%3] = true;
        }
        if (u == 0)
          FL(i,0,3){
            dbg(u, i, tb[u][i]);
          }
      };
      f(f, 0, -1);
      condprt(tb[0][0]);
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

