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
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a + b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n_i = 0, T def = unit) : s(2*n_i, def), n(n_i) {}
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

    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int n, k;
      cin >> n >> k;
      vi a(n);
      FL(i, 0, n)
        cin >> a[i];

      auto f1 = [&](int v, int& x, int& y)->bool{
        vi b(n);
        FL(i, 0, n){
          if (a[i] >= v){
            b[i] = 1;
          } else {
            b[i] = -1;
          }
        }
        FL(i, 1, n){
          b[i]+=b[i-1];
        }
        set<pair<int, int>> st;
        st.insert({0, -1});
        int l = 0;
        int r = k - 1;
        while (r < n){
          if (b[r] - (*st.begin()).F >= 0){
            x = (*st.begin()).S + 1;
            y = r;
            return true;
          }
          st.insert({b[l], l});
          l++;
          r++;
        }
        return false;
      };
      auto f2 = [&](int v, int& x, int& y)->bool{
        vi b(n);
        FL(i, 0, n){
          if (a[i] <= v){
            b[i] = 1;
          } else {
            b[i] = -1;
          }
        }
        FL(i, 1, n){
          b[i]+=b[i-1];
        }
        set<pair<int, int>> st;
        st.insert({0, -1});
        int l = 0;
        int r = k - 1;
        while (r < n){
          if (b[r] - (*st.begin()).F >= 0){
            x = (*st.begin()).S + 1;
            y = r;
            return true;
          }
          st.insert({b[l], l});
          l++;
          r++;
        }
        return false;
      };


      int lw = 1;
      int hg = n;
      int x, y;
      while (lw <= hg){
        int md = lw + (hg - lw) / 2;
        if (f1(md, x, y)){
          lw = md + 1;
        } else {
          hg = md - 1;
        }
      }
      array<int, 3> mx_vl, mn_vl;
      f1(hg, x, y);
      mx_vl = {hg, x, y};
      lw = 1, hg = n;
      while (lw <= hg){
        int md = lw + (hg - lw) / 2;
        if (f2(md, x, y)){
          hg = md - 1;
        } else {
          lw = md + 1;
        }
      }
      f2(lw, x, y);
      mn_vl = {lw, x, y};
      dbg(mn_vl[0], mx_vl[0]);

      Tree seggy(n + 2);
      FL(i, mn_vl[1], mn_vl[2] + 1){
        seggy.update(a[i], seggy.query(a[i], a[i]+1)+1);
      }

      int l = mn_vl[1];
      int ld = (mx_vl[1] - mn_vl[1]);
      int lf = mx_vl[1];
      if (ld != 0) ld /= abs(ld);
      int r = mn_vl[2];
      int rd = (mx_vl[2] - mn_vl[2]);
      int rf = mx_vl[2];
      if (rd != 0) rd /= abs(rd);
      int w = r - l + 1;
      dbg(l, ld, lf);
      dbg(r, rd, rf);
      cout << mx_vl[0] + 1 - mn_vl[0] << endl;
      FL(i, mn_vl[0], mx_vl[0] + 1){
        dbg(i);
        while (true){
          if (seggy.query(i, n+2) >= (w + 1)/2 &&
              seggy.query(0, i + 1) >= (w+1)/2){
            cout << i << " " << l + 1 << " " << r + 1 << endl;
            break;
          }
          dbg(l, r, lf, rf);
          dbg(l + ld);
          if (ld != 0 && l != lf && (ld < 0 || w > k)){
            if (ld < 0){
              l += ld;
              seggy.update(a[l], seggy.query(a[l], a[l]+1) + 1);
              w++;
            } else {
              seggy.update(a[l], seggy.query(a[l], a[l]+1) - 1);
              l += ld;
              w--;
            }
            continue;
          }
          dbg(r + rd);
          if (rd < 0){
            seggy.update(a[r], seggy.query(a[r], a[r]+1) - 1);
            r += rd;
            w--;
          } else {
            r += rd;
            seggy.update(a[r], seggy.query(a[r], a[r]+1) + 1);
            w++;
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

