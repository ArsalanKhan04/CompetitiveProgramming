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
      pii f = {-1, -1};
      int sm = 0;
      FL(i,0,n){
        cin >> s;
        FL(j,0,n){
          a[i][j] = (s[j]=='#');
          sm += a[i][j];
          if (f.F == -1 && a[i][j]) f = {i, j};
        }
      }

      if (sm == 4 && a[f.F][f.S] && a[f.F+1][f.S+1]
          && a[f.F+1][f.S] && a[f.F][f.S+1]){
        cout << "Yes" << endl;
        continue;
      }


      set<int> st1, st2;
      FL(i,0,n) FL(j,0,n)
          if (a[i][j]){
            st1.insert(j-i); // increasing lines (lines with +1 gradient)
            st2.insert(i+j); // decreasing lines (lines with -1 gradient)
          }

      if (st1.size() < 2 || st2.size() < 2){
        cout << "Yes" << endl;
        continue;
      }
      if (st1.size() == 2){
        if (abs(*st1.begin() - *st1.rbegin()) == 1){
          cout << "Yes" << endl;
          continue;
        }
      }
      if (st2.size() == 2){
        if (abs(*st2.begin() - *st2.rbegin()) == 1){
          cout << "Yes" << endl;
          continue;
        }
      }
      cout <<"No" << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

