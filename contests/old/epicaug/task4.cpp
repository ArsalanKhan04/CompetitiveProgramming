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

int is_val(vi& p, int n, int start){
  int nx1, nx2;
  int end;
  nx1 = p[start] * 2;
  nx2 = p[start] * 2 + 1;
  if (nx1 > n){
    return start + 1;
  }
  if (p[start+1] == nx1){
    end = is_val(p, n, start + 1);
    if (nx2 > n)
      return end;
    if (p[end] != nx2){
      return -1;
    }
  } else if (p[start+1] == nx2){
    end = is_val(p, n, start + 1);
    if (p[end] != nx1){
      return -1;
    }
  } else {
    return -1;
  }
  return is_val(p, n, end);
}


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
    int n, q;
    cin >> n >> q;
    vi a(n + 1), p(n);
    a[1] = 1;
    FL(i, 0, n-1)
      cin >> a[i + 2];
    FL(i, 0, n)
      cin >> p[i];
    int x, y;
    dbg(is_val(p, n, 0));
    FL(i, 0, q){
      cin >> x >> y;
      x--;
      y--;
      int temp;
      temp = p[x];
      p[x] = p[y];
      p[y] = temp;
      dbg(is_val(p, n, 0));
      condprt(is_val(p, n, 0) == n);
    }
  }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

