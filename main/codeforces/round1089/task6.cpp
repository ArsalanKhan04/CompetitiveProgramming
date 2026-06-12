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

int ask(int l, int r){
  cout << "? " << l << " " << r << endl;
  cout.flush();
  int x;
  cin >> x; 
  if (x==-1) exit(0);
  return x;
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
      int n; cin >> n;
      string s = "$0";
      int cnt = 1;

      auto f = [&](int ind){
        int x, y;
        int vl;
        if (ind >= n/2){
          if (ind & 1){
            x = (ind-1) / ask(2, ind);
            vl = cnt - 1;
          } else {
            x = ind / ask(1, ind);
            vl = cnt;
          }
          if ((vl & 1) == (x & 1)){
            s += '1';
          } else {
            s += '0';
            cnt++;
          }
        } else {
          if ((n-ind+2) & 1){
            x = (n-ind+1)/ ask(ind-1, n-1);
            y = (n-ind-1) / ask(ind+1, n-1);
          } else {
            x = (n-ind+2)/ ask(ind-1, n);
            y = (n-ind)/ ask(ind+1, n);
          }
          if ((y & 1) == (x & 1)){
            s += s.back();
          } else {
            s += s.back() == '1'? '0': '1';
          }
          if (s.back() == '0') cnt++;
          cerr << x << " "<< y << " " << s << endl;
        }
      };

      FL(i,2,n+1){
        f(i);
      }
      cout << "! " << s.substr(1) << endl;
      cout.flush();
      int fl; cin >> fl;
      if (fl==-1) exit(0);
      if (fl) continue;
      FL(i,1,n+1) s[i] = s[i]=='1'? '0' : '1';
      cout << "! " << s.substr(1) << endl;
      cout.flush();
      cin >> fl;
      if (fl==-1) exit(0);

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

