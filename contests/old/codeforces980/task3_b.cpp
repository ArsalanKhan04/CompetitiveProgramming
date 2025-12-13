
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
      dbg("taking n");
      int n;
      cin >> n;
      dbg(n);
      dbg("init");
      vpii a(2 * n, {0, 0});
      vpii b(n, {0, 0});
      vpii ind(n, {0, 0});
      FL(i, 0, n){
        ind[i] = {0, i};
      }
      dbg("taking input");
      FL(i, 0, n){
        cin >> a[i].F;
        cin >> a[i+1].F;
        b[i].F = a[i].F;
        b[i].S = a[i+1].F;
        a[i].S = i;
        a[i+1].S = i;
      }
      dbg("here");
      sort(ALL(a));
      int prev = 0;
      FL(i, 0, 2*n){
        if (i!=0 && a[i-1].F == a[i].F){
          prev++;
        } else {
          prev = 0;
        }
        ind[i].F+=(i - prev);
      }
      dbg(ind[0].F);
      dbg("here");
      sort(ALL(ind));
      FL(i, 0, n){
        dbg(ind[i].S);
        cout << b[ind[i].S].F << " " << b[ind[i].S].S << " \n"[i==n-1];
      }
      dbg("here");

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

