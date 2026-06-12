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
      int n, m;
      cin >> n >> m;
      vpii a(n); vpii b(m);
      FL(i, 0, n)
        cin >> a[i].F >> a[i].S;
      FL(i, 0, m)
        cin >> b[i].F >> b[i].S;


      vector<ll> ans(m, 0);

      vector<ll> an_f(n+1, 0);
      ll mx_an=0;

      vector<vector<array<ll, 2>>> sind(n+1);
      FL(i,0,n){
        sind[a[i].S].pb({a[i].F, i});
      }

      // maintain set;
      set<array<ll, 2>> nc; // not considered
      set<array<ll, 2>> cc; // currently considered
                             //
                             //
      FL(i,0,n){
        nc.insert({a[i].F, i});
      }

      ll sm = 0;
      FL(i,0,n+1){
        // at start find value of an_f
        an_f[i] = sm;

        // now we add one value to cc
        if (nc.empty()) break;
        auto bg = *nc.rbegin();

        nc.erase(bg);
        cc.insert(bg);
        sm += bg[0];

        mx_an = max(mx_an, sm);

        // now we remove all values that are of current i
        for (auto cr: sind[i]){
          if (cc.find(cr) != cc.end()){
            sm -= cr[0];
            cc.erase(cr);
          } else {
            nc.erase(cr);
          }
        }

        // now until there are i+1 values, fill cc
        while (cc.size() != i+1){
          if (nc.size() == 0) break;
          bg = *nc.rbegin();
          nc.erase(bg);
          cc.insert(bg);
          sm += bg[0];
        }
        if (cc.size() != i+1) break;

      }

      FL(i,1,n + 1){
        an_f[i] = max(an_f[i], an_f[i-1]);
      }
      FL(i,0,m){
        ans[i] = max(an_f[b[i].S] + b[i].F, mx_an);
        cout << ans[i] << " ";
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

