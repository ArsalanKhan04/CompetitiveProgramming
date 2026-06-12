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
      int nn;
      cin >> nn;
      string s, t; cin >> s >> t;
      auto f = [](string st){
        int n = st.size();
        vi a(n);
        a[0] = 1;
        FL(i,1,n){
          a[i] = a[i-1];
          a[i] += st[i] == '(' ? 1 : -1;
        }
        int L, R;
        FL(i, 0, n){
          L = i;
          if (st[i] == ')') break;
        }
        FL(i, 0, n){
          if (st[i] == '(') R = i;
        }

        int mnvl = n/2 - 1;
        FL(i,L,R+1){
          mnvl = min(mnvl, a[i]);
        }
        string tt = "";
        FL(i,mnvl,n-mnvl){
          tt+=st[i];
        }
        return tt;
      };

      s = f(s); t = f(t);
      if (s.size() != t.size()){
        cout << "NO" << endl;
        continue;
      }

      nn = s.size();
      int vl = 0;
      FL(i,0,nn-1){
        if (s[i] == '(' && s[i+1] != s[i]) vl++;
      }
      FL(i,0,nn-1){
        if (t[i] == '(' && t[i+1] != t[i]) vl--;
      }
      condprt(!vl);







    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

