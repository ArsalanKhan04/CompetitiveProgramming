#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int
#define MOD % 1000000007
#define FL(i, a, b) for (int i = a; i < b; i++)
#define FE(i, a, b) for (int i = a; i <= b; i++)
#define FF(i, a, b) for (int i = a; i > b; i--)
#define FFE(i, a, b) for (int i = a; i >= b; i--)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
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

#define REMAX(a, b) a = max((a), (b))
#define REMIN(a, b) a = min((a), (b))

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define INF int(1e9) + 9
 
#define endl '\n'
 
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

    int testcases = 1;
    cin >> testcases;
    while(testcases--){
      int n, m;
      cin >> n >> m;
      vi a(n);
      vi b(m);
      FL(i, 0, n)
        cin >> a[i];
      FL(i, 0, m){
        cin >> b[i];
      }
      vi gr;
      vi tmp;
      gr.pb(a[0]);
      FL(i, 1, n){
        if (a[i] > a[0]) {tmp.pb(a[i]);}
      }
      sort(ALL(tmp));
      FL(i, 0, tmp.size()){
        gr.pb(tmp[i]);
      }
      int x = gr.size();
      FL(i, 0, x){
        cerr << gr[i] << " ";
      }
      cerr << endl;
      vi gr_l(x, 0);

      FL(i, 0, m){
        auto itr = lower_bound(ALL(gr), b[i]);
        if (itr == gr.end()){
          gr_l[0]++;
          continue;
        }
        gr_l[(itr-gr.begin())]++;
      }

      FL(i, 0, x){
        cerr << gr_l[i] << " ";
      }
      cerr << endl;
      vi gr_lc(x);
      gr_lc[0] = gr_l[0];
      FL(i, 1, x){
        gr_lc[i] = gr_l[x - i] + gr_lc[i-1];
      }
      FL(i, 0, x){
        cerr << gr_lc[i] << " ";
      }
      cerr << endl;
      FL(i, 1, m + 1){
        ll ans = 0;
        for(int j = i; j < m + 1; j+=i){
          auto itr = lower_bound(ALL(gr_lc), j);
          ans += itr - gr_lc.begin() + 1;
        }
        cout << ans << " \n"[i==m];
      }
      

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

