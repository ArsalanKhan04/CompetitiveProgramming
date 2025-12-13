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



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist(1, 1000000000);

int grnd(int l, int r){
  int x = dist(rng);
  x %= (r-l+1);
  x += l;
  return x;
}

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
      int n, q;
      cin >> n >> q;
      vi a(n);
      FL(i, 0, n)
        cin >> a[i];
      vi b = a;
      sort(ALL(b));
      b.erase(unique(ALL(b)), b.end());
      vvi mp(n);
      FL(i, 0, n){
        auto itr = lower_bound(ALL(b), a[i]);
        int x = itr-b.begin();
        mp[x].pb(i);
        a[i] = x;
      }
      while (q--){
        int l, r;
        cin >> l >> r;
        r--; l--;
        set<int> st;
        int rnx;
        FL(i, 0, 30){
          rnx = grnd(l, r);
          if (upper_bound(ALL(mp[a[rnx]]), r) -
              lower_bound(ALL(mp[a[rnx]]), l) >
              (r-l+1)/3){
            st.insert(b[a[rnx]]);
          }
        }
        if (st.empty()) st.insert(-1);
        for (auto vl: st){
          cout << vl << " ";
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

