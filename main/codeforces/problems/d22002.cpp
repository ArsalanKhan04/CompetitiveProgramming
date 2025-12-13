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



struct Tree {
	typedef ll T;
	T unit = 0;
	T f(T a, T b) { return a+b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n_ = 0, T def = 0) : s(2*n_, def), n(n_) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

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

    // for each find children and ancestors
    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int n,q; cin >> n >> q;
      int P;
      vvi to(n+1);
      FL(i,2,n+1){
        cin >> P;
        to[P].pb(i);
      }
      vi p(n +1, 0);
      FL(i,1,n+1) cin >> p[i];



      vll chld(n+1, 0);
      vll dpth(n+1,0);
      auto f = [&](auto &&slf, int u, int pp, int d)->void{
        dpth[u] = d;
        for (auto v: to[u]){
          if (v == pp) continue;
          slf(slf, v, u, d+u);
          chld[u] += chld[v] + 1;
        }
      };
      f(f, 1, -1, 0);

      ll sm = 0;
      vll ndvl(n+1, 0);
      auto g = [&](int x){
        ll ad = dpth[p[x]] * x;
        ll sb = chld[p[x]] * x * p[x];
        sb += (chld[p[x]] * (chld[p[x]] + 1))/2 * p[x];
        sm -= ndvl[x];
        ndvl[x] = ad - sb;
        sm += ndvl[x];
      };


      FL(i,1,n+1){
        g(i);
      }
      while (q--){
        int x, y;
        cin >> x >> y;
        swap(p[x], p[y]);
        g(x);
        g(y);
        if (sm == 0){
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
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

