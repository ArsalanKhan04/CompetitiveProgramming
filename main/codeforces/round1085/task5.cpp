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

vi get_a(vi b){
  int n = b.size();
  vi a(n);
  set<int> st;
  st.insert(b[0]);
  int cr = n - 1;
  if (b[0] <= cr) cr++;
  a[0] = cr;
  FL(i,1,n){
    if (b[i] < cr && st.find(b[i]) == st.end()){
      // no change to cr
    } else {
      cr--;
      while (st.find(cr) != st.end()){
        cr--;
      }
    }
    st.insert(b[i]);
    a[i] = cr;
  }
  return a;
}


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
      vi a(n); vi b(n, n+10);
      FL(i, 0, n)
        cin >> a[i];
      vi c(n);
      iota(ALL(c), 0);
      reverse(ALL(c));

      vi d(n);
      FL(i,0,n) d[i] = a[i]-c[i];
      vi e = d;
      for (int i=n-2; i>=0; i--){
        d[i] = min(d[i], d[i+1]);
      }


      int ad=0;
      int cr = 0;
      bool fl=true;
      FL(i,0,n){
        if (d[i]-ad == 0){
          if (a[i]-c[i]-ad == 1){
            b[i] = c[i]+ad;
          } else if (a[i]-c[i]-ad == 0){
            continue;
          } else {
            fl=false; break;
          }
          continue;
        } else if (d[i]-ad == 1){
          b[i]=cr;
          cr++;
          ad++;
          if (a[i]-c[i]-ad != 0){
            fl = false; break;
          }
        } else {
          fl=false; break;
        }
      }
      if (fl == false){
        cout << "NO" << endl;
        continue;
      }
      cout << "YES" << endl;
      FL(i,0,n){
        cout << b[i] << " ";
      }
      cout << endl;
      /*
      vi aa = get_a(b);

      FL(i,0,n){
        cerr << aa[i] << " ";
      }
      cerr << endl;
      */

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

