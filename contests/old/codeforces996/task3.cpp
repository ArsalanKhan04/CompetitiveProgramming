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
      int n, m;
      cin >> n >> m;
      vvll a(n, vll(m));
      string s;
      cin >> s;
      FL(i, 0, n)
        FL(j, 0, m)
          cin >> a[i][j];
      ll tot = 0;
      FL(i, 0, n){
        FL(j, 0, m){
          tot += a[i][j];
        }
      }
      vll v(n);
      vll h(m);
      FL(i, 0, n){
        ll xx = 0;
        FL(j, 0, m){
          xx += a[i][j];
        }
        v[i] = xx;
      }
      FL(j, 0, m){
        ll xx = 0;
        FL(i, 0, n){
          xx += a[i][j];
        }
        h[j] = xx;
      }

      int k = 0, l = 0;
      int z = 5;
      FL(x, 0, n + m - 1){
        if (s[x] == 'R'){
          a[k][l] = z-h[l];
          v[k] += z-h[l];
          h[l] += z-h[l];
          l++;
        } else {
          a[k][l] = z-v[k];
          h[l] += z-v[k];
          v[k] += z-v[k];
          k++;
        }
      }


      FL(i, 0, n){
        FL(j, 0, m){
          cout << a[i][j] << " ";
        }
        cout << endl;
      }





    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

