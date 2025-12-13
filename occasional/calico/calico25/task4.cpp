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
      int n,m, k;
      cin >> n >> m >> k;
      char tp; int x, y;
      unordered_map<int, int> mp1; // diag1
      unordered_map<int, int> mp4; // diag2
      unordered_map<int, int> mp2; // verts
      unordered_map<int, int> mp3; // horz

      unordered_map<int, pair<int, char>> tp1;
      unordered_map<int, pair<int, char>> tp2;
      unordered_map<int, pair<int, char>> tp3;
      unordered_map<int, pair<int, char>> tp4;

      unordered_map<int, pair<int, char>> tp1_b;
      unordered_map<int, pair<int, char>> tp2_b;
      unordered_map<int, pair<int, char>> tp3_b;
      unordered_map<int, pair<int, char>> tp4_b;

      FL(i,0,k){
        cin >> tp >> x >> y;
        
        if (tp1.find(y-x) == tp1.end() || tp1[y-x].F > x){
          tp1[y-x] = {x, tp};
        } 
        if (tp4.find(y+x) == tp4.end() || tp4[y+x].F > x){
          tp4[y+x] = {x, tp};
        } 
        if (tp2.find(x) == tp2.end() || tp2[x].F > y){
          tp2[x] = {y, tp};
        } 
        if (tp3.find(y) == tp3.end() || tp3[y].F > x){
          tp3[y] = {x, tp};
        } 

        if (tp1_b.find(y-x) == tp1_b.end() || tp1_b[y-x].F < x){
          tp1_b[y-x] = {x, tp};
        } 
        if (tp4_b.find(y+x) == tp4_b.end() || tp4_b[y+x].F < x){
          tp4_b[y+x] = {x, tp};
        } 
        if (tp2_b.find(x) == tp2_b.end() || tp2_b[x].F < y){
          tp2_b[x] = {y, tp};
        } 
        if (tp3_b.find(y) == tp3_b.end() || tp3_b[y].F < x){
          tp3_b[y] = {x, tp};
        } 

        if (tp != 'R') mp1[y-x]++;
        if (tp != 'R') mp4[y+x]++;
        if (tp != 'B') mp2[x]++;
        if (tp != 'B') mp3[y]++;
      }
      ll ans = 0;
      for (auto [ky, vl]: mp1){
        ll cr = vl * 2;
        if (tp1[ky].S != 'R') cr--;
        if (tp1_b[ky].S != 'R') cr--;
        ans += cr;
      }
      for (auto [ky, vl]: mp2){
        ll cr = vl * 2;
        if (tp2[ky].S != 'B') cr--;
        if (tp2_b[ky].S != 'B') cr--;
        ans += cr;
      }
      for (auto [ky, vl]: mp3){
        ll cr = vl * 2;
        if (tp3[ky].S != 'B') cr--;
        if (tp3_b[ky].S != 'B') cr--;
        ans += cr;
      }
      for (auto [ky, vl]: mp4){
        ll cr = vl * 2;
        if (tp4[ky].S != 'R') cr--;
        if (tp4_b[ky].S != 'R') cr--;
        ans += cr;
      }
      cout << ans << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

