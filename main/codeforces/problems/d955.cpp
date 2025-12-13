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


void print_vec(const vector<int>& vec, int n) {
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
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
    int n, m, k;
    cin >> n >> m >> k;
    vvi a(n, vi(m, 0));
    string s;
    vvi b(n, vi(m, 0));
    FL(i, 0, n)
      FL(j, 0, m)
         cin >> a[i][j];

    FL(i, 0, n){
      cin >> s;
      FL(j, 0, m)
        b[i][j] = s[j] == '1';
    }

    ll diff = 0;
    FL(i, 0, n)
      FL(j, 0, m)
        diff += b[i][j] ? a[i][j] : a[i][j] * -1;

    dbg(diff);

    int temp = 0;
    int total = 0;
    FL(i, 0, n){
      temp = 0;
      total = 0;
      FL(j, 0, m){
        total+=b[i][j] ? 1 : -1;
        if (j >= k-1){
          if (j >= k)
            total-=temp ? 1 : -1;
          temp = b[i][j-k+1];
          b[i][j-k+1] = total;
        }
      }
    }
    dbg(b[0][0]);
    dbg(b[0][1]);

    FL(j, 0, m){
      total = 0;
      temp = 0;
      FL(i, 0, n){
        total+=b[i][j];
        if (i >= k-1){
          total-=temp;
          temp = b[i-k+1][j];
          b[i-k+1][j] = total;
        }
      }
    }

    int gc = b[0][0];
    FL(i, 0, n-k+1)
      FL(j, 0, m-k+1){
        gc = gcd(gc, b[i][j]);
      }

    dbg(gc);
    if (gc == 0){
      if (diff == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else {
      condprt(diff%gc==0);
    }
  }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}
