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
      int n , k;
      cin >> n >> k;
      vll a(n), p(n), d(n);
      FL(i, 0, n) cin >> p[i];
      FL(i, 0, n) cin >> d[i];



      int q; cin >> q;
      while (q--){
        set<array<ll, 3>> st;
        ll ps;
        cin >> ps;
        int T = 0;
        int dr = 1;
        int ind;
        auto itr = lower_bound(ALL(p), ps);
        if (itr == p.end()){
          cout << "YES" << endl;
          continue;
        } else {
          ind = itr - p.begin();
          T = (*itr - ps) % k;
          ps = *itr;
        }
        st.insert({ps, T, dr});

        bool fl = false;
        while (true){
          if (d[ind] == T){
            dr = !dr;
          }
          dbg(ps, T, dr);
          if (dr == 1){
            itr = lower_bound(ALL(p), ps + 1);
            if (itr == p.end()){
              fl = true;
              break;
            } else {
              T = (T + *itr - ps) % k;
              ps = *itr;
              ind = itr - p.begin();
              if (st.find({ps, T, dr}) != st.end()){
                break;
              }
              st.insert({ps, T, dr});
            }
          } else {
            itr = lower_bound(ALL(p), ps);
            if (itr == p.begin()){
              fl = true;
              break;
            } else {
              itr--;
              T = (T + ps - *itr) % k;
              ps = *itr;
              ind = itr - p.begin();
              if (st.find({ps, T, dr}) != st.end()){
                break;
              }
              st.insert({ps, T, dr});
            }
          }
        }

        if (fl){
          cout << "YES" << endl;
          continue;
        }
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

