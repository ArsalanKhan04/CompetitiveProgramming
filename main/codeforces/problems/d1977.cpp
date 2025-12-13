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


constexpr int P1 = 53;
constexpr int P2 = 43;

constexpr int M1 = 1e9 + 7;
constexpr int M2 = 1e9 + 9;


ll pow(ll x, int pw, ll md){
  ll y = 1;
  while (pw){
    if (pw & 1){
      y *= x;
      y %= md;
    }
    pw >>= 1;
    x = x * x;
    x %= md;
  }
  return y;
}

const int mxx = 3 * 1e5 + 1;
vll p1m1(mxx);
vll p2m2(mxx);


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

    FL(i, 0, mxx){
      p1m1[i] = pow(P1, i, M1);
      p2m2[i] = pow(P2, i, M2);
    }

    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int n, m;
      cin >> n >> m;
      vvi a(n, vi(m));
      string s;
      FL(i, 0, n){
        cin >> s;
        FL(j,0,m) a[i][j] = s[j]-'0';
      }
      vvll hsh1(n, vll(m));
      vvll hsh2(n, vll(m));
      vll hsh1sm(m, 0);
      vll hsh2sm(m, 0);
      vector<string> anstr(m, "");
      FL(i, 0, n){
        FL(j, 0, m){

          anstr[j] += (a[i][j] + '0');
          hsh1[i][j] = a[i][j] * p1m1[i];
          hsh1[i][j] %= M1;
          hsh2[i][j] = a[i][j] * p2m2[i];
          hsh2[i][j] %= M2;
          hsh1sm[j] += hsh1[i][j];
          hsh2sm[j] += hsh2[i][j];
          hsh1sm[j] %= M1;
          hsh2sm[j] %= M2;
        }
      }
      map<pair<int, int>, int> cnt;
      int ans = 0;
      string ans_str;
      FL(i, 0, n){
        FL(j, 0, m){
          ll h1vl = 0, h2vl = 0;
          if (a[i][j]){
            h1vl = M1 - p1m1[i];
            h2vl = M2 - p2m2[i];
          } else {
            h1vl = p1m1[i];
            h2vl = p2m2[i];
          }
          h1vl += hsh1sm[j];
          h2vl += hsh2sm[j];
          h1vl %= M1;
          h2vl %= M2;
          cnt[{h1vl, h2vl}]++;
          ll crcnt = cnt[{h1vl, h2vl}];
          if (crcnt > ans){
            string crstr = anstr[j];
            if (a[i][j]){
              crstr[i] = '0';
            } else {
              crstr[i] = '1';
            }
            ans = crcnt;
            ans_str = crstr;
          }
        }
      }
      cout << ans << endl;
      cout << ans_str << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

