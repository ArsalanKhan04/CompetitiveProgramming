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
      int n, k;
      int L, R;
      cin >> n >> k;
      cin >> L >> R;
      vi a(n);
      FL(i, 0, n)
        cin >> a[i];
      int l = 0, r = 0;
      int prv = 0, nxt = 0;
      map<int, int> mp;
      ll ans = 0;
      int rx[2] = {0, 0};
      FL(i, 0, n){
        while (rx[0] < n && mp.size() < k){
          mp[a[rx[0]++]]++;
        }
        while (rx[1] < n && mp.find(a[rx[1]]) != mp.end()){
          rx[1]++;
        }
        if (mp.size() < k) break;
        ll can = 0;
        int itrm = max(min(rx[1]-i, R), L);
        int rtrm = max(min(rx[0]-i, R), L);
        dbg(i, itrm, rtrm);
        dbg(i, rx[0], rx[1], can);
        if (!(rx[0] - i > R || rx[1] - i < L)) {
          can += itrm - rtrm + 1;
          dbg(can);
        }
        // ans += max(min(r-(i-prv), R), L) - min(max(r-i, L), R)+1;
        ans += can;
        mp[a[i]]--;
        if (mp[a[i]] == 0){
          mp.erase(a[i]);
        }
      }
      cout << ans << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

