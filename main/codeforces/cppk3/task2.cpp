
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
      int n, m;
      cin >> n >> m;
      vvi a(n, vi(m));
      string s;
      FL(i, 0, n){
        cin >> s;
        FL(j, 0, m) {
          a[i][j] = s[j] - '0';
        }
      }

      auto prt_mat = [&](){
      };

      vector<vpii> ans;
      for (int i = n - 1; i > 1; i -= 1){
        for(int j = 0; j < m; j++){
          if (a[i][j]){
            if (j > 0){
              ans.pb({{i, j}, {i - 1, j}, {i-1, j - 1}});
              a[i-1][j-1] = !a[i-1][j-1];
              a[i][j] = 0;
              a[i-1][j] = !a[i-1][j];
            } else {
              ans.pb({{i, j}, {i - 1, j}, {i-1, j + 1}});
              a[i-1][j+1] = !a[i-1][j+1];
              a[i][j] = 0;
              a[i-1][j] = !a[i-1][j];
            }
            prt_mat();
          }
        }
      }
      for (int j = m - 1; j > 1; j--){
        for (int i = 0; i < 2; i++){
          if (a[i][j] && i == 0){
              ans.pb({{i, j}, {i + 1, j-1}, {i, j-1}});
              a[i][j] = !a[i][j];
              a[i+1][j-1] = !a[i+1][j-1];
              a[i][j-1] = !a[i][j-1];
          }
          if (a[i][j] && i == 1){
              ans.pb({{i, j}, {i - 1, j-1}, {i, j-1}});
              a[i][j] = !a[i][j];
              a[i-1][j-1] = !a[i-1][j-1];
              a[i][j-1] = !a[i][j-1];
          }
          prt_mat();
        }
      }

      int val = 0;
      for (; val < 16; val++){
        vi tmp(4);
        tmp[0] = a[0][0];
        tmp[1] = a[0][1];
        tmp[2] = a[1][0];
        tmp[3] = a[1][1];
        for (int i = 0; i < 4; i++){
          if ((1 << i) & val){
            FL(j, 0, 4){
              if (j == i) continue;
              tmp[j] = !tmp[j];
            }
          }
        }
        if (tmp[0] + tmp[1] + tmp[2] + tmp[3] == 0)
          break;
      }
      for (int i = 0; i < 4; i++){
        if ((1 << i) & val){
          vpii t;
          FL(j, 0, 4){
            if (j == i) continue;
            t.pb({j / 2, j % 2});
          }
          ans.pb(t);
        }
      }

      cout << ans.size() << endl;
      FL(i, 0, ans.size()){
        FL(j, 0, 3){
          cout << ans[i][j].F+1 << " " << ans[i][j].S+1 << " ";
        }
       cout << endl;
      }
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

