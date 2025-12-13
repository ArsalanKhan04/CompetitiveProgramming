#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int
#define MOD % 1000000007
#define FL(i, a, b) for (int i = a; i < b; i++)
#define FE(i, a, b) for (int i = a; i <= b; i++)
#define FF(i, a, b) for (int i = a; i > b; i--)
#define FFE(i, a, b) for (int i = a; i >= b; i--)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
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

#define REMAX(a, b) a = max((a), (b))
#define REMIN(a, b) a = min((a), (b))

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define INF int(1e9) + 9
 
#define endl '\n'
 
#define condprt(x) cout << ((x) ? "YES" : "NO") << endl



vll Fac(1, 1);
vll Inv(1, 1);

ll pow(ll a, ll b, ll m){
  if (b == 0)
    return 1;
  ll ans = pow(a, b/2, m);
  ans *= ans;
  ans %= m;
  if (b & 1)
    ans *= a;
  ans %= m;
  return ans;
}

ll inverse(ll a, ll m){
  return pow(a, m-2, m);  
}


ll fac(ll a, ll m){
  while (a >= Fac.size()){
    Fac.pb((Fac.back() * Fac.size()) % m);
    Inv.pb(inverse(Fac.back(), m));
  }
  return Fac[a];
}

ll comb(ll n, ll r, ll m){
  if (r < 0 || r > n)
    return 0;

  while ((int) Fac.size() < n + 1){
    Fac.pb((Fac.back() * (int) Fac.size()) % m);
    Inv.pb(inverse(Fac.back(), m));
  }
  return (Fac[n] * ((Inv[r] * Inv[n-r]) % m)) % m;
}

ll combs(ll n1, ll n2, ll r, ll m){
  if (n1 > n2)
    swap(n1, n2);
  ll r1, r2;
  r1 = max((ll) 0, r - n2 + 1);
  ll combs = 0;
  FL(i, r1, min(n1, r + 1)){
    r2 = r - i;
    combs += comb(n1, i, m) * comb(n2, r2, m);
  }
  return combs;
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

    int testcases = 1;
    while(testcases--){
      ll n, p;
      cin >> n >> p;
      ll ans = 0;
      if (n & 1){
        ll x = n / 2;
        ll y = (n + 1) / 2;
        ll lft, rgt, cmbs, st, curr;
        FL(i, 1, x + 1){
          curr = cmbs = 0;
          rgt = i;
          lft = y - i;
          st = x - 1;
          while (st < n - 2){
            curr += (combs(lft, rgt, st - x + 1, p) * fac(st, p)) % p;
            st++;
          }
          ans += curr;
          ans %= p;
        }
      } else {


      }
      cout << (ans * n) % p << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

