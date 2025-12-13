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
    // cin >> TCS;
    while(TCS--){
      int n;
      cin >> n;
      vi a(n + 1);
      FL(i, 1, n + 1)
        cin >> a[i];
      
      vvi c(n + 1, vi());
      int thres = sqrt(n);
      FL(i, 1, n + 1){
        c[a[i]].pb(i);
      }

      vi ans(n + 1, 0);
      auto f1 = [&](int L){
        // less Ls (use harmonic sum over here)
        vi curr = c[L];
        int m = curr.size();
        vi nxt(n + 1);
        int cr = n + 1;
        for (int i = n; i >= 0; i--){
          if (a[i] == L){
            cr = i;
          }
          nxt[i] = cr;
        }
        // nxt has been defined, now we will calculate for each value of x
        for (int x = 1; x < n + 1; x++){
          int grps = 0;
          int ptr = nxt[0];
          while (ptr < n + 1){
            grps++;
            if (ptr + x + 1 > n){
              break;
            }
            ptr = nxt[ptr+x+1];
          }
          ans[x] += grps;
        }
      };


      auto fn = [&](int L, int x, int g)->bool{
        vi curr = c[L];
        int m = curr.size();

        int prev = curr[0];
        g--;
        FL(i, 0, m){
          if (curr[i] - prev > x){
            g--;
            prev = curr[i];
          }
        }
        if (g >= 0){
          return true;
        } else {
          return false;
        }
      };

      auto f2 = [&](int L){
        vi curr = c[L];
        int m = curr.size();
        vi grps(m + 1);
        for (int i = 1; i <= m; i++){
          int lw = 1; int hg = n;
          int md;
          while (lw <= hg){
            md = lw + (hg - lw) / 2;
            if (fn(L, md, i)){
              hg = md - 1;
            } else {
              lw = md + 1;
            }
          }
          grps[i] = lw;
        };
        // grps is in descending order (starting from biggest value to smallest)
        // we will keep it in this form so that we can reconstruct answer
        FL(i, 1, m + 1){
          ans[grps[i]]+= 1;
        }

      };
      int tmp = 0;
      FL(L, 1, n + 1){
        if (c[L].size() == 0) continue;
        if (c[L].size() < thres){
          tmp++;
          f2(L);
        }
      }
      for (int i = n; i >= 1; i--){
        dbg(ans[i]);
        swap(ans[i], tmp);
        tmp += ans[i];
      }
      FL(L, 1, n + 1){
        if (c[L].size() >= thres){
          f1(L);
        }
      }
      FL(i, 1, n + 1){
        cout << ans[i] << endl;
      }

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

