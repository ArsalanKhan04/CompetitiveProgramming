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
  
    int mx = 5 * 1e5 + 1;
    vvi fac(mx + 1);
    FL(i, 2, mx + 1){
      for (int j = i*2; j< mx + 1; j+=i){
        fac[j].pb(i);
      }
    }

    while(TCS--){
      int n,m,q;
      cin >> n>>m>>q;
      vi a(n);
      FL(i, 0, n)
        cin >> a[i];
      vi fc = fac[m];
      int ds = fc.size();
      vector<vector<set<int>>> vvs(ds);
      vector<int> cvs(ds);
      FL(i, 0, ds){
        int dv = fc[i];
        int m = m / dv;
        vvs[i] = vector<set<int>>(m);
      }
      FL(i, 0, ds){
        int f = fc[i];
        vector<set<int>>& vs = vvs[i];
        FL(j, 0, n){
          if (j != 0 && (a[j] % f == a[j-1] % f)) continue;
        }
      }
      
      while (q--){

      }
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

