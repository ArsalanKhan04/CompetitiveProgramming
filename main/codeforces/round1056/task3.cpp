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
      set<int> st;
      FL(i, 0, n){
        cin >> a[i];
        st.insert(a[i]);
      }
      if (st.size() == 1){
        if(a[0] == (n+1)/2){
          if (n & 1){
            cout << 2 << endl;
          } else {
            cout << 1 << endl;
          }
          continue;
        }
        if(!(n&1) && a[0] == (n+2)/2){
          cout << 1 << endl;
          continue;
        }
      }
      bool fl = true;
      if (st.size() == 1) fl = false;
      vector<char> b(n, 'X');
      FL(i, 0, n - 1){
        if (abs(a[i] - a[i+1]) > 1) fl = false;
        if(a[i] > a[i+1]){
          if (b[i] == 'L') fl = false;
          b[i] = 'R';
          b[i+1] = 'R';
        } else if (a[i] < a[i+1]){
          if (b[i] == 'R') fl = false;
          b[i] = 'L';
          b[i+1] = 'L';
        }
      }
      FL(i, 1, n){
        if (b[i] == 'X'){
          if (b[i-1] == 'R') b[i] = 'L';
          if (b[i-1] == 'L') b[i] = 'R';
        }
      }
      FFE(i, n-2, 0){
        if (b[i] == 'X') {
          if (b[i+1] == 'R') b[i] = 'L';
          if (b[i+1] == 'L') b[i] = 'R';
      }
      }
      FL(i, 0, n){
        cerr << b[i];
      }
      cerr << endl;
      int c_l = 0, c_r = 0;
      FL(i, 0, n){
        if (b[i] == 'R') c_r++;
      }
      FL(i, 0, n){
        if (b[i] == 'R') c_r--;
        if (a[i] != c_r + c_l + 1) fl = false;
        if (b[i] == 'L') c_l++;
      }
      cout << fl << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

