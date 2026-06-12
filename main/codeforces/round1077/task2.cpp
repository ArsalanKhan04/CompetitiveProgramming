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
      int x, y;
      cin >> x >> y;
      int p = 0;
      int q = 0;
      int ind = 30;
      int msk = (1 << 30) - 1; // last 30 digits are 1
      set<array<int, 3>> st;
      while (ind >= 0){
        int cvl = 1 << ind;
        if ((cvl & x) && (cvl & y)){
          q++;
          p *= 2;
          q *= 2;
          ind--;
          break;
        } else if (cvl & x){
          p += 1;
        } else if (cvl & y){
          q += 1;
        } else {
          // if p & q both 0
          int xm = x & msk;
          int ym = y & msk;
          int pm1 = (p+1) << ind;
          int qm1 = (q << ind) + ym;
          int pm2 = (p << ind) + xm;
          int qm2 = (q+1) << ind;
          int scr1 = abs(x-pm1) + abs(y-qm1);
          int scr2 = abs(x-pm2) + abs(y-qm2);
          st.insert({scr1, pm1, qm1});
          st.insert({scr2, pm2, qm2});
        }
        p *= 2;
        q *= 2;
        ind--;
        msk >>= 1;
      }
      while (ind >= 0){
        p++;
        p *= 2;
        q *= 2;
        ind--;
      }
      p /= 2;
      q /= 2;
      // dbg(p, q);
      st.insert({abs(x-p) + abs(y-q), p, q});

      auto an = *st.begin();
      // dbg(an.size());
      dbg(an[0]);
      
      cout << an[1] << " " << an[2] << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

