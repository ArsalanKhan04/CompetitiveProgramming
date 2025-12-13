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
      string s, t;
      cin >> s >> t;
      bool fl = true;
      vector<pii> vp;
      int mx = 0;
      int r1 = n - 1;
      for (int i = n -1; i>=0;i--){
        r1 = min(r1, i);
        while (r1 >= 0 && s[r1] != t[i]) r1--;
        if (r1 < 0) {
          fl = false;
          break;
        }
        int l1 = r1;
        if (l1 < i){
          vp.push_back({l1, i});
          mx = max(mx, i-l1);
        }
      }
      if (mx > k || !fl){
        cout << -1 << endl;
        continue;
      }
      string s1 = s;
      cout << mx << endl;
      FL(i,0,mx){
        string s2 = s1;
        for (auto pr: vp){
          int lf = pr.F;
          int rg = pr.S;
          if (lf + i < rg){
            s2[lf+i+1] = s1[lf+i];
          }
        }
        if (i == mx-1) assert (s2 == t);
        cout << s2 << endl;
        s1 = s2;
      }
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

