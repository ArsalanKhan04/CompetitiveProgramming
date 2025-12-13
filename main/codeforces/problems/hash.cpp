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


/* Modular Arithmetic Classes Defined Below */

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}
 

int power(ll x, int pr, int md){
  ll ans = 1; 
  x%=md;
  while (pr){
    if (pr & 1){
      ans *= x;
      ans %= md;
    }
    x = x*x;
    x %= md;
    pr /= 2;
  }
  return ans;
}


const int M1 = 1e9 + 9;
const int P1 = 37;

const int M2 = 1e9 + 7;
const int P2 = 29;

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



    auto f = [&](string s, int p, int md){
      ll hsh = 0;
      for (int i = 0; i < s.size(); i++){
        hsh += (ll) power(p, i, md) * (s[i] - 'a' + 1);
        hsh %= md;
      }
      return hsh;
    };

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    s = "%" + s;
    int hsh2 = f(t, P1, M1);

    vll a(n + 1);
    FL(i,1,n+1){
      a[i] = power(P1, i - 1, M1) * (s[i] - 'a' + 1);
      a[i] %= M1;
    }
    vll c = a;
    FL(i,1,n+1){
      c[i] += c[i-1];
      c[i] %= M1;
    }

    auto g = [&](int i, int j){
      ll vl = c[j] - c[i-1] + M1;
      vl %= M1;
      vl *= power(power(P1, i-1, M1), M1-2, M1);
      vl %= M1;
      return vl;
    };

    set<int> st;
    for (int i = 1; i < n + 1; i++){
      for (int j = i; j < n + 1; j++){
        st.insert(g(i, j));
      }
    }


    set<string> st2;
    for (int i = 1; i < n + 1; i++){
      for (int j = i; j < n + 1; j++){
        string tt = "";
        for (int k = i; k <= j; k++){
          tt += s[k];
        }
        st2.insert(tt);
        st.insert(g(i, j));
        dbg(g(i, j), tt);
      }
    }

    cout << st.size() << endl;
    cout << st2.size() << endl;




#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

