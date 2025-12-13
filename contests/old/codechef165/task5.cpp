
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
      int n;
      cin >> n;
      vll b(n);
      ll cr = 0;
      bool fl = false;
      FL(i, 0, n){
        cin >> b[i]; cr+= b[i];
        if (b[i] != 0) fl = true;
      }
      if (cr == 0 && fl) {cout << -1 << endl; continue;}
      if (!fl) {cout << 0 << endl; continue;}
      if (cr < 0){
        FL(i, 0, n) b[i] = -1 * b[i];
        cr = -1 * cr;
      }
      ll non_z = -1;
      FL(i, 0, n){
        if (b[i] != 0) non_z = i;
      }
      vll a;
      a.assign(b.begin(), (b.begin() + non_z + 1));
      n = a.size();
      dbg(non_z);
      dbg(n);
      dbg(a[n-1]);
      ll opers = 0;
      dbg(a[0]);
      if (a[0] <= 0){
        opers+= 1 - a[0];
        cr+= 1 - a[0];
        a[0]= 1;
      }
      dbg(a[0]);
      FL(i, 0, n){
        if (cr < i + 1){
          cr++;
          opers++;
          a[0]++;
        }
        if (a[i] < 0) {
          cr += -1 * a[i];
          opers += -1 * a[i];
          a[i] = 0;
        }
      }
      dbg(a[0]);

      FL(i, 1, n + 1){
        if (a[n-i] == 0) continue;
        if (n - i + 1 > cr){
          opers += n - i + 1 - cr;
          a[0] += n - i + 1 - cr;
          cr = n - i + 1;
        }
        dbg(cr);
        dbg(a[n-i]);
        dbg(i);
        if (n - i + 1 > cr - a[n-i] + 1){
          opers += n - i + 1 - (cr - a[n-i] + 1);
          a[0] += n - i + 1 - (cr - a[n-i] + 1);
          cr += n - i + 1 - (cr - a[n-i] + 1);
        }
        dbg(cr);
        cr -= a[n - i];
        opers += a[n-i];
        dbg(opers);
        dbg(a[0]);
        dbg("---");
      }
      cout << opers << endl;
      

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

