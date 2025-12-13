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
      int n, m;
        cin >> n >> m;
      vvi a(n, vi(m));
      string s;
      FL(i, 0, n){
        cin >> s;
        FL(j, 0, m){
          a[i][j] = s[j] - '0';
        }
      }
      int lys = min(m, n) / 2;
      vector<vector<int>> vals(lys);
      FL(x, 0, lys){
        FL(j, x, m - x){
          vals[x].pb(a[x][j]);
        }
        FL(i, x + 1, n - x - 1){
          vals[x].pb(a[i][m-x-1]); 
        }
        FF(j, m - x - 1, x - 1){
          vals[x].pb(a[n-x-1][j]); 
        }
        FF(i, n - x - 2, x){
          vals[x].pb(a[i][x]); 
        }
      }
      ll cnt = 0;
      FL(x, 0, lys){
        int cc=vals[x].size();
        FL(j, 0, vals[x].size()){
          if (vals[x][j] == 1 && vals[x][(j+1)%cc]==5 && vals[x][(j+2)%cc]==4 && vals[x][(j+3)%cc]==3){
            cnt++;
          }
        }
      }
      cout << cnt << endl;
      /*
      vi prev(10, -1);
      prev[5] = 1;
      prev[4] = 5;
      prev[3] = 4;
      prev[1] = 0;
      int cnt = 0;
      FL(x, 0, lys){
        int curr = 0;
        int cn = 0;
        while (!vals[x].empty()){
          cerr << vals[x].front();
          if (curr == prev[vals[x].front()])
            curr = vals[x].front();
          else
            curr = 0;
          if (cn < 3){
            vals[x].pb(vals[x].front());
            cn++;
          }
          vals[x].pop_front();
          if (curr == 3)
            cnt++;
        }
        cerr << endl;
        dbg(cnt);
      }
      cout << cnt << endl;
      */

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

