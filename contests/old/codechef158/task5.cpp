#include <algorithm>
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
      vi c(n, 0);
      int A, B;
      vvi adj(n + 1, vi(n + 1, 0));
      FL(i, 0, n - 1){
        cin >> A >> B;
        A--;
        B--;
        c[A]++;
        c[B]++;
        adj[A][B] = 1;
        adj[B][A] = 1;
      }
      int mx = 0;
      FL(i, 0, n){
        REMAX(mx, c[i]);
      }
      cout << mx << endl;
      vvi ans(mx + 1, vi(n, 0));
      vi curr(mx + 1, 1);
      
      FL(i, 0, n){
        int in = 0;
        FL(j, 0, n){
          if (adj[i][j] == 1){
            while ((ans[in][i] != 0 || ans[in][j] != 0)){
              in++;
              in %= mx;
            }
            ans[in][i] = curr[in];
            ans[in][j] = curr[in];
            curr[in]++;
            adj[i][j] = 0;
            adj[j][i] = 0;
            in++;
          }
        }
      }
      FL(i, 0, mx){
        FL(j, 0, n){
          if (ans[i][j] == 0){
            ans[i][j] = curr[i];
            curr[i]++;
          }
          cout << ans[i][j] << " \n"[j==n-1];
        }
      }
      
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

