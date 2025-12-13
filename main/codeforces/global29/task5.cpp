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
    cin >> TCS;
    while(TCS--){
      ll n, q;
      cin >> n >> q;
      vll a(n);
      FL(i, 0, n)
        cin >> a[i];
      // for each a_i check the ones that can make the xth bit easily
      // for 32 values for all 32 bits
      // and so on
      //

      vvll ad(31, vll());
      FL(bti, 0, 31){
        vll b = a;
        FFE(btj, bti, 0){
          ll cr = ((ll)1 << (btj + 1)) - 1;
          FL(i, 0, n){
            b[i] = b[i] & cr;
          }
          sort(ALL(b));
          int sx;
          FL(i, 0, n){
            sx = i;
            if (b[i] >= ((ll)1 << btj)){
              break;
            }
          }
          // dbg(sx, b[sx], btj, cr);
          ad[bti].pb(max(((ll)1<<btj)-b[sx], (ll)0));
          if (b[sx] >= ((ll)1 << btj)){
            b[sx]-=((ll)1<<btj);
          } else{
            b[sx]=0;
          }
        }
      }
      vll hm(31,0);
      FL(i, 0, 31){
        FL(j, 0, i+1){
          //cerr << ad[i][j] << " ";
          hm[i] += ad[i][j];
        }
        // cerr << endl;
      }

      ll nvl = 0;
      FL(i, 0, n){
        nvl = nvl | a[i];
      }
      ll bx;
      FL(i, 0, q){
        ll vl = nvl;
        cin >> bx;
        FFE(j, 30, 0){
          if (hm[j] <= bx){
            vl = vl | (((ll)1 << (j+1)) - 1);
            break;
          }
        }
        cout << __builtin_popcount(vl) << endl;
      }
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

