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
      vll a(n), b(n);
      FL(i, 0, n)
        cin >> a[i];
      FL(i, 0, n)
        cin >> b[i];
      sort(ALL(b));
      ll tot = 0;
      FL(i, 0, n){
        tot += a[i];
      }
      FL(i, 0, n){
        tot -= b[i];
      }
      sort(ALL(a));
      sort(ALL(b));
      bool fl = false;
      FL(i, 0, n){
        if (a[i] != b[i]){
          fl = true;
          break;
        }
      }
      if (tot == 0){
        if (fl){
          cout << -1 << endl;
        } else {
          cout << (ll)1e8 << endl;
        }
        continue;
      }
      int st = *max_element(ALL(b)) + 1;
      int ans = 0;
      bool flag = false;
      vll facs;
      dbg(tot);
      dbg(sqrt(tot)+1);
      FL(i, 1, sqrt(tot) + 1){
        if (tot % i == 0){
          facs.pb(i);
          facs.pb(tot / i);
        }
      }
      for (auto x: facs){
        if (x < st) continue;
        vll c = a;
        vll d = b;
        FL(i, 0, n){
          c[i] %= x;
        }
        sort (ALL(c));
        flag = true;
        FL(i, 0, n){
          if (c[i] != b[i]){
            flag = false;
            break;
          }
        }
        if (flag){
          ans = x;
          break;
        }
      }
      if (flag){
        cout <<(ll) ans << endl;
      } else {
        cout << -1 << endl;
      }

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

