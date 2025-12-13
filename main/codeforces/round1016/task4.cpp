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
    cin >> TCS;
    while(TCS--){
      int n, q;
      cin >> n >> q;
      auto getcoord = [&](ll val)->pii {
        vi vls;
        dbg(val);
        val--;
        int cc = 2*n;
        while (cc--) {
          vls.pb(val&1);
          val>>=1;
        }
        reverse(ALL(vls));
        ll tbsize = (1 << (n - 1));
        int x = 0; int y = 0;
        for (int i = 0; i < vls.size(); i += 2){
          int nm = vls[i] * 2 + vls[i+1];
          if (nm & 1){
            x += tbsize;
          } 
          if (nm == 1 || nm == 2)
            y += tbsize;
          tbsize>>=1;
        }
        return {y + 1, x + 1};
      };

      auto getval = [&](auto &&slf, int x, int y, ll cvl, ll bnd)->ll{
        vi vls;
        if (bnd == 0) return cvl;
        cvl <<= 2;
        ll adval = 0;
        ll sb1 = 0, sb2 = 0;
        if (x >= bnd && y >= bnd){
          adval = 1;
          sb1 = bnd;
          sb2 = bnd;
        } else if (x >= bnd){
          adval = 3;
          sb1 = bnd;
        } else if (y >= bnd){
          adval = 2;
          sb2 = bnd;
        }
        return slf(slf, x - sb1, y - sb2, adval+cvl, bnd/2);
      };

      while (q--){
        char c1, c2;
        cin >> c1 >> c2;
        if (c1 == '-'){
          int x, y;
          cin >> x >> y;
          x--;
          y--;
          cout << getval(getval, y, x, 0, (1<<(n-1))) + 1 << endl;
        } else {
          ll val;
          cin >> val;
          auto ans  = getcoord(val);
          cout << ans.F << " " << ans.S << endl;
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

