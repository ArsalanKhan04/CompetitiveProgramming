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
      string a, b;
      cin >> a >> b;
      
      vi c(n);
      ll ons = 0;
      FL(i, 0, n){
        c[i] = a[i] != b[i];
        ons += c[i];
      }
      if (ons == 0){
        cout << 0 << endl;
        continue;
      }
      vector<deque<char>> xrs(n);
      bool flag = false;
      // pick the first 1, if it has a 1 on its c position, take xor with the next 1
      // after that use that 1 for every value
      int x = 0;
      int fst = -1;
      int scd = -1;
      while (x < n){
        if (a[x] == '1'){
          if (fst == -1)
            fst = x;
          scd = x;
        }
      }
      if (scd == -1 || fst == scd && c[fst] == 1){
        cout << -1 << endl;
        continue;
      }

      vi mvs;

      if (c[fst] == 1){ // if c[fst] == 1 that automatically means fst != scd
        FL(i, scd - fst, n){
          if (a[scd] == '1')
            c[fst + (i - scd)] =  !c[fst + (i - scd)];
        }
        mvs.pb(fst - scd);
      }

      // now we have final c and we can use fst b to fix this
      FL(i, 0, n){
        FL(j, fst, n){
          xrs[i].push_back(a[j]);
        }
      }
      FL(i, 0, n){
        FL(j, 0, i){
          xrs[i].push_front('0');
        }
      }


      FL(i, 0, n){
        if (c[i]){
          mvs.pb(i - fst);         

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

