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


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
    // cin >> TCS;
    while(TCS--){
      int n, st, x;
      cin >> n >> st >> x;

      if (n < 2000){
        int vl = -1;
        while (vl < x){
          if (st == -1){
            cout << "! " << st << endl;
            cout.flush();
            return 0;
          }
          cout << "? " << st << endl;
          cout.flush();
          cin >> vl >> st;
          if (vl == -1 && st == -1){
            return 0;
          }
        }
        cout << "! " << vl << endl;
        continue;
      }

      uniform_int_distribution<int> dist(1, n);
      unordered_set<int> nms;
      while (nms.size() < 1000){
        nms.insert(dist(rng));
      }

      vi a(nms.begin(), nms.end());
      array<int, 2> mnvl = {st, -1};

      int ind, vl;
      FL(i, 0, 1000){
        cout << "? " << a[i] << endl;
        cout.flush();
        cin >> vl >> ind;
        if (ind == -1 && vl == -1){
          return 0;
        }
        if (vl < x){
          if (mnvl[1] == -1 || vl > mnvl[1]){
            mnvl = {ind, vl};
          }
        }
      }
      vl = -1;
      st = mnvl[0];
      while (vl < x){
        if (st == -1){
          cout << "! " << st << endl;
          cout.flush();
          return 0;
        }
        cout << "? " << st << endl;
        cout.flush();
        cin >> vl >> st;
        if (vl == -1 && st == -1){
          return 0;
        } 
      }
      cout << "! " << vl << endl;
      cout.flush();
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

