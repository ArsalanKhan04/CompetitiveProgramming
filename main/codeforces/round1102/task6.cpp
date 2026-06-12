#include <algorithm>
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
      vll h(n);
      FL(i, 0, n)
        cin >> h[i];
      int rt = 0;
      FL(i,0,n){
        if (h[rt] < h[i]) rt = i;
      }
      rotate(h.begin(), h.begin()+rt+1, h.end());
      for (auto vl: h) cerr << vl << " ";
      cerr << endl;

      vll prf(n, 0);
      vll suf(n, 0);
      stack<pair<ll, int>> stk;
      // prf is initially 0 and stack is empty
      // left of l
      // when w0 is empty nothing to the left of it
      ll sm = 0;
      FL(i,1,n){
        int cnt = 0;
        while (!stk.empty() && stk.top().F < h[i-1]){
          sm -= stk.top().F * stk.top().S;
          cnt += stk.top().S; stk.pop();
        }
        stk.push({h[i-1], cnt+1});
        sm += h[i-1]*(cnt+1);
        prf[i] = sm;
      }
      stk = stack<pair<ll, int>>();
      sm = 0;
      for (int i = n-2; i>=0; i--){
        int cnt = 0;
        while (!stk.empty() && stk.top().F < h[i]){
          sm -= stk.top().F * stk.top().S;
          cnt += stk.top().S; stk.pop();
        }
        stk.push({h[i], cnt+1});
        sm += h[i]*(cnt+1);
        suf[i] = sm;
      }

      auto ans = prf;
      FL(i,0,n){
        ans[i] = prf[i] + suf[i];
      }
      rotate(ans.begin(), ans.begin()+n-(rt+1), ans.end());
      FL(i,0,n){
        cout << ans[i] << " ";
      }
      cout << endl;
      /*
      FL(i,0,n){
        cout << suf[i] << " ";
      }
      cout << endl;

      cout << endl;
      */





    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

