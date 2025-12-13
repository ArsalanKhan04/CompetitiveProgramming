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
      int n, q;
      cin >> n >> q;
      vi a(n);
      string s;
      cin >> s;
      vvi to(3, vi(3, 0));
      vvi avto(3, vi(3, 0));
      vvi to2(3, vi(3, 0));
      FL(i, 0, q){
        char x, y;
        cin >> x >> y;
        int crx = x - 'a';
        int cry = y - 'a';
        to[crx][cry]++;
        avto[crx][cry]++;

        if (avto[1][2] > 0 && crx == 2 && cry == 0){
          to2[1][0]++;
          avto[1][2]--;
        }
        if (avto[2][1] > 0 && crx == 1 && cry == 0){
          to2[2][0]++;
          avto[2][1]--;
        }
      }
      FL(i, 0, n){
        if (s[i] == 'a'){
          continue;
        } else if (s[i] == 'b'){
          if (to[1][0] > 0){
            s[i] = 'a';
            to[1][0]--;
            continue;
          } else if (to2[1][0] > 0 && to[1][2] > 0 && to[2][0] > 0){
            s[i] = 'a';
            to[1][2]--;
            to[2][0]--;
            to2[1][0]--;
            continue;
          }
        } else {
          if (to[2][0] > 0){
            s[i] = 'a';
            to[2][0]--;
            continue;
          } else if (to2[2][0] > 0 && to[2][1] > 0 && to[1][0] > 0){
            s[i] = 'a';
            to[2][1]--;
            to[1][0]--;
            to2[2][0]--;
            continue;
          } else if (to[2][1] > 0){
            s[i] = 'b';
            to[2][1]--;
            continue;
          }
        }
      }
      cout << s << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

