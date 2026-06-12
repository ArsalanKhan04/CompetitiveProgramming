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
      vi a(n); vi b(n);
      FL(i, 0, n)
        cin >> a[i];
      FL(i, 0, n)
        cin >> b[i];
      FL(i,0,n){
        if (a[i] > b[i]) swap(a[i], b[i]);
      }

      vi c;
      FL(i,0,n) c.pb(a[i]), c.pb(b[i]);
      sort(ALL(c));
      c.erase(unique(ALL(c)), c.end());

      FL(i,0,n){
        a[i] = lower_bound(ALL(c), a[i])-c.begin();
        b[i] = lower_bound(ALL(c), b[i])-c.begin();
      }

      auto f = [&](int x){
        stack<int> st;
        int sgn;
        FL(i,0,n){
          if (a[i] < x && b[i] < x){
            sgn = -1;
          } else if (a[i] >= x && b[i] >= x){
            sgn = +1;
          } else continue;
          if (st.empty()){
            st.push(sgn); 
            continue;
          } else if (sgn==-1 && st.top()==-1){
            continue;
          }
          st.push(sgn);
        }
        int cr = 0;
        while (!st.empty()){
          cr += st.top();
          st.pop();
        }
        // if (x == 3) dbg(cr);
        if (cr <= 0){
          return false;
        } else return true;
      };


      int lw = 0;
      int hg = c.size()-1;


      while (lw <= hg){
        int md = lw + (hg-lw)/2;
        if (f(md)){
          lw = md + 1; // lw remains the same
        } else { 
          hg = md - 1; // + happens atleast once in hg
        }
      }

      cout << c[hg] << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

