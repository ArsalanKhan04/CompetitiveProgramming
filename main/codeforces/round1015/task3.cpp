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
      vi a(n), b(n);
      FL(i, 0, n){
        cin >> a[i];
      }
      FL(i, 0, n) cin >> b[i];
            vpii c(n), d(n);
      int smcnt = 0;
      FL(i, 0, n){
        c[i] = {a[i], b[i]};
        d[i] = {b[i], a[i]};
        if (a[i] == b[i]) smcnt++;
      }
      sort(ALL(c)); sort(ALL(d));
      bool flag = true;
      if (smcnt > 1) flag = false;
      FL(i, 0, n){
        if (c[i].F != d[i].F || c[i].S != d[i].S){
          flag = false;
          break;
        }
      }
      if (!flag){
        cout << -1 << endl;
        continue;
      }
      vpii mvs;
      FL(i, 0, n){
        if (a[i] == b[i] && i != (n + 1) / 2 - 1){
          swap (a[i], a[(n + 1)/2 - 1]);
          swap (b[i], b[(n + 1)/2 - 1]);
          mvs.push_back({i + 1, ((n + 1)/2)});
        }
      }
      int x = 0;
      vi top(n + 1, -1);
      FL(i, 0, n){
        while (top[b[i]] != -1 && top[b[i]] != i){
          int tp = top[b[i]];
          mvs.push_back({i + 1, tp + 1});
          swap(a[i], a[tp]);
          swap(b[i], b[tp]); 
        }
        if (i < n / 2){
          top[a[i]] = n - i - 1;
        }
      }
      FL(i, 0, n){
        if (a[i] != b[n-i-1]) flag = false;
      }
      if (flag == false){
        cout << -1 << endl;
        continue;
      }
      cout << mvs.size() << endl;
      for (auto y: mvs){
        cout << y.F << " " << y.S << endl;
      }
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

