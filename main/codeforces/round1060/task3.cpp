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

    /*
    vi prs;
    int mx = 2e5;
    vb prms(mx + 1, true);
    for (int i = 2; i < mx + 1; i++){
      if (!prms[i]) continue;
      for (int j = i * 2; j < mx + 1; j+=i){
        prms[j] = false;
      }
    }
    for (int i = 2; i < mx + 1; i++){
      if (prms[i])
        prs.push_back(i);
    }
    */

    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int n;
      cin >> n;
      vi a(n);
      vll b(n);

      map<int, int> mp;
      auto f = [&](int x){
        if (x == 1) return;
        for (int i = 2; i*i < x + 1; i++){
          if (!(x % i)){
            mp[i]++;
            while (x % i == 0){
              x/=i;
            }
          }
        }
        if (x > 1){
          mp[x]++;
        }
      };

      FL(i, 0, n)
        cin >> a[i];
      FL(i,0,n) cin >> b[i];


      ll cst = 1e15;
      auto g = [&](int u){
        int x = a[u]+1;
        for (int i = 2; i*i < x + 1; i++){
          if (!(x % i)){
            if (mp.find(i) != mp.end()){
              cst = min(cst, b[u]);
            }
            while (x % i == 0){
              x/=i;
            }
          }
        }
        if (x > 1){
          if (mp.find(x) != mp.end()) {
            cst = min(cst, b[u]);
          }
        }
      };

      
      bool fl = false;
      FL(i,0,n){
        f(a[i]);
      }

      for (auto [ky, vl]: mp){
        if (vl > 1){
          fl = true;
        }
      }
      if (fl){
        cout << 0 << endl;
        continue;
      }

      vector<int> st;

      FL(i,0,n){
        g(i);
        if (a[i] & 1){
          st.push_back(b[i]);
        }
      }
      sort(ALL(st));
      if (st.size() >= 2){
        cst = min(cst, (ll)st[0] + st[1]);
      }
      
      pii mvl = {1e9+10, -1};
      FL(i,0,n){
        mvl = min(mvl, {b[i], i});
      }
      int mi = mvl.S;
      for (auto [ky, vl]: mp){
        if (a[mi] % ky == 0) continue;
        cst = min(cst, (ll)mvl.F * (ky-(a[mi]%ky)));
      }


      cout << cst << endl;



    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

