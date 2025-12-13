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
      string st = "SFH";
      vvi a(3, vi(3));
      ll total = 0;
      FL(i, 0, 3){
        FL(j, 0, 3){
          cin >> a[i][(j) % 3];
          total += a[i][(j) % 3];
          // cin >> a[i][(j + 2) % 3];
          // total += a[i][(j + 2) % 3];
        }
      }
      ll ans = 1000000;
      vi prev(3, false);
      int a1, a2, a3;
      FL(i, 0, 3){
        prev[i] = true;
        FL(j, 0, 3){
          if (prev[j] == true)
            continue;
          prev[j] = true;
          FL(k, 0, 3){
            if (prev[k] == true)
              continue;
            total-=a[0][i];
            total-=a[1][j];
            total-=a[2][k];
            if (total < ans){
              ans = total;
              a1 = i;
              a2 = j;
              a3 = k;
            } else if (total == ans){
              if (i < a1){
                a1 = i;
                a2 = j;
                a3 = k;
              } else if (i == a1 && j < a2){
                a1 = i;
                a2 = j;
                a3 = k;
              }
            }
            total+=a[0][i];
            total+=a[1][j];
            total+=a[2][k];
          }
          prev[j] = false;
        }
        prev[i] = false;
      }
      cout << st[a1] << st[a2] << st[a3] << " ";
      cout << ans << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

