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
    ll mx = 100001;
    vll a(mx + 1);
    FL(i, 0, mx+1){
      a[i] = i / 2;
    }
    FL(i, 2, mx + 1){
      for (int j = 2 * i; j < mx + 1; j+=i){
        a[j] -= a[i];
      }
    }
    FL(i, 1, mx + 1){
      cerr << a[i] << " ";
    }
    cerr << endl;
    vll c(mx + 1);
    dbg("here");
    c[2] = a[2];
    FL(i, 3, mx + 1){
      c[i] = 2 * a[i] + c[i-1];
    }
    FL(i, 1, mx + 1){
      cerr << c[i] << " ";
    }
    cerr << endl;
    dbg(c[100000]);
    while(testcases--){
      int n;
      cin >> n;
      int lw = 1;
      int hg = 100000;
      int md;
      while (lw <= hg){
        md = lw + (hg - lw) / 2;
        if (c[md] >= n){
          hg = md - 1;
        } else {
          lw = md + 1;
        }
      }
      dbg(hg);
      int x = n - c[hg];
      dbg(x);
      int cnt = 0;
      int y = 0;
      while (cnt < x){
        y++;
        dbg(y, lw - y);
        dbg(gcd(y, lw - y));
        if (gcd(y, lw -y) == 1){
          cnt++;
        }
        dbg(cnt);
      }
      cout << y << " " <<  lw - y << endl;
  
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

