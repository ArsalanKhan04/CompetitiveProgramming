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


int P1 = 5; int M1 = 1e9 + 9;
int P2 = 3; int M2 = 1e9 + 7;


ll power(ll x, ll pr, ll m){
  ll an = 1;
  while (pr){
    if (pr & 1) an *= x;
    an %= m;
    x *= x;
    x %= m;
    pr /= 2;
  }
  return an;
}


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
      string s;
      string t;
      cin >> s >> t;
      int n = s.size();
      vll a1(n + 1, 0);
      vll a2(n + 1, 0);
      FL(i,0,n){
        a1[i+1] = (s[i]-'0'+ 1) * power(P1, i, M1);
        a1[i+1] %= M1;
        a2[i+1] = (s[i]-'0'+1) * power(P2,i,M2);
        a2[i+1] %= M2;
      }
      vll c1 = a1;
      vll c2 = a2;
      FL(i,1,n+1){
        c1[i] += c1[i-1];
        c1[i] %= M1;
        c2[i] += c2[i-1];
        c2[i] %= M2;
      }
      dbg(c1[n], c2[n]);
      pair<ll, ll> ht = {0, 0};
      FL(i,0,n){
        ht.F += (t[i]-'0'+1)*power(P1,i,M1);
        ht.S += (t[i]-'0'+1)*power(P2,i,M2);
        ht.F%=M1;
        ht.S%=M2;
      }
      dbg(ht.F, ht.S);
      int an = -1;
      FL(i,0,n){
        pair<ll, ll> ht2 = {0, 0};
        ht2.F += ((((c1[n] - c1[i] + M1) % M1) * power(power(P1,i,M1), M1-2, M1)) % M1
            + (c1[i] * power(P1, n-i, M1)) % M1) % M1;
        ht2.S += ((((c2[n] - c2[i] + M2) % M2)  * power(power(P2,i,M2), M2-2, M2)) % M2
            + (c2[i] * power(P2, n-i, M2)) % M2) % M2;
        ht2.F %= M1;
        ht2.S %= M2;
        if (ht2.F == ht.F && ht2.S == ht.S){
          an = i;
          break;
        }
      }
      cout << an << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

