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
      vi a(n);
      FL(i, 0, n)
        cin >> a[i];
      sort(ALL(a));
      stack<int> od, ev;
      stack<int> ev_added;
      FL(i,0,n){
        if (a[i] & 1) od.push(a[i]);
        else ev.push(a[i]);
      }
      
      ll sm = 0;
      int ods = 0;
      int evs = 0;
      FL(i,0,n){
        if (sm & 1){
          if (!ev.empty()){
            sm += ev.top();
            ev_added.push(ev.top());
            ev.pop();
          } else if (od.size() > 1 && ev_added.size()){
            sm -= ev_added.top();
            ev.push(ev_added.top());
            ev_added.pop();
            od.pop();
            od.pop();
          } else {
            if (ods == 0){
              sm += od.top();
            }
            ods++;
            od.pop();
          }
        } else {
          if (od.empty()){
            sm += ev.top();
            ev_added.push(ev.top());
            ev.pop();
          } else {
            if (ods == 0){
              sm += od.top();
            }
            ods++;
            od.pop();
          }
        }
        if (ods & 1)
          cout << sm << " ";
        else 
          cout << 0 << " ";
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

