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
      vi b=a;
      sort(ALL(b));
      b.erase(unique(ALL(b)), b.end());
      FL(i,0,n){
        a[i]=lower_bound(ALL(b), a[i])-b.begin();
      }

      auto f=[&](int x){
        int ttl=0;
        int ple=0, pmr=0, peq=0, pcr=0;
        int le=0; int mr=0; int eq=0; int cr=0;
        FL(i,0,n){
          if (a[i]<x) le++;
          else if (a[i]>x) mr++;
          else eq++;
          cr++;
          if ((cr & 1) && le+eq>mr && mr+eq > le){
            ttl++;
            ple=le, pmr=mr, peq=eq, pcr=cr;
            le=0; mr=0; eq=0; cr=0;
          }
        }
        if (cr > 0){
          le+=ple;
          mr+=pmr;
          eq+=peq;
          cr+=pcr;
          if ((cr & 1) && le+eq>mr && mr+eq > le){
          } else return -1;
        }
        return ttl;
      };

      int mx=1;
      FL(x,0,b.size()){
        mx=max(mx, f(x));
      }
      cout << mx << endl;



    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}


