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
    // cin >> TCS;
    while(TCS--){
      int n, m;
      cin >> n;
      vi a(n + 1), b(n + 1);
      vi c(n + 1);
      FL(i, 1, n + 1) cin >> a[i];
      FL(i, 1, n + 1) cin >> b[i];
      vvll a_i(n + 1, vll(1, 0));
      vvll b_i(n + 1, vll(1, 0));
      vvll a_ic(n + 1);
      vvll b_ic(n + 1);

      ll ans = 0;
      FL(i, 1, n + 1){
        a_i[a[i]].pb(min(i, n - i + 1));
        b_i[b[i]].pb(min(i, n - i + 1));
      }
      FL(i, 1, n + 1){
        sort(ALL(a_i[i]));
        sort(ALL(b_i[i]));
        a_ic[i].assign(ALL(a_i[i]));
        FL(j, 1, a_ic[i].size()){
          a_ic[i][j] += a_ic[i][j-1];
        }
        b_ic[i].assign(ALL(b_i[i]));
        FL(j, 1, b_ic[i].size()){
          b_ic[i][j] += b_ic[i][j-1];
        }
      }
      FL(i, 1, n + 1){
        for (int x: a_i[i]){
          auto itr = upper_bound(ALL(b_i[i]), x);
          int cc = itr - b_i[i].begin() - 1;
          if (cc > 0)
          ans += b_ic[i][cc];
        }
        for (int x: b_i[i]){
          auto itr = lower_bound(ALL(a_i[i]), x);
          int cc = itr - a_i[i].begin() - 1;
          if (cc > 0)
          ans += a_ic[i][cc];
        }
      }

      FL(i, 1, n + 1){
        ll rgt = n - i;
        ll lft = i - 1;
        ans += ((rgt * (rgt + 1)) / 2 + (lft * (lft + 1)) / 2) * (a[i] == b[i]);
      }
      cout << ans << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

