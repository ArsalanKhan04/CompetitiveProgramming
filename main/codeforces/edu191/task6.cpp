#include <algorithm>
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
    // cin >> TCS;
    while(TCS--){
      int n = 7;
      int lines = ceil(log2(n+1));

      vvi a(n+1, vi(lines, 0));
      FL(i,0,n+1){
        FL(j,0,lines){
          a[i][j] = (i & (1 << j)) > 0;
        }
      }

      vi c(lines);
      iota(ALL(c), 0);

      int val_count=0; int tot_count=0;
      dbg(lines);
      dbg(10*9*8*7*6*5*4*3*2);

      while (true){
        tot_count++;
        vvi b(n+1, vi(lines));
        FL(i,0,n+1){
          FL(j,0,lines){
            b[i][c[j]] = a[i][j];
          }
        }
        vi d(n+1); vi chck(n+1); iota(ALL(chck), 0);
        FL(i,0,n+1){
          for (int j = lines-1; j>=0; j--){
            d[i] = d[i]*2+b[i][j];
          }
        }
        if (is_permutation(ALL(d), ALL(chck))){
          val_count++;
        }
        if (!next_permutation(ALL(c))) break;
      }
      
      cout << "N: " << n << " tot: " <<
        tot_count << " - val: " << val_count << endl;


      

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

