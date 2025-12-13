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
      string s;
      cin >> s;
      s = "%" + s;
      vi cs(n + 1, 0);
      FL(i, 1, n + 1){
        if (i & 1){
          cs[i] = (s[i] == '1');
        } else {
          cs[i] = (s[i] == '1') * 2;
        }
        cs[i] += cs[i-1];
      }

      auto cb = [&](int l, int r)->int{
        int sz = cs[r] - cs[l-1] + 3 * (r - l + 1);
        if (sz == 0) return 0;
        if ((l & 1) ^ ((r - l + 1) & 1)){
          return (((sz+2)%3)+3)%3;
          if (sz & 1){
            return 1;
          } else {
            return 2;
          }
        } else {
          return ((sz % 3)+3)%3;
        }
      };

      int l, r;
      int ons = 0;
      int tos = 0;
      int ods = 0;
      while (q--){
        cin >> l >> r;
        if ((r - l + 1) & 1){
          ods++;
        }
        if (cb(l, r) == 2){
          tos++;
        } else if (cb(l, r) == 1){
          ons++;
        }
        dbg(l, r, ons, tos, ods);
        int diff = tos * 2 + ons;
        if (tos + ons == 1){
          cout << "NO" << endl;
        } else {
          if (ods || (diff %3 == 0)){
            cout << "YES" << endl;
          } else {
            cout << "NO" << endl;
          }
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

