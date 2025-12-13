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
      int n;
      cin >> n;
      vi a(n);
      FL(i, 0, n)
        cin >> a[i];
      vector<vvi> alls(4, vvi(n));
      map<int, int> cnt_m;
      FL(i, 0, n){
        vi nms;
        FL(j, 0, 31){
          if (a[i] & (1 << j)){
            nms.pb((1 << j));
          }
        }
        FL(x, 0, nms.size()){
          cnt_m[nms[x]]++;
          alls[0][i].pb(nms[x]);
          FL(y, x + 1, nms.size()){
            cnt_m[nms[x]|nms[y]]++;
            alls[1][i].pb(nms[x]|nms[y]);
            FL(z, y + 1, nms.size()){
              cnt_m[nms[x]|nms[y]|nms[z]]++;
              alls[2][i].pb(nms[x]|nms[y]|nms[z]);
              FL(u, z + 1, nms.size()){
                cnt_m[nms[x]|nms[y]|nms[z]|nms[u]]++;
                alls[3][i].pb(nms[x]|nms[y]|nms[z]|nms[u]);
              }
            }
          }
        }
      }
      ll mul2 = 0;
      ll mul1 = 0;
      FL(i, 0, n){
        ll curr_ans = 0;
        FL(j, 0, 4){
          for (int x: alls[j][i]){
            cnt_m[x]--;
            curr_ans +=(int) pow(-1, j) * cnt_m[x];
          }
        }
        mul2 += curr_ans;
        mul1 += n - i - 1 - curr_ans;
      }
      cout << mul1 + 2 * mul2 << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

