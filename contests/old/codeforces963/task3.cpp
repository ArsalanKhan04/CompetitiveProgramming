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
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
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

  int t;
  cin >> t;
  FL(et, 0, t) {
    int n, k;
    cin >> n >> k;
    vi a(n);
    vi b(n);
    FL(i, 0, n)
      cin >> a[i];
    FL(i, 0, n){
      b[i] = a[i] % (2 * k);
    }
    sort(ALL(b));
    set<int> pres;
    bool flag = true;
    int mn = b[0];
    int mx = b[0] + k - 1;
    dbg(mn);
    dbg(mx);
    FL(i, 0, n){
      int ed = (b[i] + k - 1) - (2 * k);
      if (b[i] > mx && ed < mn){
        flag = false;
        break;
      } else {
        if (b[i] <= mx){
          mn = b[i];
        } else {
          mx = ed;
        }
      }
    }
    if (!flag){
      cout << -1 << endl;
    } else {
      int mxA = -1;
      FL(i, 0, n){
        mxA = max(mxA, a[i]);
      }
      int ans  =  mxA - (mxA % (2 *  k)) + mn;
      if (ans < mxA){
        ans += 2 * k;
      }
      cout << ans << endl;
    }
    

  }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

