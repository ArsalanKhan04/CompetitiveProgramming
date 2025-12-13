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

    int n, m, q;
    cin >> n >> m >> q;
    vll a(n);
    vll b(m);
    ll t_a = 0, t_b = 0;
    FL(i, 0, n){
      cin >> a[i];
      t_a  += a[i];
    }
    FL(i, 0, m){
      cin >> b[i];
      t_b  += b[i];
    }

    sort(ALL(a));
    a.erase(unique(ALL(a)), a.end());

    sort(ALL(b));
    b.erase(unique(ALL(b)), b.end());

    n = a.size();

    vvll a_x(200001, vll());
    FL(i, 0, n){
      if (t_a - a[i] == 0) continue;
      ll curr = abs(t_a - a[i]);
      while (curr < 200001){
        a_x[curr].pb(t_a-a[i]);
        curr += abs(t_a - a[i]);
      }
    }
    set<ll> b_x;
    FL(i, 0, m){
      b_x.insert(t_b - b[i]);
    }
    
    dbg("Here");
    ll x;
    while (q--){
      cin >> x;
      bool flag = false;
      vll c_a_x = a_x[abs(x)];
      for (ll each: c_a_x){
        if (b_x.find(x / each) != b_x.end()){
          flag = true;
          break;
        }
      }
      condprt(flag);
    }

    
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

