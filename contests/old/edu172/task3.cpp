
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


ll calc_score(string s, int parts, int n){
  //dbg(parts);
  ll scr = 0;
  ll val = 0;
  ll cnt = 0;
  ll x = 0;
  while (parts > 0){
    if (s[x] == '0'){
      cnt--;
    } else {
      scr += val * cnt;
      val++;
      cnt = 1;
      parts--;
    }
    x++;
  }
  while (x < n){
    if (s[x++] == '0') cnt--; else cnt++;
  }
  scr += val * cnt;
  //dbg(scr);
  return scr;
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
    cin >> testcases;
    while(testcases--){
      ll n, m;
      cin >> n >> m;
      string s;
      cin >> s;
      int zrs = 0; int ons = 0;
      FL(i, 1, n) if (s[i] == '0') zrs++; else ons++;
      vi x(n);
      int curr = ons - zrs;
      dbg(curr);
      x[0] = -INF;
      FL(i, 1, n){
        x[i] = curr;
        if (s[i] == '0'){
          curr++;
        } else {
          curr--;
        }
      }
      sort(RALL(x));
      int tot = 0;
      int y;
      FL(i, 0, n - 1){
        cerr << x[i] << " ";
      }
      FL(i, 0, n - 1){
        tot += x[i];
        if (tot >= m || x[i] <= 0){
          y = i;
          break;
        }
      }
      cerr << endl;
      if (tot >= m){
        cout << y + 2 << endl;
      } else {
        cout << -1 << endl;
      }

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

