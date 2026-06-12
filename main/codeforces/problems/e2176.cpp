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


/**
 * Author: Simon Lindholm
 * Date: 2016-10-08
 * License: CC0
 * Source: me
 * Description: Segment tree with ability to add or set values of large intervals, and compute max of intervals.
 * Can be changed to other things.
 * Use with a bump allocator for better performance, and SmallPtr or implicit indices to save memory.
 * Time: O(\log N).
 * Usage: Node* tr = new Node(v, 0, sz(v));
 * Status: stress-tested a bit
 */
const ll inf = 1e18;
struct Nodex {
	Nodex *l = 0, *r = 0;
	ll lo, hi, mset = inf, madd = 0, val = -inf;
	Nodex(ll lo_,ll hi_):lo(lo_),hi(hi_){} // Large llerval of -inf
	ll query(ll L, ll R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(ll L, ll R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(ll L, ll R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			ll mid = lo + (hi - lo)/2;
			l = new Nodex(lo, mid); r = new Nodex(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

struct Node {
	Node *l = 0, *r = 0;
	ll lo, hi, mset = inf, madd = 0, val = 0;
	Node(ll lo_,ll hi_):lo(lo_),hi(hi_){} // Large llerval of -inf
	ll query(ll L, ll R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return l->query(L, R) + r->query(L, R);
	}
	void set(ll L, ll R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = x, val = (hi-lo)*x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = l->val + r->val;
		}
	}
	void add(ll L, ll R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = l->val + r->val;
		}
	}
	void push() {
		if (!l) {
			ll mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
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
      int n;
      cin >> n;
      vi a(n), c(n), p(n);
      FL(i, 0, n)
        cin >> a[i];
      FL(i,0,n) cin >> c[i];
      FL(i,0,n){
        cin >> p[i];
        p[i]--;
      }

      vi prv(n, 0);
      vi nxt(n, n-1);

      

      vector<array<int, 2>> d;
      FL(i,0,n){
        array<int, 2> cr = {a[i], i};
        auto itr = upper_bound(RALL(d), cr);
        if (itr != d.rend()){
          prv[i] = (*itr)[1]+1;
        }
        while (!d.empty() && d.back()[0] <= cr[0]){
          d.pop_back();
        }
        d.push_back(cr);
      }

      d.clear();
      for (int i=n-1; i>=0; i--){
        array<int, 2> cr = {a[i], (int)1e9};
        auto itr = upper_bound(RALL(d), cr);
        if (itr != d.rend()){
          nxt[i] = (*itr)[1]-1;
        }
        while (!d.empty() && d.back()[0] <= cr[0]){
          d.pop_back();
        }
        cr[1] = i;
        d.push_back(cr);
      }

      /*
      FL(i,0,n){
        cerr << prv[i] << "," << nxt[i] << " ";
      }
      cerr << endl;
      */

      vector<array<int, 4>> va(n);
      FL(i,0,n){
        va[i][0] = c[i];
        va[i][1] = a[i];
        va[i][2] = prv[i];
        va[i][3] = nxt[i];
      }

      sort(RALL(va));




      Node* tr = new Node(0, va.size());
      Nodex* trx = new Nodex(0, va.size());


      FL(i,0,n){
        tr->set(va[i][2], va[i][3]+1, va[i][0]);
        trx->set(va[i][2], va[i][3]+1, va[i][0]);
      }
      /*
        FL(i,0,n){
          cerr << tr->query(i, i+1) << " ";
        }
        cerr << endl;
      */

      cout << tr->query(0, n) - trx->query(0,n) << " ";

      FL(i,0,n){
        tr->set(prv[p[i]], nxt[p[i]]+1, 0);
        trx->set(prv[p[i]], nxt[p[i]]+1, 0);
        cout << tr->query(0, n) - trx->query(0,n) << " ";
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

