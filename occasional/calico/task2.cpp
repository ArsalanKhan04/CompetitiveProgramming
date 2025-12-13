
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
      ll b, n;
      cin >> b >> n;
      vll a(n);
      FL(i, 0, n){
        cin >> a[i];
      }
      auto check = [&](ll md, ll &hgt){
        ll cst = 0;
        hgt = 0;
        FL(i, 0, n){
          if (a[i] > md){
            cst += a[i] - md;
          } else {
            hgt += md - a[i];
          }
        }
        if (cst <= b)
          return true;
        return false;
      };

      auto check2 = [&](ll md, ll &hgt){
        ll cst = 0;
        hgt = 0;
        FL(i, 0, n){
          if (a[i] > md){
            cst += a[i] - md;
          } else {
            hgt += md - a[i];
          }
        }
        if (hgt == 0)
          return true;
        return false;
      };
      ll lw, hg, md;
      ll hgt;
      lw = 0;
      hg = 1e13;
      while (lw <= hg){
        md = lw + (hg - lw) / 2;
        if (check(md, hgt)){
          hg = md - 1;
        } else {
          lw = md + 1;
        }
      }
      check(lw, hgt);
      if (hgt == 0){
        hg = 1e13;
        while (lw <= hg){
          md = lw + (hg - lw) / 2;
          if (check2(md, hgt)){
            lw = md + 1;
          } else {
            hg = md - 1;
          }
        }
        cout << hg << endl;
        continue;

      }
      dbg(lw);
      cout << lw << endl;
      
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

