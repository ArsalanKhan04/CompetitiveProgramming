
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

    string s;
    cin >> s;
    int n = s.size();
    vi a(n);
      
    int pos = 0;
    int mn = 0;
    int mx = 0;
    FL(i, 0, n){
      if (s[i] == 'L'){
        pos--;
      } else if (s[i] == 'R'){
        pos++;
      }
      a[i] = pos;
      REMIN(mn, pos);
      REMAX(mx, pos);
    }
    int f_i_mn = -1, f_i_mx = -1, l_i_mn, l_i_mx;
    FL(i, 0, n){
      if (a[i] == mn){
        if (f_i_mn == -1)
          f_i_mn = i;
        l_i_mn = i;
      }
      if (a[i] == mx){
        if (f_i_mx == -1)
          f_i_mx = i;
        l_i_mx = i;
      }
    }

    int qs = 0;
    int ans;
    int n_mx = mx;
    int n_mn = mn;
    FL(i, f_i_mn + 1, n){
      qs += s[i] == '?';
    }
    ans = mx - mn + qs;
    dbg(mx);
    dbg(mn);
    qs = 0;
    dbg(f_i_mx);
    dbg(l_i_mn);
    FL(i, f_i_mx + 1, n){
      qs += s[i] == '?';
    }
    dbg(qs);
    REMAX(ans, mx - mn + qs);
    cout << ans << endl;


    
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

