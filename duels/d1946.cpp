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
#define aii array<int, 2>
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
      ll n, x;
      cin >> n >> x;
      vll a(n);
      // each a_i can have a total of 30 bits
      FL(i, 0, n)
        cin >> a[i];
      // we will go in reverse direction

      set<aii> st;
      auto inst = [&](int nl, int nr){
        auto it = st.lower_bound({nl, -1});
        if (it != st.begin()){
          --it;
          if ((*it)[1] < nl) ++it;
        }

        while (it != st.end() && (*it)[0] <= nr){
          nl = min(nl, (*it)[0]);
          nr = max(nr, (*it)[1]);
          it = st.erase(it);
        }

        st.insert({nl, nr});
      };

      int ans = 1;

      int fl = 0;
      for (int ind = 30; ind >= 0; ind--){
        vi c;
        ll vl = 1 << ind;
        vi b(n);
        auto cpst = st;
        FL(i, 0, n){
          if (a[i] & vl) c.pb(i);
        }
        dbg(ind, c.size());
        if ((c.size() & 1) && (x & vl)){ // cs is odd and so is x
          // its fine we can just skip this and move on 
        } else if (c.size() & 1){ // only cs is odd
          // its no longer fine, k does not exist
          if (fl == 0){
            fl = -1;
          }
          break;
        } else if (x & vl){ // only x is odd
          // we can have one of our solution here now
          // num of inds are even so we can make this 0 and have a smaller than x value
          for (int j = 0; j < c.size(); j+=2){
            dbg(ind, c[j], c[j+1]);
            inst(c[j], c[j+1]);
            dbg(st.size());
          }
          int cr = n;
          for (auto [lft, rgt]: st){
            cr -= rgt - lft;
          };
          ans = max(ans, cr);
          st = cpst;
          fl = 1;
        } else {
          for (int j = 0; j < c.size(); j+=2){
            inst(c[j], c[j+1]);
            dbg(st.size());
          }
        }
        if (ind == 0){
          int cr = n;
          for (auto [lft, rgt]: st){
            cr -= rgt - lft;
          };
          ans = max(ans, cr);
        }
      }
      if (fl == -1){
        cout << -1 << endl;
      } else {
        cout << ans << endl;
      }
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

