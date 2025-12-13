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
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define INF int(1e9) + 9
 
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
    dbg(testcases);
    cin >> testcases;
    while(testcases--){
      int n;
      cin >> n;
      dbg(n);
      pii s;
      int x, y;
      cin >> x >> y;
      bool def = (x ^ y) & 1;
      vb avail(n + 1, true);
      avail[0] = false;

      vector<queue<int>> q(2, queue<int>());
      FL(i, 1, n + 1){
        cin >> x >> y;
        q[(x ^ y) & 1].push(i);
      }
      dbg(def);
      dbg(!def);
      dbg(q[def].size());
      dbg(q[!def].size());

      int j;
      if (q[def].size() >= q[!def].size()){
        cout << "First" << endl;
        cout.flush();
        FL(i, 0, n){
          if (i & 1){
            cin >> j;
            if (j == -1)
              return 0;
            avail[j] = false;
          } else {
            while (!q[!def].empty()){
              if (avail[q[!def].front()]){
                break;
              } else {
                q[!def].pop();
              }
            }
            if (q[!def].empty()){
              while (!q[def].empty()){
                if (avail[q[def].front()]){
                  break;
                } else {
                  q[def].pop();
                }
              }
              cout << q[def].front() << endl;
              cout.flush();
              q[def].pop();
            } else {
              cout << q[!def].front() << endl;
              cout.flush();
              q[!def].pop();
            }
          }
        }
      } else {
        cout << "Second" << endl;
        cout.flush();
        FL(i, 1, n + 1){
          if (i & 1){
            cin >> j;
            if (j == -1)
              return 0;
            avail[j] = false;
          } else {
            while (!q[def].empty()){
              if (avail[q[def].front()]){
                break;
              } else {
                q[def].pop();
              }
            }
            if (q[def].empty()){
              while (!q[!def].empty()){
                if (avail[q[!def].front()]){
                  break;
                } else {
                  q[!def].pop();
                }
              }
              cout << q[!def].front() << endl;
              cout.flush();
              q[!def].pop();
            } else {
              cout << q[def].front() << endl;
              cout.flush();
              q[def].pop();
            }
          }
        }
      }
      
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

