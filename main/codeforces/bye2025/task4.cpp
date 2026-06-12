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
      int n, m;
      cin >> n >> m;
      vi a(n);
      FL(i, 0, n)
        cin >> a[i];
      if (m > n / 2){
        cout << -1 << endl;
        continue;
      }
      vector<pii> vp;
      FL(i,0,n){
        vp.pb({a[i], i+1});
      }
      sort(ALL(vp));
      vector<pii> mvs;
      if (m == 0){
        int cr = n - 2;
        ll sm = 0;
        while (cr >= 0 && sm < vp[n-1].F){
          sm += vp[cr].F;
          cr--;
        }
        if (sm < vp[n-1].F){
          cout << -1 << endl;
          continue;
        }
        FL(i,0,cr+1){
          mvs.pb({vp[i].S, vp[i+1].S});
        }
        FL(i,cr+1,n-1){
          mvs.pb({vp[i].S, vp[n-1].S});
        }
      } else {
        int rm = n - (m*2);
        FL(i,0,rm){
          mvs.pb({vp[i].S, vp[i+1].S});
        }
        for (int i = n - 1; i > rm; i-=2){
          mvs.pb({vp[i].S, vp[i-1].S});
        }
      }


      cout << mvs.size() << endl;
      for (auto mv: mvs){
        cout << mv.F << " " << mv.S << endl;
      }
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

