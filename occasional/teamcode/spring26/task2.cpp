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


#define aii array<int, 3>

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
      int n,m,k; cin>>n>>m>>k;
      vector<array<int,3>> c1(k); // x, y, d 0,1,2,3 NESW
      vector<array<int,3>> c2(k); // y, x, d 0,1,2,3 NESW
      string D="NESW";
      FL(i,0,k){
        char d;
        cin>>c1[i][0]>>c1[i][1]>>d;
        c1[i][2]=c2[i][2]=D.find(d);
        c2[i][0]=c1[i][1];
        c2[i][1]=c1[i][0];
      }
      // E is +1 to y
      // W is -1 to y
      // S is +1 to x
      // N is -1 to x
      sort(ALL(c1));
      sort(ALL(c2));
      vi dp(k); // min values to explode
      FL(i,0,k){
        if (c1[i][2]==0){
          dp[i]=c1[i][0];
        } else if (c1[i][2]==1){
          dp[i]=m-c1[i][1]+1;
        } else if (c1[i][2]==2){
          dp[i]=n-c1[i][0]+1;
        } else {
          dp[i]=c1[i][1];
        }
      }

      // when going from up to down
      // keep track of values coming S

      map<array<int, 3>, int> mp;
      FL(i,0,k){
        mp[c1[i]]=i;
      }
      
      vector<aii> mvs = {
        {1, 0, 0},
        {0, -1, 1},
        {-1, 0, 2},
        {0, 1, 3}
      };

      FL(t,1,min(n,m)+1){
        FL(x,1,n+1){
          FL(y,1,m+1){
            vi crr;
            for (auto mv: mvs){
              aii cvl = {x+t*mv[0], y+t*mv[1], mv[2]};
              int ind = -1;
              if (mp.find(cvl) != mp.end()){
                ind = mp[cvl];
              }
              if (ind == -1) continue;
              crr.pb(ind);
            }
            if (crr.size() <= 1) continue;
            for (auto ind: crr){
              mp.erase(c1[ind]);
              dp[ind]=t;
            }
          }
        }
      }

      vector<aii> nsv;
      vector<aii> ewv;
      for (auto [ky, vl]: mp){
        if (ky[2]&1){
          ewv.pb(c2[vl]);
        } else {
          nsv.pb(ky);
        }
      }

      // sorted by m
      vector<vector<stack<int>>> stns(m+1, vector<stack<int>>(2));
      // sorted by n
      vector<vector<stack<int>>> stew(n+1, vector<stack<int>>(2));

      sort(ALL(ewv));
      sort(ALL(nsv));

      for (auto ew: ewv){
        int crow = ew[1];
        int ind1 = mp[{ew[1], ew[0], ew[2]}];
        if (ew[2]==3){
          if (!stew[crow][(ew[0]&1)].empty()){
            int ind2 = stew[crow][(ew[0]&1)].top();
            stew[crow][(ew[0]&1)].pop();
            int dist = c2[ind1][0] - c2[ind2][0];
            dp[ind1] = dist/2; dp[ind2] = dist/2;
          } 
        } else {
          stew[crow][ew[0]&1].push(ind1);
        }
      }

      for (auto ns: nsv){
        int crow = ns[1];
        int ind1 = mp[ns];
        if (ns[2]==0){
          if (!stns[crow][(ns[0]&1)].empty()){
            int ind2 = stns[crow][(ns[0]&1)].top();
            stns[crow][(ns[0]&1)].pop();
            int dist = c1[ind1][0] - c1[ind2][0];
            dp[ind1] = dist/2; dp[ind2] = dist/2;
          } 
        } else {
          stns[crow][ns[0]&1].push(ind1);
        }
      }

      FL(i,0,k) {
        cout << dp[i] << " ";
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

