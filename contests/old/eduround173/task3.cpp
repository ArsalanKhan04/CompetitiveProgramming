#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int
#define MOD % 1000000007
#define FL(i, a, b) for (int i = a; i < b; i++)
#define FE(i, a, b) for (int i = a; i <= b; i++)
#define FF(i, a, b) for (int i = a; i > b; i--)
#define FFE(i, a, b) for (int i = a; i >= b; i--)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
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

#define REMAX(a, b) a = max((a), (b))
#define REMIN(a, b) a = min((a), (b))

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define INF int(1e9) + 9
 
#define endl '\n'
 
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

    int testcases = 2;
    cin >> testcases;
    while(testcases--){
      int n;
      cin >> n;
      vi a(n);
      int v = n / 2;
      FL(i, 0, n){
        cin >> a[i];
        if (abs(a[i]) != 1)
          v = i;
      }

      ll mx = 0;
      ll mn = 0;
      ll curr = 0;
      for (int i = v + 1; i < n; i++){
        curr += a[i];
        REMAX(mx, curr);
        REMIN(mn, curr);
      }
      curr = 0;
      ll mx2 = 0;
      ll mn2 = 0;
      for (int i = v - 1; i >= 0; i--){
        curr += a[i];
        REMAX(mx2, curr);
        REMIN(mn2, curr);
      }
      REMAX(mx, mx + mx2);
      REMIN(mn, mn + mn2);

      int mn1 = 0, mx1 = 0;
      int t1, t2;
      if (v != 0){
        vi c(v + 1, 0);
        FL(i, 0, v){
          c[i + 1] = a[i];
        }
        FL(i, 1, v){
          c[i + 1] += c[i];
        }
        t1 = 0;
        t2 = 0;
        FL(i, 1, v + 1){
          t1 = min(t1, c[i]);
          t2 = max(t2, c[i]);
          REMAX(mx1, c[i] - t1);
          REMIN(mn1, c[i] - t2);
        }
      }

      if (n - v - 1 != 0){
        vi d(n - v, 0);
        FL(i, 1, n - v){
          d[i] = a[v + i];
        }
        FL(i, 1, n - v){
          d[i] += d[i - 1];
        }
        t1 = 0;
        t2 = 0;
        FL(i, 1, n - v){
          t1 = min(t1, d[i]);
          t2 = max(t2, d[i]);
          REMAX(mx1, d[i] - t1);
          REMIN(mn1, d[i] - t2);
        }
      }
      set<ll> ans;
      for (ll i = mn1; i <= mx1; i++){
        ans.insert(i);
      }
      for (ll i = mn; i <= mx; i++){
        ans.insert(a[v] + i);
      }
      cout << ans.size() << endl;
      for (ll x : ans){
        cout << x << " ";
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

