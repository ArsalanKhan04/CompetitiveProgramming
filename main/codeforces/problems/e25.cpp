#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int
#define MOD % 1000000007
#define FL(i, a, b) for (int i = a; i < b; i++)
#define FE(i, a, b) for (int i = a; i <= b; i++)
#define FF(i, a, b) for (int i = a; i > b; i--)
#define FFE(i, a, b) for (int i = a; i >= b; i--)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
#define pii pair<int, int>
#define vpii vector<pii>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
#define endl '\n'
 
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

  int t;
  cin >> t;
  FL(et, 0, t) {
    string s;
    cin >> s;
    int n = s.size();
    bool flag = false;
    FL(i, 0, n/2){
      if(s[i]!=s[n-1-i]){
        flag = true;
        break;
      }
    }
    if (flag){
      cout << "YES" << endl;
      cout << 1 << endl;
      cout << s << endl;
      continue;
    }
    int x = 0;
    while (x < n && s[x]==s[0])
      x++;
    if (x==n){
      cout << "NO" << endl;
      continue;
    }
    dbg(x);
    FL(i, 0, (n - x) / 2){
      if (s[x+1+i] != s[n-1-i]){
        flag = true;
        break;
      }
    }
    if (flag){
      cout << "YES" << endl;
      cout << 2 << endl;
      cout << s.substr(0, x+1) << " " << s.substr(x + 1, n) << endl;
      continue;
    } 
    dbg(x);
    if (x == 1 || ((n&1) && (x == n/2))){
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    cout << 2 << endl;
    cout << s.substr(0, x + 2) << " " << s.substr(x + 2, n) << endl;

  }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

