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
    int T; cin >> T;
    while (T--){
      int n, k;
      cin>>n>>k;
      vi A(n);
      vi B(n);
      vpii a;
      ll cost = 0, sales=0;
      FL(i,0,n) {
        cin>>A[i];
      }
      FL(i,0,n) {
        cin>>B[i];
      }
      FL(i,0,n) {
        if (A[i] <= B[i]){
          cost += A[i];
          sales += B[i];
          a.pb({B[i], A[i]});
        }
      }
      sort(ALL(a), greater<pii>());
      auto comp = [&](pii &x, pii &y){
        return x.S < y.S; 
      };
      int x = 0;
      priority_queue<pii, vpii, decltype(comp)> pq(comp);
      ll mx = 0;
      ll curr;
      while (x < a.size()){
        curr = sales - cost;
        if (pq.size() == k){
          REMAX(mx, curr);
        }
        pq.push(a[x]);
        sales -= a[x].F;
        if (pq.size() > k){
          cost -= pq.top().S;
          pq.pop();
        }
        x++;
      }

      cout << mx << endl;
    }
    
    

#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

