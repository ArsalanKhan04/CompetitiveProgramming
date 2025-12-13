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
      vll a(n);
      FL(i, 0, n)
        cin >> a[i];

      // one single, two single
      ll sm = 0;
      ll sds = 0;
      map<ll, ll> mp;
      FL(i, 0, n){
        mp[a[i]]++;
      }
      vll ods;
      for (auto [ky, vl]: mp){
        if (vl & 1){
          sm += (ll)ky * (vl-1);
          sds += vl-1;
          ods.push_back(ky);
        } else {
          sm += (ll)ky *(vl);
          sds += vl;
        }
      }
      ll mxsm = 0;
      if (sds > 2) mxsm = sm;
      if (sds == 0){
        cout << 0 << endl;
        continue;
      }
      sort(ALL(ods));
      int m = ods.size();
      dbg(sm);
      FL(i, 0, m){
        if (ods[i] < sm){
          mxsm = max(mxsm, sm + ods[i]);
        }
      }
      FL(i, 0, m - 1){
        if (ods[i+1] - ods[i] < sm){
          mxsm = max(sm + ods[i] + ods[i+1], mxsm);
        }
      }
      cout << mxsm << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

