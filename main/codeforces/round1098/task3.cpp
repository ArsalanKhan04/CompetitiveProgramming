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
      string a; int n;
      cin >> a >> n;
      vll d(n); FL(i,0,n) cin >> d[i];
      vi df(10); FL(i,0,n) df[d[i]]=true;

      auto pwr=[](ll nm, ll pw){
        ll an = 1;
        FL(i,0,pw) an*=nm;
        return an;
      };
        
      ll lrg = 0, sml = 0;
      FL(i,0,a.size()){
        lrg=(lrg*10)+(ll)d.back();
        sml=sml*10+d.front();
      }
      ll aa = stoll(a);
      ll an = min(abs(aa-lrg), abs(aa-sml));
      ll bb = 0;
      if (a.size() > 1){
        an = min(an, abs(aa-(lrg/10)));
      }
      FL(j,0,n){
        an = min(an, abs(aa-(ll)(sml+d[j]*pwr(10, a.size()))));
      }
      FL(i,0,a.size()){
        ll pos = a.size()-i-1;
        ll c = a[i]-'0';
        sml/=10; lrg/=10;
        
        FL(j,0,n){
          bb += (ll)d[j] * (pwr(10LL, pos));
          an = min(an, abs(aa-(bb+sml)));
          an = min(an, abs(aa-(bb+lrg)));
          bb -= (ll)d[j] * (pwr(10LL, pos));
        }
        if (!df[c]){
          break;
        }
        bb += (ll)c * (pwr(10LL, pos));
      }
      dbg(aa-an, aa+an);
      cout << an << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

