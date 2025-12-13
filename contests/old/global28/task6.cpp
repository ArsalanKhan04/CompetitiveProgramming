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
      vi a(n), b(n);
      FL(i, 0, n)
        cin >> a[i];
      FL(i, 0, n)
        cin >> b[i];

      vvi st(n, vi(log2(n) + 1));
      FL(i, 0, n){
        st[i][0] = b[i];
      }

      // Fill the rest of the table
      for (int j = 1; (1 << j) <= n; j++) {
          for (int i = 0; (i + (1 << j) - 1) < n; i++) {
              st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
          }
      }

      auto ranMin = [&](int L, int R)->int{
        int k = log2(R - L + 1);
        return min(st[L][k], st[R - (1 << k) + 1][k]);
      };
      
      ll x = 62;
      int opers = 0;
      while (x>=0){
        ll curr = (ll)1 << x;
        dbg(curr);
        int fst = -1;
        int lst = -1;
        FL(i, 0, n){
          if (a[i] > curr){
            if (fst == -1) fst = i;
            lst = i;
          }
        }
        x--;
        if (lst == -1) continue;
        dbg(x);
        double y = ranMin(fst, lst);
        FL(i, fst, lst + 1){
          a[i] = (int) ceil(a[i]/y);
        }
        opers++;
      }
      cout << opers << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

