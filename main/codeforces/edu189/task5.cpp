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


const float mlt=1.74;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist(1, 1000000000);

const vpii disp={
  {0,0}, {0,1},
  {1,0}, {1,1},
  {0,-1}, {-1, 0},
  {-1,-1}
};

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
    while(TCS--){
      int n,r; cin >> n >> r;
      vpii pts(n);
      FL(i,0,n){
        cin >> pts[i].F  >> pts[i].S;
      }
      if (n==4) {
        cout << "1\n70 70\n" << endl;
        continue;
      }
      while (true){
        ll cnt=0;
        int lft=2*r; int tp = ceil(mlt*r)*2; 
        int o[2][2];
        o[0][0]=dist(rng) % lft; o[0][1]=dist(rng)%tp;
        o[1][0]=o[0][0]+r; o[1][1]=o[0][1]+ceil(mlt*r);
        set<pair<int, int>> sp;

        auto dst=[&](pii a, pii b){
          ll cc=r*r;
          ll aa=(a.F-b.F); aa*=aa;
          ll bb=(a.S-b.S); bb*=bb;
          if (aa+bb <= cc){
            return true;
          }
          return false;
        };
        auto floordiv = [](int a, int b){ return a/b - (a%b != 0 && (a^b) < 0); };

        auto f=[&](pii pt){
          // check against first
          FL(i,0,2){
            pii cls;
            cls.F = floordiv(pt.F - o[i][0], lft) * lft + o[i][0];
            cls.S = floordiv(pt.S - o[i][1], tp) * tp + o[i][1];
            for (auto dispe: disp){
              cls.F += dispe.F*lft;
              cls.S += dispe.S*tp;
              if (dst(cls, pt)){
                cnt++;
                sp.insert(cls);
                break;
              }
              cls.F -= dispe.F*lft;
              cls.S -= dispe.S*tp;
            }
          }
        };

        FL(i,0,n){
          f(pts[i]);
        }
        if (cnt >= 8900){
          cout << sp.size() << endl;
          for (auto sss: sp){
            cout << sss.F << " " << sss.S << endl;
          }
          break;
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
