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

    int testcases = 1;
    cin >> testcases;
    while(testcases--){
      int n;
      cin >> n;
      vpii a(n);
      FL(i, 0, n)
        cin >> a[i].F >> a[i].S;
      vi a_x(n), b_x(n);
      iota(ALL(a_x), 0);
      iota(ALL(b_x), 0);
      sort(ALL(a_x), [&](int x, int y) {
            return a[x].F > a[y].F;
          });
      sort(ALL(b_x), [&](int x, int y) {
            return a[x].S > a[y].S;
          });
      int b_mx = 0;
      int a_mx = 0;

      int b_i = 0;
      int a_i = 0;
      int diff = INT_MAX;
      while (true){
        if (a_i == n || b_i == n || a[a_x[a_i]].F < a_mx || a[b_x[b_i]].S < b_mx){
          break;
        }
        if (a_x[a_i] != b_x[b_i]){
          REMIN(diff, abs(a[a_x[a_i]].F - a[b_x[b_i]].S));
        } else {
          if (b_i != n - 1)
            REMIN(diff, abs(a[a_x[a_i]].F - a[b_x[b_i+1]].S));   
          if (a_i != n - 1)
            REMIN(diff, abs(a[a_x[a_i + 1]].F - a[b_x[b_i]].S));   
        }
        if (a[a_x[a_i]].F < a[b_x[b_i]].S){
          REMAX(a_mx, a[b_x[b_i]].F);
          b_i++;
        } else {
          REMAX(b_mx, a[a_x[a_i]].S);
          a_i++;
        }
      }
      cout << diff << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

