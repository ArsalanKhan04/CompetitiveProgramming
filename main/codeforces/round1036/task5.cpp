#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int
#define FL(i, a, b) for (ll i = a; i < b; i++)
#define FE(i, a, b) for (ll i = a; i <= b; i++)
#define FF(i, a, b) for (ll i = a; i > b; i--)
#define FFE(i, a, b) for (ll i = a; i >= b; i--)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>
#define vpii vector<pii>
#define vll vector<ll>
#define vvll vector<vll>
#define vi vector<ll>
#define vvi vector<vll>
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
      vll a(n + 1);
      FL(i, 1, n + 1)
        cin >> a[i];
      ll sm = accumulate(ALL(a), (ll) 0);
      ll hf = sm / 2;
      if (sm & 1 || hf < *max_element(ALL(a))){
        cout << -1 << endl;
        continue;
      }
      vll c = a;
      FL(i, 1, n+1) c[i]+=c[i-1];

      auto f = [&](auto &&slf, int l, int r, ll hfg, vector<array<ll, 4>>& pxx)->ll{
        ll ans = 0;
        int x = l;
        ll csm = 0;
        while (x < r + 1){
          csm += a[x];
          x++;
          if (csm >= hfg){
            break;
          }
        }
        dbg(x);
        if (c[x-1] - c[l-1] >= hfg && c[r] - c[x-1] >= hfg){
          pxx.pb({l, r, x-1, hfg});
          return 1;
        } else {
          vector<array<ll, 4>> axx, bxx;
          ll vl1, vl2;
          vl1 = c[x-1]-c[l-1];
          vl2 = c[r]-c[x-1];
          ll avl = slf(slf, l, x-1, (vl1-vl2)/2, axx);
          vl1 = c[x-2]-c[l-1];
          vl2 = c[r]-c[x-2];
          ll bvl = slf(slf, x-1, r, (vl2-vl1)/2, bxx);
          if (bvl > avl){
            axx.pb({l, r, x-1, vl2});
            pxx = axx;
            return 1 + avl;
          } else {
            bxx.pb({l, r, x-2, vl1});
            pxx = bxx;
            return 1 + bvl;
          }
        }
      };
      vector<array<ll, 4>> pxx;
      int ans = f(f, 1, n, hf, pxx);
      cout << ans << endl;
      vvll ans_arr;
      for (auto [l, r, x, hv]: pxx){
        vll bv(n + 1, 0);
        ll h2 = hv;
        for (int i = l; i <= x; i++){
          if (a[i] >= h2){
            bv[i] = h2;
            a[i] -= h2;
            break;
          } else {
            bv[i] = a[i];
            h2 -= a[i];
            a[i] = 0;
          }
        }
        h2 = hv;
        for (int i = x + 1; i<= r; i++){
          if (a[i] >= h2){
            bv[i] = h2;
            a[i] -= h2;
            break;
          } else {
            bv[i] = a[i];
            h2 -= a[i];
            a[i] = 0;
          }
        }
        ans_arr.pb(bv);
      }
      for (auto arr: ans_arr){
        FL(i, 1, n + 1){
          cout << arr[i] << " ";
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

