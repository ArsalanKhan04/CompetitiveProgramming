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
      FL(i, 0, n)
        cin >> a[i];
      vi ra(n + 1, -1);
      FL(i, 0, n){
        ra[a[i]] = i;
      }
      int U, V;
      vector<set<int>> to(n, set<int>());
      FL(i, 0, n - 1){
        cin>>U>>V;
        U--;V--;
        to[U].insert(V);
        to[V].insert(U);
      }
      vi av(n + 1, 2*1e5 + 2);
      FL(i, 0, n){
        int vl = 0;
        if (a[i] == 0){
          int fr = 0;
          for (auto v: to[i]){
            vl = max(vl, a[v]);
            if (a[v] == 0) fr++;
          }
          dbg(fr);
          av[vl] = min(fr, av[vl]);
        }
      }
      FL(i, 1, n + 1){
        av[i] = min(av[i], av[i-1]);
      }
      int prvl = 0;
      ll ans = -1;
      FL(i, 1, n + 1){
        dbg(prvl, ra[i], av[i]);
        if (ra[i] == -1){
          if (prvl >= av[i]){
            ans = i;
            break;
          }
          prvl++;
        } else {
          bool fl = true;
          for (auto v: to[ra[i]]){
            if (a[v] != 0){
              fl = false;
            }
            to[v].erase(ra[i]);
          }
          if (fl && to[ra[i]].size() <= prvl){
            ans = i;
            break;
          }
        }
      }
      cout << ans << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

