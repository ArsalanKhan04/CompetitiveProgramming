
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

    int mx = 100000;
    vb prm(mx + 1, true);
    FL(i, 2, mx + 1){
      if (!prm[i]) continue;
      for (int j = 2 * i; j < mx + 1; j += i){
        prm[j] = false;
      }
    }
    prm[1] = false;
    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int n;
      cin >> n;
      set<int> st;
      set<int> pm;
      FL(i, 1, n + 1){
        st.insert(i);
        if (prm[i]) pm.insert(i);
      }
      st.erase(2);
      vi ans(n + 1, 0);
      ans[1] = 2;
      ll sum = 2;
      int i = 2;
      while (i < n + 1){
        if (pm.begin() == pm.end()) break;
        int tf = ((*pm.begin() - 1) * i) - sum + 1;
        if (tf < 0){ pm.erase(*pm.begin());
          continue;
        }
        auto itr = st.lower_bound(tf);
        if (itr == st.end() || (*itr + sum + i - 1) / i > *(pm.begin())){
          ans[i] = *st.rbegin();
          sum+=ans[i];
          st.erase(*st.rbegin());
          i++;
          continue;
        }
        ans[i] = *itr;
        sum += ans[i];
        st.erase(ans[i]);
        i++;
      }
      ll sm = 0;
      FL(x, 1, n + 1){
        cout << ans[x] << " ";
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

