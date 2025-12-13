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
      int n;
      cin >> n;
      vi a(n);
      FL(i,0,n) cin >> a[i];
      vpii b(n);
      FL(i,0,n) cin >> b[i].F >> b[i].S;
      int mx = 0;
      int mn = 0;
      bool flag = true;
      FL(i, 0, n){
        if (a[i] == 1){
          mx++;
          mn++;
        } else if (a[i] == -1){
          mx++;
        }
        mx = min(mx, b[i].S);
        mn = max(mn, b[i].F);
        b[i].F = mn;
        b[i].S = mx;
        if (mx < mn){
          flag = false;
          break;
        }
      }
      if (!flag){
        cout << -1 << endl;
        continue;
      }
      int vl = mn;
      vi c = a;
      for (int i = n - 1; i >= 0; i--){
        if (c[i] == 1){
          vl--;
        } else if (c[i] == -1){
          if (vl >= b[i].F && vl!=0 && (i==0 || vl>b[i-1].F)){
            vl--;
            c[i] = 1;
          } else {
            c[i] = 0;
          }
        }
      }
      FL(i, 0, n){
        cout << c[i] << " ";
      }
      cout << endl;

      dbg(mn, mx);
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

