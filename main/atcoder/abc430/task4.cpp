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

    int n;
    cin >> n;
    set<array<ll, 2>> st;
    st.insert({0, 0});
    st.insert({(ll)3e9, n+1});
    vll crmn(n + 2, 2e9);

    int x;
    ll cvl = 2e9;
    FL(i,1,n+1){
      cin >> x;
      st.insert({x, i});
      auto itr = st.find({x, i});
      itr--;
      auto pr = *itr;
      itr++; itr++;
      auto pr2 = *itr;
      if (pr2[1] != n + 1){
        cvl -= crmn[pr2[1]];
        crmn[pr2[1]] = min(crmn[pr2[1]], pr2[0] - x);
        cvl += crmn[pr2[1]];
      }
      cvl -= crmn[pr[1]];
      crmn[pr[1]] = min(crmn[pr[1]], x - pr[0]);
      cvl += crmn[pr[1]];
      
      crmn[i] = min(x - pr[0], pr2[0] - x);
      cvl += crmn[i];
      cout << cvl << endl;
    }

#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

