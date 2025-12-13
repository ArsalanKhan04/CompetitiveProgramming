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


  int TCS = 1;
  cin >> TCS;
  while(TCS--){
    map<pii, int> dp;
    auto ask = [&](int lf, int rg){
      if (dp.find({lf, rg}) != dp.end()){
        return dp[{lf, rg}];
      }
      int x;
      cout << "? " << lf << " " << rg << endl;
      cout.flush();
      cin >> x;
      if (x < 0) exit(0);
      return dp[{lf, rg}] = x;
    };
    int n, q;
    cin >> n >> q;
    int li, ri;
    vpii a;
    FL(i,0,q){
      cin >> li >> ri;
      a.pb({li, ri});
    }
    sort(ALL(a), [](pii x, pii y){
        if (x.F == y.F){
          return x.S > y.S;
        }
        return x.F < y.F;
      });
    vpii b;
    FL(i,0,q){
      if (b.empty() || b.back().S < a[i].S){
        b.push_back(a[i]);
      }
    }

    int lw = 1;
    int hg = n;
    int x;
    while (lw <= hg){
      int md = lw + (hg - lw) / 2;
      x = ask(lw, md);
      if (x == 0) lw = md + 1;
      else hg = md - 1;
    }
    hg = lw;
    // hg is 0
    vpii c;
    for (auto bp: b){
      if (hg >= bp.F && bp.S >= hg){
        c.push_back(bp);
      }
    }

    int mx = 0;
    for (auto cp: c){
      x = ask(cp.F, cp.S);
      mx = max(mx, x);
    }
    cout << "! " << mx << endl;
    cout.flush();
  }
}

