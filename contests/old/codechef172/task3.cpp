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
      int n, k;
      cin >> n >> k;
      vi a(n);
      FL(i, 0, n)
        cin >> a[i];
      set<ll> l, h;

      ll midsum = 0;
      auto bal = [&](){
        if (l.size() > h.size() + 1){
          auto itr = l.end();
          itr--;
          int x = *itr;
          h.insert(x);
          l.erase(x);
          midsum-=x;
        }
        if (h.size() > l.size()){
          auto itr = h.begin();
          int x = *itr;
          l.insert(x);
          h.erase(x);
          midsum+=x;
        }
      };
      auto frm = [&](int val){
        if (l.find(val) != l.end()){
          l.erase(val);
          midsum -= val;
        }
        if (h.find(val) != h.end()){
          h.erase(val);
        }
        bal();
      };
      auto fad = [&](int val){
        if (h.begin() != h.end() && *h.begin() < val){
          int x = *h.begin();
          swap(val, x);
          h.erase(val);
          h.insert(x);
        }
        l.insert(val);
        midsum += val;
        bal();
      };
      ll mxval = 0;

      auto calc = [&](){
        ll curval = midsum * 2;
        auto it = l.end();
        it--;
        if ((n - k) & 1){
          curval -= *it;
        }
        REMAX(mxval, curval);
        dbg(mxval);
      };



      int l1 = 0;
      int l2 = 0;

      FL(i, 0, n){
        fad(a[i]);
      }
      while (l2 < k){
        frm(a[l2++]);
      }
      calc();
      while (l2 < n){
        // remove l2
        fad(a[l1++]);
        frm(a[l2++]);
        calc();
        // add l1
      }

      cout << mxval << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

