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

    int mx = 1e5 + 1;
    vb prm(mx + 1, true);
    for (int i = 2; i < mx + 1; i++){
      if (!prm[i]) continue;
      for (int j = i*2; j < mx + 1; j+= i){
        prm[j] = false;
      }
    }
    

    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int n;
      cin >> n;
      vi a(n);
      vb fc(n + 1, false);
      vector<set<int>> divs(n + 1, set<int>());
      for (int i = n; i >= 2; i--){
        if (!prm[i]) continue;
        for (int j = i; j < n + 1; j+= i){
          if (fc[j]) continue;
          divs[i].insert(j);
          fc[j] = true;
        }
        dbg(i, divs[i].size());
      }
      vi c(n + 1);
      vi ans(n + 1, 0);
      ans[1] = 1;
      FL(i, 2, n + 1){
        if (prm[i]){
          for (auto j: divs[i]){
            c[j] = i;
          }
        }
      }
      
      FL(i, 2, n + 1){
        if (c[i] == i){
          int vl = *divs[c[i]].rbegin();
          ans[i] = vl;
          divs[c[i]].erase(vl);
        } else {
          int vl = *divs[c[i]].begin();
          ans[i] = vl;
          divs[c[i]].erase(vl);
        }
      }
      FL(i, 1, n + 1){
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

