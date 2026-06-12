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
      int n, k;
      cin >> n >> k;
      if (k & 1){
        FL(i,0,k) cout << n << " ";
        cout << endl;
        continue;
      }

      int y = n;
      vi a;
      while (y){
        a.pb(y&1);
        y>>=1;
      }
      reverse(ALL(a));


      int nm1 = 0;
      int nm2 = 0;

      vector<vi> vbt(k);

      int ptr = 0; // can go till k only

      FL(i,0,a.size()){ // less than 25
        if (a[i]){
          int ptr2 = ptr;
          if (ptr >= k){
            ptr2 = 0;
          }
          vbt[ptr2].pb(0);
          FL(j,0,k) {
            if (j == ptr2) continue;
            vbt[j].pb(1);
          }
          ptr++;
        } else {
          int ptr2 = min(ptr, k);
          // this will be the number of elements done so far
          // make sure that ptr2 is even
          ptr2 -= ptr2 & 1;
          FL(j,0,ptr2){
            vbt[j].pb(1);
          }
          FL(j,ptr2,k){
            vbt[j].pb(0);
          }
        }
      }

      for (auto btm: vbt){
        int nm = 0;
        for (auto x: btm){
          nm = nm*2 + x;
        }
        cout << nm << " ";
      }
      cout << endl;


      

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

