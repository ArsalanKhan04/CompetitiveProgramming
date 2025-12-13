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
      vi a(n);
      FL(i, 0, n)
        cin >> a[i];

      auto f = [&](int v, int& x, int& y)->bool{
        vi b(n);
        FL(i, 0, n){
          if (a[i] >= v){
            b[i] = 1;
          } else {
            b[i] = -1;
          }
        }
        FL(i, 1, n){
          b[i]+=b[i-1];
        }
        set<pair<int, int>> st;
        st.insert({0, -1});
        int l = 0;
        int r = k - 1;
        while (r < n){
          if (b[r] - (*st.begin()).F >= 0){
            x = (*st.begin()).S + 1;
            y = r;
            return true;
          }
          st.insert({b[l], l});
          l++;
          r++;
        }
        return false;
      };


      int lw = 1;
      int hg = n;
      int x, y;
      while (lw <= hg){
        int md = lw + (hg - lw) / 2;
        if (f(md, x, y)){
          lw = md + 1;
        } else {
          hg = md - 1;
        }
      }
      f(hg, x, y);
      cout << hg << " " << x + 1 << " " << y + 1 << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

