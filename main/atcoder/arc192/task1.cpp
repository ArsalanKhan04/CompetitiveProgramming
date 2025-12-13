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
    // cin >> TCS;
    while(TCS--){
      int n;
      cin >> n;
      vi a(n);
      FL(i, 0, n)
        cin >> a[i];
      // if a[i] = 0 and a[i+1] = 0 and a[i+2] = 1 then move to a[i+2]
      // if a[i] = 0 and a[i+1] = 0 and a[i-1] = 1 then move to 
      vi done(n, -1);
      FL(i, 0, n){
        if (a[i] == 0 && (a[(i+1)%n] == 0) && (a[(i+2)%n] == 1)){
          done[i] = 1;
          done[(i+1)%n] = 2;
          done[(i+2)%n] = 3;
          a[i] = 1;
          a[(i+1)%n] = 1;
        }
      }
      FL(i, 0, n){
        if (a[i] == 1 && (a[(i+1)%n] == 0) && (a[(i+2)%n] == 0)
            && (done[i] == -1 || done[i] == 3)){
          done[i] = 3;
          done[(i+1)%n] = 2;
          done[(i+2)%n] = 1;
          a[(i+1)%n] = 1;
          a[(i+2)%n] = 1;
        }
      }
      bool flag = true;
      FL(i, 0, n){
        if (a[i] == (a[(i+1)%n]) && a[i] == 0){
          flag = false;
          break;
        }
      }
      if (!flag){
        cout << "No" << endl;
        continue;
      }
      FL(i, 0, n){
        if (a[i] == 0){
          if (done[(i + n - 1)%n] == 3){
            if (done[(i + 1) % n] == 3){
              flag = false;
              break;
            } else {
              done[(i + 1) % n] = 1;
            }
          } else if (done[(i + n - 1)%n] == 1){
            if (done[(i + 1) % n] == 1){
              flag = false;
              break;
            } else {
              done[(i + 1) % n] = 3;
            }
          }
        }
      }
      if (flag){
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

