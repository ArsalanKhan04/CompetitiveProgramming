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
    /// cin >> TCS;
    while(TCS--){
      int n;
      cin >> n;
      vector<vector<int>> routes(n);
      unordered_map<int, vector<int>> stop_to_routes;

      string line;
      getline(cin, line); // flush newline after n

      FL(i, 0, n) {
        getline(cin, line);
        stringstream ss(line);
        int stop;
        while (ss >> stop) {
          routes[i].pb(stop);
          stop_to_routes[stop].pb(i);
        }
      }

      int source, destination;
      cin >> source >> destination;

      if (source == destination) {
        cout << 0 << endl;
        continue;
      }

      unordered_set<int> visited_stops;
      unordered_set<int> visited_routes;
      queue<pair<int, int>> q;

      for (int route_idx : stop_to_routes[source]) {
        q.push({route_idx, 1});
        visited_routes.insert(route_idx);
      }

      int result = -1;
      while (!q.empty()) {
        auto [route_idx, hops] = q.front(); q.pop();
        auto& route = routes[route_idx];

        if (find(ALL(route), destination) != route.end()) {
          result = hops;
          break;
        }

        for (int stop : route) {
          if (visited_stops.count(stop)) continue;
          visited_stops.insert(stop);

          for (int next_route : stop_to_routes[stop]) {
            if (!visited_routes.count(next_route)) {
              visited_routes.insert(next_route);
              q.push({next_route, hops + 1});
            }
          }
        }
      }

      cout << result << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

