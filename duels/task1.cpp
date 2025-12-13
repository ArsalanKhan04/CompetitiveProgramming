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
    // cin >> TCS;
    while(TCS--){
      int n;
      cin >> n;
      vll a(n), b(n);
      FL(i, 0, n)
        cin >> a[i];
      FL(i, 0, n){
        cin >> b[i];
        b[i]--;
      }
      vi pr(n, 0);
      vvi to(n, vi());
      FL(i, 0, n){
        if (b[i] >= 0)
          pr[b[i]]++;
        to[i].pb(b[i]);
      }
      queue<int> q;
      FL(i, 0, n){
        if (pr[i] == 0){
          q.push(i);
        }
      }
      ll ans = 0;
      queue<int> mvs;
      stack<int> mv2;
      while (!q.empty()){
        auto x = q.front();
        q.pop();
        ans += a[x];
        if (a[x] >= 0){
          mvs.push(x);
        } else {
          mv2.push(x);
        }
        for (auto v: to[x]){
          if (v < 0) continue;
          pr[v]--;
          if (a[x] > 0){
            a[v] += a[x];
          }
          if (pr[v] == 0) q.push(v);
        }
      }
      while (!mv2.empty()){
        mvs.push(mv2.top());
        mv2.pop();
      }
      cout << ans << endl;
      assert(mvs.size() == n);
      while (!mvs.empty()){
        cout << mvs.front() + 1 << " ";
        mvs.pop();
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

