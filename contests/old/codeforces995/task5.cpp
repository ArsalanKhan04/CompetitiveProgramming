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
      int n, k;
      cin >> n >> k;
      vi a(n), b(n);
      FL(i, 0, n)
        cin >> a[i];
      FL(i, 0, n)
        cin >> b[i];

      map<int, int> a_c;
      a_c[0] = 0;
      FL(i, 0, n){
        a_c[a[i]]++;
        if (a_c.find(b[i]) == a_c.end())
          a_c[b[i]] = 0;
      }
      int prev = 0;
      for (auto [x, y]: a_c){
        a_c[x] += prev;
        prev += y;
      }
      map<int, int> b_c;
      b_c[0] = 0;
      FL(i, 0, n){
        b_c[b[i]]++;
        if (b_c.find(a[i]) == b_c.end())
          b_c[a[i]] = 0;
      }
      prev = 0;
      for (auto [x, y]: b_c){
        b_c[x] += prev;
        prev += y;
      }

      vi alls;
      FL(i, 0, n){
        alls.pb(a[i]);
        alls.pb(b[i]);
      }
      sort(ALL(alls));
      alls.erase(unique(ALL(alls)), alls.end());
      ll mx_profit = 0;
      prev = 0;
      ll curr = 0;
      for (auto x: alls){
        if (curr <= k)
          mx_profit = max(mx_profit, (ll) (n - prev) * x);
        prev = b_c[x];
        curr = a_c[x] - b_c[x];
      }

      cout << mx_profit << endl;



    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

