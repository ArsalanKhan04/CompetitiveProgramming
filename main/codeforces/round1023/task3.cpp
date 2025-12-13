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
      ll n, k;
      cin >> n >> k;
      string s; cin >> s;
      vll a(n);
      FL(i, 0, n)
        cin >> a[i];

      int zrs = 0;
      FL(i, 0, n){
        if (s[i] == '0') { a[i] = -1 * 1e15;
          zrs++;
        }
      }
      
      ll tl = 0;
      ll mxt = 0;
      FL(i, 0, n){
        tl += a[i];
        if (tl < 0) tl = 0;
        mxt = max(tl, mxt);
      }
      if (mxt > k || (mxt < k && zrs == 0)){
        cout << "No" << endl;
        continue;
      } else if (mxt == k){
        cout << "Yes" << endl;
        FL(i, 0, n){
          cout << a[i] << " ";
        }
        cout << endl;
        continue;
      }
      int z = 0;
      FL(i, 0, n){
        if (s[i] == '0'){
          z = i;
          break;
        }
      }
      ll lft = 0;
      ll mxl = 0, mxr = 0;
      ll rgt = 0;
      FL(i, z + 1, n){
        rgt += a[i];
        if (rgt < -1 * 1e15) break;
        mxr = max(mxr, rgt);
      }
      for (int i = z - 1; i >= 0; i--){
        lft += a[i];
        if (lft < -1 * 1e15) break;
        mxl = max(mxl, lft);
      }
      a[z] = k - (mxr + mxl); 

      cout << "Yes" << endl;
      FL(i, 0, n){
        cout << a[i] << " ";
      }
      cout << endl;

      
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

