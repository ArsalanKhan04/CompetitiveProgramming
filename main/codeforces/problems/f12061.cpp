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
      string s, t;
      cin >> s >> t;
      int n = s.size();
      s = "$" + s; t = "$" + t;
      deque<pii> adq, bdq;
      FL(i, 1, n + 1){
        if (s[i] != s[i-1]){
          adq.push_back({s[i] - '0', 1});
        } else {
          adq.back().S++;
        } 
        if (t[i] != t[i-1]){
          bdq.push_back({t[i] - '0', 1});
        } else {
          bdq.back().S++;
        } 
      }
      bool flag = true;
      int ans = 0;
      while (!bdq.empty()){
        pii curr = bdq.front();
        bdq.pop_front();
        int ax[2] = {0, 0};
        int cnt = 0;
        while (!adq.empty() && ax[curr.F] < curr.S){
          ax[adq.front().F] += adq.front().S;
          adq.pop_front(); 
          cnt++;
        }
        if (ax[curr.F] != curr.S) {
          flag = false;
          break;
        }
        dbg(cnt);
        if (adq.empty()){
          adq.push_front({!curr.F, ax[!curr.F]});
        } else {
          adq.front().S += ax[!curr.F];
        }
        ans += cnt / 2;
      }
      if (flag){
        cout << ans << endl;
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

