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
      vector<array<ll, 5>> pos;
      vector<array<ll, 5>> neg;
      vector<array<ll, 5>> q(n);
      FL(i, 0, n){
        FL(j,0,3){
          cin >> q[i][j];
        }
        q[i][3] = i;
        q[i][4] = 1;
        if (q[i][0] > 0) pos.pb(q[i]);
        else neg.pb(q[i]);
      }

      sort(ALL(pos), [](auto x, auto y){
        return x[2] < y[2];
          });

      sort(ALL(neg), [](auto x, auto y){
        return x[2] > y[2];
          });
      dbg(pos.size(), neg.size());


      auto f = [](array<ll, 5> lft, array<ll, 5> rgt)->bool{
        array<ll, 3> pl;
        pl[0] = lft[0] - rgt[0];
        pl[1] = lft[1] - rgt[1];
        pl[2] = lft[2] - rgt[2];
        if (pl[0] == pl[1] && pl[0] == 0) return false;
        
        ll b2ac = 0;
        b2ac = pl[1] * pl[1];
        b2ac -= 4 * pl[0] * pl[2];
        dbg(b2ac);
        return b2ac >= 0;
      };

      int pn = pos.size(); int nn = neg.size();
      for (int i = pn-1; i>=0; i--){
        FL(j,i+1,pn){
          if (f(pos[i], pos[j])) continue;
          pos[i][4] = max(pos[i][4], pos[j][4] + 1);
        }
        dbg(pos[i][4]);
      }

      for (int i = nn-1; i>=0; i--){
        FL(j,i+1,nn){
          if (f(neg[i], neg[j])) continue;
          neg[i][4] = max(neg[i][4], neg[j][4] + 1);
        }
      }

      vll ans(n, 0);
      FL(i,0,pn){
        ans[pos[i][3]] = pos[i][4];
      }
      FL(j,0,nn){
        ans[neg[j][3]] = neg[j][4];
      }
      FL(i,0,pn){
        FL(j,0,nn){
          if (f(pos[i], neg[j])) continue;
          dbg("YES");
          dbg(pos[i][4], neg[j][4]);
          ans[pos[i][3]] = max(ans[pos[i][3]], pos[i][4] + neg[j][4]);
          ans[neg[j][3]] = max(ans[neg[j][3]], pos[i][4] + neg[j][4]);
        }
      }

      FL(i,0,pn){
        FL(j,i+1,pn){
          if (f(pos[i], pos[j])) continue;
          ans[pos[j][3]] = max(ans[pos[j][3]], ans[pos[i][3]]);
        }
      }
      FL(i,0,nn){
        FL(j,i+1,nn){
          if (f(neg[i], neg[j])) continue;
          ans[neg[j][3]] = max(ans[neg[j][3]], ans[neg[i][3]]);
        }
      }

      FL(i,0,n){
        cout << ans[i] << " ";
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

