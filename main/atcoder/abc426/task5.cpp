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
      double t[4];
      double s[4];
      FL(i,0,4)cin>>t[i];
      FL(i,0,4)cin>>s[i];
      
      double dt = sqrt(pow(s[3]-s[1], 2) + pow(s[2]-s[0], 2));
      double ds = sqrt(pow(t[3]-t[1], 2) + pow(t[2]-t[0],2));
      dbg(ds, dt);

      double lw = 0;
      double hg = max(dt,ds);

      auto f = [&](double x){
        double ts[2];
        double ss[2];
        if (x < dt){
          ts[0] = t[0] + ((t[2]-t[0])/dt)*x;
          ts[1] = t[1] + ((t[3]-t[1])/dt)*x;
        } else {
          ts[0] = t[2];
          ts[1] = t[3];
        }
        if (x < ds){
          ss[0] = s[0] + ((s[2]-s[0])/ds)*x;
          ss[1] = s[1] + ((s[3]-s[1])/ds)*x;
        } else {
          ss[0] = s[2];
          ss[1] = s[3];
        }
        dbg(ts[0], ts[1], ss[0], ss[1]);
        return sqrt(pow(ts[1]-ss[1], 2) + pow(ts[0]-ss[0],2));
      };
      for (float i = lw; i < hg; i+=0.01){
        dbg(i, f(i));
      }

      cerr<<setprecision(10);

      while (lw < hg){
        float md1 = lw + (hg-lw)/3;
        float md2 = lw + ((hg-lw)*2)/3;
        float dm1 = f(md1);
        float dm2 = f(md2);
        dbg(dm1, dm2, md1, md2);
        if (dm1 < dm2){
          hg = md2;
        } else {
          lw = md1;
        }
        dbg(lw, hg);
        if (abs(dm1-dm2) < (1e-7)) break;
      }
      cout << setprecision(10) << f(lw) << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

