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
      int U, V;
      vector<set<int>> to(n, set<int>());
      FL(i, 0, n-1){
        cin>>U>>V;
        U--; V--;
        to[U].insert(V);
        to[V].insert(U);
      }
      int ux = -1, vx = -1;
      FL(i, 0, n){
        if (to[i].size() == 2){
          for (auto v: to[i]){
            ux = i; vx = v;
            break;
          }
        }
        if (ux != -1) break;
      }
      if (ux == -1 && vx == -1){
        cout << "NO" << endl;
        continue;
      }
      cout << "YES" << endl;
      auto f = [&](auto && slf, int u, int p, bool pr)->void{
        for (auto v: to[u]){
          if (v == p) continue;
          if (v == vx){
            pr = !pr;
          }
          if (pr){
            cout << v + 1 << " " << u + 1 << endl;
          } else {
            cout << u + 1 << " " << v + 1 << endl;
          }
          slf(slf, v, u, !pr);
          if (v == vx){
            pr = !pr;
          }
        }
      };
      f(f, ux, -1, 0);

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

