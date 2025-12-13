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

constexpr int inf = 1e9;


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
      int n, m;
      cin >> n >> m;
      vvi to(n + 1, vi());
      FL(i,0,m){
        int U, V; cin >> U >> V;
        to[U].pb(V);
        to[V].pb(U);
      }
      vvi d(n + 1, vi(2, inf));
      string s;
      cin >> s;
      s = "%" + s;
      priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
      FL(i,1,n+1){
        if (s[i] == 'S') {
          pq.push({0, i, i});
        }       }
      vi ex(n + 1, -1);
      while (!pq.empty()){
        auto [cur_d, u, org] = pq.top();
        pq.pop();
        if (ex[u]==org || ex[u]==inf) continue;
        if (ex[u] == -1) ex[u] = org;
        else ex[u] = inf;
        if (cur_d < d[u][0]){
          d[u][1] = d[u][0];
          d[u][0] = cur_d;
        } else if (cur_d < d[u][1]){
          d[u][1] = cur_d;
        }
        for (auto v: to[u]){
          pq.push({cur_d+1, v, org});
        }
      }
      FL(i,1,n + 1){
        if (s[i] == 'D'){
          cout << d[i][0] + d[i][1] << endl;
        }
      }
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

