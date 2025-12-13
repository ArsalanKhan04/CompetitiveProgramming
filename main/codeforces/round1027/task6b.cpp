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


constexpr int mxv = 1e6 + 2;

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
    vb prims(mxv, true);
    prims[1] = false;
    for (int i = 2; i < mxv; i++){
      if (prims[i]){
        for (int j = 2 * i; j < mxv; j+=i){
          prims[j] = false;
        }
      }
    }

    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int x, y, k;
      cin >> x >> y >> k;
      int xn = x / gcd(x, y); // div operations basically
      int yn = y / gcd(x, y); // mul operations basically
      
      int oprs = 0;
      bool fl = true;
      map<int, int> dvk;
      auto f = [&](auto &&slf, int vl)->int{
        if (vl == 1) return 0;
        if (dvk.find(vl) != dvk.end()) return dvk[vl];
        int ops = INT_MAX;
        FL(i, 1, sqrt(vl) + 1){
          if (vl % i == 0){
            int ai = vl / i;
            if (ai != 1 && ai <= k){
              ops = min(ops, 1 + slf(slf, i));
            } else if (prims[ai]) {
              fl = false;
              dbg(ai);
              break;
            }
            if (i != 1 && i <= k){
              ops = min(ops, 1 + slf(slf, ai));
            } else if (prims[i]) {
              dbg(i);
              fl = false;
              break;
            }
          }
        }
        if (!fl) return 0;
        dvk[vl] = ops;
        return ops;
      };
      oprs += f(f, xn);
      oprs += f(f, yn);
      if (fl){
        cout << oprs << endl;
      } else {
        cout << -1 << endl;
      }

      // convert xn to min num of divisors that are smaller than k
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

