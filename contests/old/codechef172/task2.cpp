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
      int q; cin >> q;
      int p, x;
      set <int> s1;
      set <int> s2;
      FL(i, 0, n){
        if ((i & 1) && a[i] == 0){
          s2.insert(i);
        }
        if (!(i&1) && a[i]){
          s1.insert(i);
        }
      }
      while (q--){
        cin >> p >> x;
        p--;
        if (p&1){
          if (s2.find(p) != s2.end()){
            s2.erase(p);
          }
          if (!x){
            s2.insert(p);
          }
        }
        if (!(p&1)){
          if (s1.find(p) != s1.end()){
            s1.erase(p);
          }
          if (x){
            s1.insert(p);
          }
        }
        if (s1.empty()){
          cout << 0 << endl;
          continue;
        }
        if (s2.empty()){
          cout << 1 << endl;
          continue;
        }
        auto itr1 = s1.end();
        auto itr2 = s2.end();
        itr1--;
        itr2--;
        if (*itr1 > *itr2){
          cout << 1 << endl;
        } else {
          cout << 0 << endl;
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

