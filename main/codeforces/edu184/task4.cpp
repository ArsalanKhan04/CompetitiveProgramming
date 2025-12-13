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
      ll x, y, k;
      dbg(log2(1e12));
      cin >> x >> y >> k;
      if (k < y){
        cout << k << endl;
        continue;
      } else if (y == 1){
        cout << -1 << endl;
        continue;
      }
      auto f1 = [&](ll v){
        ll v2 = v - 1;
        FL(i,0,x){
          v2 -= v2/y;
        }
        return v2+1;
      };
      if (x <= 1e6){
        ll vl = k - 1;
        FL(i,0,x){
          vl += vl / (y-1);
        }
        if (vl+1 > 1e12){
          cout << -1 << endl;
          continue;
        }
        cout << vl+1 << endl;
        continue;
      }
      if (y >= 1e5){
        ll trs = x;
        bool fl = true;
        ll cr = k - 1;
        FL(i,2,1e7+2){
          if (trs == 0) break;
          if (cr >= i * (y-1)){
            continue;
          }
          ll df = i * (y-1) - cr;
          ll ps = cr / (y - 1);
          ll dv = (df + ps - 1) / ps;
          dv = min(dv, trs);
          cr += dv * ps;
          trs -= dv;
        }
        if (cr + 1 > 1e12){
          cout << -1 << endl;
          continue;
        }
        cout << cr + 1 << endl;
        continue;
      }
      cout << -1 << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

