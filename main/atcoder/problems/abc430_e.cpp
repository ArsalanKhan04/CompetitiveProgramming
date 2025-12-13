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

int power(int n, int pr, int md){
  ll sol = 1;
  ll x = n;
  while (pr){
    if (pr & 1) sol *= x;
    x *= x; x %= md;
    sol %= md;
    pr /= 2;
  }
  return sol;
}


const int P1 = 3, M1 = 1e9+9;
const int P2 = 5, M2 = 1e9+7;

struct rolling_hash{

  
};

// initialize it for A and B
// B c[n]
// prefix sums

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
      string s, t;
      cin >> s >> t;
      int n = s.size();
      s = s + s;
      ll hsh1 = 0;
      ll hsh2 = 0;
      FL(i,0,n){
        hsh1 += power(P1, i, M1) * (t[i]-'0'+1);
        hsh1 %= M1;
        hsh2 += power(P2, i, M2) * (t[i]-'0'+1);
        hsh2 %= M2;
      }
      vll c1(2*n + 1, 0);
      vll c2 = c1;
      FL(i,0,2*n){
        c1[i+1] = power(P1, i, M1) * (s[i]-'0'+1);
        c1[i+1] %= M1;
        c1[i+1] += c1[i];
        c1[i+1] %= M1;
        c2[i+1] = power(P2, i, M2) * (s[i]-'0'+1);
        c2[i+1] %= M2;
        c2[i+1] += c2[i];
        c2[i+1] %= M2;
      }

      int ans = -1;
      FL(i, 0, n+1){
        ll vl1 = c1[i+n] - c1[i] + M1;
        ll vl2 = c2[i+n] - c2[i] + M1;
        vl1 %= M1;
        vl1 *= power(power(P1, i, M1), M1-2, M1);
        vl1 %= M1;
        if (vl1 == hsh1 && vl2 == hsh2){
          ans = i;
          break;
        }
      }
      cout << ans << endl;


      dbg(hsh1);
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

