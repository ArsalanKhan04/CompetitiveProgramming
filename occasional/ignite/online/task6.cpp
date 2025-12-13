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

const int INF = 1e9 + 1;


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
      int n;
      cin >> n;
      vector<vector<int>> routes(n);
      map<int, vector<int>> stop_to_routes;

      string line;
      getline(cin, line); // flush newline after n
                          //

      set<int> convs;
      FL(i, 0, n) {
        getline(cin, line);
        stringstream ss(line);
        int stop;
        while (ss >> stop) {
          routes[i].pb(stop);
          stop_to_routes[stop].pb(i);
          convs.insert(stop);
        }
      }


      int source, destination;
      cin >> source >> destination;

      vvi d(n, vi(n, INF));

      for (auto [ky, vl]: stop_to_routes){
        for (auto v1: vl){
          for (auto v2: vl){
            d[v1][v2] = 1;
            d[v2][v1] = 1;
          }
        }
      }
      FL(i,0,n) d[i][i] = 0;
      FE(k, 0, n - 1)
        FE(i, 0, n - 1)
          FE(j, 0, n - 1)
            REMIN(d[i][j], d[i][k] + d[k][j]);


      vi r1, r2;
      r1 = stop_to_routes[source];
      r2 = stop_to_routes[destination];
      int dis = INF;
      for (auto x: r1){
        for(auto y: r2){
          dis = min(dis, d[x][y]);
        }
      }

      if (dis == INF){
        cout << -1 << endl;
      }
      else 
        cout << dis + 1 << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

