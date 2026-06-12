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
      vi b = a;
      sort(ALL(b));
      b.erase(unique(ALL(b)), b.end());
      FL(i,0,n){
        a[i] = lower_bound(ALL(b), a[i]) - b.begin();
      }
      vector<vpii> vp(n);

      FL(i,0,n){
        if (vp[a[i]].empty() || vp[a[i]].back().second < i - 1){
          vp[a[i]].push_back({i, i});
        } else {
          vp[a[i]].back().second=i;
        }
      }

      bool fl = true;
      set<pii> st1, st2;

      auto f = [&](int ind){
        st2.clear();
        vpii cvp = vp[ind];
        if (cvp.empty()) return;
        if (cvp.size() == 1) return;
        if (cvp.size() >= 4) {
          fl = false;
          return;
        }
        if (cvp.size() == 2){
          if (cvp[0].second == cvp[1].first - 2){
            st2.insert({cvp[0].second+1, cvp[1].second});
            st2.insert({cvp[0].first, cvp[0].second+1});
          }
          if (cvp[0].first == cvp[0].second
              && cvp[1].second+1 < n){
            st2.insert({cvp[0].first, cvp[1].second+1});
          }
          if (cvp[1].first == cvp[1].second
              && cvp[0].first-1 >= 0){
            st2.insert({cvp[0].first-1, cvp[1].second});
          }
          if (cvp[0].first == cvp[0].second){
            st2.insert({cvp[0].first, cvp[1].first-1});
          }
          if (cvp[1].first == cvp[1].second){
            st2.insert({cvp[0].second+1, cvp[1].second});
          }
        } else {
          if ((cvp[0].first == cvp[0].second)
            && (cvp[1].second+1==cvp[2].first-1)){
            st2.insert({cvp[0].first, cvp[1].second+1});
          }
          if ((cvp[2].first == cvp[2].second)
              && (cvp[0].second+1==cvp[1].first-1)){
            st2.insert({cvp[0].second+1, cvp[2].first});
          }
        }
        if (st2.empty()){
          fl = false;
          return;
        }
        if (st1.empty()){ 
          st1=st2;
          return;
        }
        set<pii> st3;
        for (auto stvl: st2){
          if (st1.find(stvl)!=st1.end()) st3.insert(stvl);
        }
        if (st3.empty()){
          fl = false;
          return;
        }
        st1=st3;
      };




      FL(i,0,n){
        f(i);
      }
      
      st1.insert({1,1});
      fl = false;
      for (auto pvl: st1){
        FL(i,0,n) vp[i].clear();
        dbg(pvl.first, pvl.second);
        bool fl3 = true;
        vi c = a;
        swap(c[pvl.first], c[pvl.second]);
        FL(i,0,n){
          if (vp[c[i]].empty() || vp[c[i]].back().second < i - 1){
            dbg(c[i], i);
            vp[c[i]].push_back({i, i});
          } else {
            vp[c[i]].back().second=i;
          }
          if (vp[c[i]].size() > 1){
            fl3 = false;
            dbg(c[i]);
          }
        }
        fl |= fl3;
      }
      condprt(fl);

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

