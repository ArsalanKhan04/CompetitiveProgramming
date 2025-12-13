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

constexpr ll INF = 1e18;


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
      ll n, m;
      cin >> n >> m;
      vll a(n + 1, 0);
      FL(i, 1, n + 1)
        cin >> a[i];
      vll b(n + 1, 0);
      vll c(n + 1, 0);
      FL(i, 1, n + 1){
        b[i] = a[i] % m;
      }
      sort(ALL(b));
      FL(i, 1, n + 1){
        c[i] = b[i] + c[i-1];
      }
      ll tot = INF;
      ll lptr, rptr;
      FL(i, 1, n + 1){
        ll curr = b[i];
        ll t_c = 0;
        {
          auto itr1 = upper_bound(ALL(b), curr);
          lptr = itr1 - b.begin() - 1;
          auto itr2 = upper_bound(ALL(b), m / 2 + curr);
          rptr = itr2 - b.begin() - 1;
          if (lptr == -1) lptr = 1;
          // dbg(lptr, rptr);
          t_c += lptr * curr - c[lptr];
          t_c += c[rptr] - c[lptr] - curr * (rptr-lptr);
          t_c += -c[n] + c[rptr] + (n - rptr) * (curr + m);
          REMIN(tot, t_c);
        } 
        {
          t_c = 0;
          curr = m - curr;
          auto itr1 = upper_bound(ALL(b), m / 2 - curr);
          lptr = itr1 - b.begin() - 1;
          if (lptr == -1) lptr = 0;
          auto itr2 = upper_bound(ALL(b), m - curr);
          rptr = itr2 - b.begin() - 1;
          // dbg(lptr, rptr);
          t_c += c[lptr] + curr * lptr;
          t_c += (m - curr) * (rptr - lptr) - c[rptr] + c[lptr];
          t_c += (curr - m) * (n - rptr) + c[n] - c[rptr];
          REMIN(tot, t_c);
        }
      }
      cout << tot << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

