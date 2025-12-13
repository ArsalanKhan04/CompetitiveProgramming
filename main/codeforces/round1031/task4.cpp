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

constexpr int INF = 1e9;


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
      vi a(n);
      vi b(n);
      FL(i, 0, n)
        cin >> a[i];
      FL(i,0,n) cin >>b[i];

      auto chck = [&](int x)->bool{
        if (x == 0) return true;
        int mnst1 = INF;
        int mn2st1 = INF;
        int mnst2 = INF;
        int mnst3 = -1;
        FL(i, 0, x){
          if (a[i] < mnst1) {
            mn2st1 = mnst1;
            mnst1 = a[i];
          } else if (a[i] < mn2st1) mn2st1 = a[i];
        }
        FL(i, 0, n-x+1){
          if (b[i] < mnst2) mnst2 = b[i];
        }
        FL(i,x,n){
          if (a[i] > mnst3) mnst3 = a[i];
        }
        if (mnst3 > mnst1){
          mnst1 = min(mn2st1, mnst3);
        } 
        if (mnst1 > mnst2){
          return true;
        }
        return false;
      };

      int lw = 0, hg = n;
      while (lw <= hg){
        int md = lw + (hg - lw) / 2;
        if (chck(md)){
          lw = md + 1;
        } else 
          hg = md - 1;
      }
      cout << hg << endl;



    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

