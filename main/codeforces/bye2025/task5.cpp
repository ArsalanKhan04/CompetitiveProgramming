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
      ll sm;
      cout << "? " << 1 << " " << n << endl;
      cout.flush();
      cin >> sm;
      if (sm == -1) exit(0);


      ll x;
      auto part = [&](int l, int h, ll csm){
        ll hsm = csm;
        int lg = l;
        int hg = h;
        while (lg <= hg){
          int md = lg + (hg - lg) / 2;
          cout << "? " << l << " " << md << endl;
          cout.flush();
          cin >> x;
          if (x == -1) exit(0);
          if (x < hsm){
            lg = md + 1;
          } else if (x == hsm) {
            return md;
          } else {
            hg = md - 1;
          }
        }
        return lg;
      };

      int l = 1, h = n;
      ll nsm = sm;
      while (l < h){
        nsm/=2;
        int pt = part(l, h, nsm);
        // cout << "PART FOUND AT: " << pt << endl;
        if (pt - l < h - pt){
          h = pt;
        } else {
          l = pt + 1;
        }
      }

      cout << "! " << nsm << endl;
      cout.flush();
        

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

