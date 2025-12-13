#include <algorithm>
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

const int P[] = {53, 59};
const int M[] = {(int) 1e9 + 9, (int) 1e9 + 7};

ll pow(ll x, int y, int md){
  ll an = 1;
  while (y){
    if (y & 1){
      an *= x;
      an %= md;
    }
    y>>=1;
    x *= x;
    x %= md;
  }
  return an;
}

pair<int, int> hsh(vi a){
  ll hsh[2] = {0, 0};
  FL(i, 0, a.size()){
    FL(j, 0, 2){
      hsh[j]+=pow(P[j], i, M[j]) * a[i];
    }
  }
  return {hsh[0], hsh[1]};
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
    vi Fac(11);
    Fac[0] = 1;
    FL(i, 1, 11){
      Fac[i] = Fac[i-1] * i;
    }
    dbg(Fac[10]);

    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int n, k;
      cin >> n >> k;
      if (k == 1){
        if (n == 1) {
          cout << "YES" << endl;
          cout << 1 << endl;
        } else {
          cout << "NO" << endl;
        }
        continue;
      }
      if (n<11 && k > Fac[n]){
        cout <<"NO" << endl;
        continue;
      }
      if (k & 1 && n < 11 && k > Fac[n] - 3){
        cout <<"NO" << endl;
        continue;
      }
      if (k & 1 && !(n&1)){
        cout <<"NO" << endl;
        continue;
      }
      vi a(n);
      vvi ans;
      set<pair<int, int>> st;
      iota(ALL(a), 1);
      vi b(n), c(n);
      if (k & 1){
        
        ans.pb(a);
        st.insert(hsh(a));
        FL(i, 0, n){
          int x = i * 2;
          int y = i * 2 + 1;
          x %= n;
          y %= n;
          dbg(x, y);
          b[n-1-x] = i + 1;
          c[n-1-y] = i + 1;
        }
        ans.pb(b);
        st.insert(hsh(b));
        ans.pb(c);
        st.insert(hsh(c));
        next_permutation(ALL(a));
      }
      while (ans.size() < k){
        b = a;
        FL(i, 0, n) b[i] = n + 1- b[i];
        if (st.find(hsh(a)) != st.end() || st.find(hsh(b)) != st.end()){
          next_permutation(ALL(a));
          continue;
        }
        ans.pb(a);
        ans.pb(b);
        next_permutation(ALL(a));
      }
      cout << "YES" << endl;
      for (auto an: ans){
        FL(j, 0, n){
          cout << an[j] << " \n"[j==n-1];
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

