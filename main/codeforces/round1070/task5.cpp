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
      vi a(n+1), c(n+1), p(n+1);
      FL(i, 1, n+1)
        cin >> a[i];
      FL(i,1,n+1) cin >> c[i];
      FL(i,1,n+1) cin >> p[i];

      vi cs_int(n+1, -1);
      set<pii> cst_ind;
      FL(i,1,n+1){
        cst_ind.insert({c[i], i});
      }
      for (auto [cst, ind]: cst_ind){
        if (cs_int[ind]!=-1) continue;
        int vl = a[ind];
        for (int i = ind; i < n+1; i++){
          if (cs_int[i]!=-1) break;
          if (a[i] <= vl){
            cs_int[i] = cst;
          } else {
            break;
          }
        }
        for (int i = ind - 1; i > 0; i--){
          if (cs_int[i]!=-1) break;
          if (a[i] <= vl){
            cs_int[i] = cst;
          } else {
            break;
          }
        }
      }
      priority_queue<pair<int, int>> pq;
      FL(i,1,n+1){
        pq.push({cs_int[i], i});
      }
      ll an = 0;
      FL(i,1,n+1){
        an += cs_int[i];
      }
      cout << an - pq.top().F << " ";

      vi prv0(n+1);
      vi nxt0(n+1);
      FL(i,1,n+1) {
        prv0[i] = i;
        nxt0[i] = i;
      }

      vb zrdn(n+1, false);
      set<pair<int, int>> zr_int;
      set<pair<int, int>> zr_rv;

      set<pair<int, int>> pq_rm;
      FL(i,1,n+1){
        // new zr is p[i] 
        int ind = p[i];
        int st = ind, ed = ind;
        int vl = a[ind];
        int cst = 0;
        int j = ind;
        int lf = ind - 1;
        while (j < n + 1){
          if (zrdn[j]){
            // dbg(zr_int.size());
            //dbg(j);
            auto itr = zr_int.lower_bound({j, -1}); // will now show itr for the range
            if (itr == zr_int.end() || (*itr).F > j) itr--;
            pii rng = *itr;
            // dbg(rng.F, rng.S);
            zr_int.erase(rng);
            zr_rv.erase({-1*rng.S, -1*rng.F});
            lf = min(lf, rng.F-1);
            j = rng.S;
          } else if (a[j] <= vl) {
            pq_rm.insert({cs_int[j], j});
            an -= cs_int[j];
            cs_int[j] = 0;
            zrdn[j] = true;
          } else {
            break;
          }
          j++;
        }
        ed = j - 1;
        j = lf;
        while (j > 0){
          if (zrdn[j]){
            auto itr = zr_rv.lower_bound({-1*j, -1e9}); // will now show itr for the range
            pii rng = *itr;
            zr_rv.erase(rng);
            zr_int.erase({-1*rng.S, -1*rng.F});
            // dbg(rng.F, rng.S);
            j = -1*rng.S;
          } else if (a[j] <= vl) {
            pq_rm.insert({cs_int[j], j});
            an -= cs_int[j];
            cs_int[j] = 0;
            zrdn[j] = true;
          } else {
            break;
          }
          j--;
        }
        st = j + 1;
        zr_int.insert({st, ed});
        zr_rv.insert({-1*ed, -1*st});

        while (!pq.empty() && pq_rm.find(pq.top()) != pq_rm.end()){
          pq.pop();
        }
        if (pq.empty()){
          cout << an << " ";
        } else {
          cout << an - pq.top().F << " ";
        }
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

