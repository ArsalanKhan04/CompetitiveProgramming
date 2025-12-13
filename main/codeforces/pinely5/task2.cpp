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
      vvi a(n+1, vi(n+1));
      string s;
      FL(i,0,n){
        cin >> s;
        FL(j,0,n){
          a[i][j] = (s[j] == '#');
        }
      }

      pii pr = {-1, -1};
      int bk = 0;
      FL(i,0,n){
        FL(j,0,n){
          if (a[i][j]){
            if (pr.F == -1){
              pr = {i, j};
            }
            bk++;
          }
        }
      }
      if (pr.F == -1 || bk == 1 || (bk == 4 && a[pr.F+1][pr.S+1] 
          && a[pr.F+1][pr.S] && a[pr.F][pr.S+1])){
        cout << "YES" << endl;
        continue;
      }

      set<pair<int, int>> st1, st2;
      FL(i,0,n){
        FL(j,0,n){
          if (a[i][j]) st1.insert({0, j-i});
          if (a[i][j]) st2.insert({0, j+i});
        }
      }
      bool fl = false;
      dbg(st2.size());
      if (st1.size() == 1 || st2.size() == 1){
        fl = true;
      }
      if (st1.size() == 2){
        if((*st1.rbegin()).second - (*st1.begin()).second == 1){
          fl = true;
        }
      }
      if (st2.size() == 2){
        if(abs((*st2.rbegin()).second - (*st2.begin()).second) == 1){
          fl = true;
        }
      }
      if (fl){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

