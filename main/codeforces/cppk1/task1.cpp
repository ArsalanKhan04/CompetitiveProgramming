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


template <class T>
struct segTree
{
    int n;
    vector<T> t;
    T init;
    segTree(int _n, T _init)
    {
        n = _n;
        t.resize(2 * n);
        init = _init;
        for (auto &tt : t)
            tt = init;
    }

    void update(int i, T k)
    {
        i += n;
        t[i] = k;
        while (i > 1)
        {
            i >>= 1;
            t[i] = merge(t[i << 1], t[(i << 1) | 1]);
        }
    }

    T query(int l, int r)
    {
        l += n;
        r += n;
        T res = init;
        while (l < r)
        {
            if (l & 1)
            {
                res = merge(res, t[l]);
                l++;
            }
            if (!(r & 1))
            {
                res = merge(res, t[r]);
                r--;
            }
            l >>= 1;
            r >>= 1;
        }
        if (l == r)
            res = merge(res, t[l]);
        return res;
    }

    T merge(T a, T b)
    {
        T res;
        res = a + b;
        return res;
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

    int testcases = 1;
    cin >> testcases;
    while(testcases--){
      int n;
      cin >> n;
      vi a(n);
      FL(i, 0, n){
        cin >> a[i];
        a[i]--;
      }
      segTree<int> st(2*n, 0);
      vi b(2 * n, -1);
      FL(i, 0, n){
        b[i] = a[i];
        b[i+n] = a[i];
      }
      int ext;
      vi ans(n);
      FFE(i, 2*n-1, 0){
        if (b[i] >= i){
          dbg(i, b[i], st.query(i + 1, b[i]-1));
          st.update(b[i], 1);
          ans[b[i]] = (b[i] - i) - st.query(i + 1, b[i] - 1);
        } else if (b[i] + n >= i) {
          dbg(i, b[i], st.query(i + 1, b[i]-1+n));
          st.update(b[i] + n, 1);
          ans[b[i]] = (b[i] - i + n) - st.query(i + 1, b[i] - 1 + n);
        }
      }
      FL(i, 0, n){
        cout << ans[i] << " \n"[i==n-1];
      }
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

