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
      int n; cin >> n;
      vi v(n), p(n);
      map<pair<int, int>, int> mp;
      FL(i,0,n) cin>>v[i],cin>>p[i];
      vi vs=v, ps=p;
      sort(ALL(vs)), sort(ALL(ps));
      vs.erase(unique(ALL(vs)), vs.end());
      ps.erase(unique(ALL(ps)), ps.end());
      int V = vs.size(); int P = ps.size();
      int N = V + P;
      vector<set<int>> to(N);
      FL(i, 0, n){
        int vv = lower_bound(ALL(vs), v[i]) - vs.begin();
        int pp = lower_bound(ALL(ps), p[i]) - ps.begin() + V;
        mp[{vv, pp}] = i + 1;
        to[vv].insert(pp);
        to[pp].insert(vv);
      }
      // from each graph point
      int ods = 0;
      int odi = 0;
      FL(i, 0, N){
        if (to[i].size() & 1) ods++, odi=i;
      }
      // need to connect two od values together?
      vi ans;
      stack<int> st;
      st.push(odi);
      while (!st.empty()){
        if (to[st.top()].empty()){
          ans.push_back(st.top());
          st.pop();
        } else {
          int nxt = *to[st.top()].begin();
          to[st.top()].erase(nxt);
          to[nxt].erase(st.top());
          st.push(nxt);
        }
      }
      if ((ods != 2 && ods != 0) || ans.size() != n + 1){
        cout << "NO" << endl;
        continue;
      }
      vi aaa;
      cout << "YES" << endl;
      FL(i, 0, n){
        int a = ans[i], b=ans[i+1];
        if (a > b) swap(a, b);
        dbg(a, b);
        aaa.pb(mp[{a, b}]);
      }
      FL(i, 0, n){
        cout << aaa[i] << " ";
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

