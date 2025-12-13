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

    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> h;
    priority_queue<int, vector<int>, greater<int>> a;
    queue<int> tmp1;
    queue<int> tmp2;
    while (q--){
      int t, v;
      cin >> t >> v;
      if (t==1){
        h.push(v);
      } else {
        a.push(v);
      }
      int sz = 0;
      ll ans = 0;
      while (a.size() > h.size()){
        tmp2.push(a.top());
        a.pop();
      }
      dbg(h.size());
      while(h.size()){
        if (h.size() == a.size() && a.top() < h.top()){
          ans += (h.size() + a.size()) * (a.top() - sz);
          sz = a.top();
          tmp2.push(a.top());
          a.pop();
        } else {
          ans += (h.size() + a.size()) * (h.top() - sz);
          sz = h.top();
          if (h.size() == a.size()){
            tmp2.push(a.top());
            a.pop();
            tmp1.push(h.top());
            h.pop();
          } else {
            tmp1.push(h.top());
            h.pop();
          }
        }
      }
      cout << ans << endl;
      while (tmp1.size()){
        h.push(tmp1.front());
        tmp1.pop();
      }
      while(tmp2.size()){
        a.push(tmp2.front());
        tmp2.pop();
      }


    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

