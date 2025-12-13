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
      int n, m, d;
      cin >> n >> m >> d;
      vector<array<int, 3>> va(m);
      int inp[3];
      vector<vvi>vx(n, vvi(n, vi()));
      FL(i,0,m) {
        cin >> inp[0] >> inp[1] >> inp[2];
        va[i] = {inp[2], inp[0], inp[1]};
      }


      int tp[3] = {0};
      auto f = [&tp](int a, int b, pii sc, pii thr){
        if (sc.F == b && thr.S == a &&
            sc.S == thr.F) tp[0]++;
        if (sc.F == a && thr.F == b &&
            sc.S == thr.S) tp[1]++;
        if (sc.S == thr.F && thr.S == a &&
            sc.S == b) tp[2]++;
      };

      sort(ALL(va));
      FL(i,0,m){
        FL(j,i+1, m){
          FL(k,j+1, m){
            if (!(va[i][0] < va[j][0] && va[j][0] < va[k][0])){
              continue;
            }
            if (va[k][0] - va[i][0] > d) continue;
            pii sc = {va[j][1], va[j][2]};
            pii thr = {va[k][1], va[k][2]};
            f(va[i][1], va[i][2], sc, thr);
          }
        }
      }
      cout << tp[0] << " " << tp[1] << " " << tp[2] << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

