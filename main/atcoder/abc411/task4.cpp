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
      int n,q; cin >>n>>q;
      vector<pair<int, string>> stps;
      vector<int> typs;
      while (q--){
        int tp; cin >> tp;
        int p; string s;
        cin >> p;
        typs.pb(tp);
        if (tp == 2){
          cin >> s;
          stps.pb({p, s});
        } else if (tp == 1){
          stps.pb({p, ""});
        } else if (tp == 3){
          stps.pb({p, ""});
        }
      }

      vector<string> ans;
      bool f3 = false;
      int cr = -1;
      for(int i = typs.size() - 1; i>= 0; i--){
        if (cr == -1 && typs[i] == 3){
          cr = stps[i].F; 
        }
        if (typs[i] == 2 && cr == stps[i].F){
          ans.pb(stps[i].S);
        }
        if (typs[i] == 1 && cr == stps[i].F){
          cr = -1;
        }
      }
      string aa = "";
      for (int x = ans.size() - 1; x >= 0; x--){
        aa += ans[x];
      }
      cout << aa << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

