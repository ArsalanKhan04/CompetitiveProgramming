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
      int n,m,l; cin>>n>>m>>l;
      vvi dp(n+1, vi(m+1, 0));
      vi a(n + 1, 0);
      FL(i,1,n+1) cin >> a[i];
      vector<int> cr;
      FL(i,1,n+1){
        // remaining = n - i
        // we should have n - i + 1 at each time
        int rem = n - i + 2;
        dbg(rem);
        rem = min(rem,m);
        int ad = a[i]-a[i-1];
        while (cr.size() < rem && ad){
          cr.push_back(1);
          ad--;
        }
        sort(ALL(cr));
        int idx = 0;
        while (ad){
          cr[idx]++;
          ad--;
          idx++;
          if (idx >= cr.size() || cr[idx] >= cr[idx-1]) idx = 0;
        }
        sort(ALL(cr));
        cr.pop_back();
      }
      if (cr.empty()) cr.push_back(l-a[n]);
      else cr.back() += l - a[n];
      cout << cr[0] << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

