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
    int x = 8;
    while(TCS--){
      dbg(TCS);
      ll l, r;
      cin >> l >> r;
      map<int, int> mp;
      auto f = [&](auto &&slf, ll lvl, ll rvl)->void{
        dbg(lvl, rvl);
        if (lvl == rvl) {
          mp[lvl] = rvl;
          return;
        }
        ll mvl = lvl ^ rvl;
        int pos = 31 - __builtin_clz(mvl);
        dbg(pos);
        ll msk = (1LL << (pos + 1));
        msk--;
        // msk = msk | lvl;
        ll rm = (~msk) & lvl;
        lvl = lvl & msk;
        rvl = rvl & msk;
        dbg(msk);
        if (msk - lvl < rvl){
          slf(slf, rm | (msk-lvl+1), rm | rvl);
        } if (msk - rvl > lvl){
          slf(slf, rm | lvl, rm | (msk-rvl-1));
        }
        for (ll cvl = lvl; cvl <= rvl; cvl++){
          if (msk-cvl <= rvl && msk-cvl >= lvl){
            mp[rm | cvl]= rm | (msk-cvl);
          }
        }
      };
      f(f, l, r);
      ll sm = 0;
      for (auto [lm, rm]: mp){
        sm += lm | rm;
      }
      cout << sm << endl;
      for (auto [lm, rm]: mp){
        cout << rm << " ";
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

