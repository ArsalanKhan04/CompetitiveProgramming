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

      vvi tobg(n*n + 2), tosm(n*n + 2);

      set<int> st;
      FL(i, 1, n*n + 2){
        st.insert(i);
      }

      int x;
      FL(i, 0, n){
        cout << "? " << st.size() << " ";
        for (auto vl: st){
          cout << vl << " ";
        }
        cout << endl;
        cout.flush();
        
        cin >> x;
        if (x == -1) return 0;
        set<int> st2;
        int y;
        while (x--){
          cin >> y;
          if (y == -1) return 0;
          st2.insert(y);
        }
        while (!st2.empty()){
          int cvl = *st2.begin();
          st2.erase(cvl);
          st.erase(cvl);
          for (auto vv: st){
            if (st2.find(vv) != st2.end()){
              if (vv < cvl)
                tosm[vv].pb(cvl); // vv is bigger than cvl
              if (cvl < vv)
                tobg[cvl].pb(vv); // cvl is bigger than vv
              break;
            }
            if (cvl < vv)
              tosm[cvl].pb(vv); // cvl is bigger than vv
            if (vv < cvl)
              tobg[vv].pb(cvl); // vv is bigger than cvl
          }
        }
        if (st.size() == 0) break;
      }


      auto f = [&](vvi to){
        vector<pair<int, int>> dp(n*n + 2, {0, -1});
        vi ind(n*n + 2, 0);
        FL(i, 1, n*n+2){
          for (auto x: to[i]){
            ind[x]++;
          }
        }
        queue<int> q;
        FL(i, 1, n*n+2){
          if (ind[i] == 0) q.push(i);
        }
        while (!q.empty()){
          int u = q.front();
          q.pop();
          for (auto v: to[u]){
            if (dp[v].F <= dp[u].F){
              dp[v] = {dp[u].F+1, u};
            }
            ind[v]--;
            if (ind[v] == 0) q.push(v);
          }
        }
        int mxi = 0;
        FL(i, 1, n*n+2){
          if (dp[i].F > dp[mxi].F){
            mxi = i;
          }
        }
        vi an;
        while (true){
          an.push_back(mxi);
          mxi = dp[mxi].S;
          if (mxi == -1) break;
        }
        return an;
      };
      
      vi an_a = f(tobg);
      vi an_b = f(tosm);

      if (an_a.size() < an_b.size()){
        an_a = an_b;
      }
      sort(ALL(an_a));
      int cnt = 0;
      cout << "! ";
      for (auto x: an_a){
        cout << x << " ";
        cnt++;
        if (cnt == n + 1){
          break;
        }
      }
      cout << endl;
      cout.flush();

      // Now DAGs have been made


    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

