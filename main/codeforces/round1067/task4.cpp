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
      string s,t;
      cin >> s >> t;
      vb sb(n+1), tb(n+1);
      s = "%" + s;
      t = "%" + t;
      FL(i,1,n+1){
        sb[i] = s[i] == '1';
        tb[i] = t[i] == '1';
      }

      vpii mvs;
      int l = -1, r = -1;
      bool fl = true;

      // check if pair exists
      FL(i,2,n + 1){
        if (sb[i] == sb[i-1]){
          fl = false;
        }
      }
      auto fpr = [&]{
        FL(i,1,sb.size()){
          auto x = sb[i];
          cerr << x << "";
        }
        cerr << endl;
      };

      // flip to force making a pair
      if (fl){
        if (n & 1){
          mvs.pb({2, n - 1});
          FL(i,2,n){
            sb[i] = !sb[i];
          }
        } else {
          mvs.pb({1, n - 1});
          FL(i,1,n){
            sb[i] = !sb[i];
          }
        }
      }
      fpr();

      FL(i,2,n+1){
        if (sb[i] == sb[i-1]){
          l = i-1; r = i;
        }
      }

      // make into 0
      while (true){
        while (l > 1 && sb[l-1] == sb[l]){
          l--;
        }
        while (r < n && sb[r+1] == sb[r]){
          r++;
        }
        if (l == 1 && r == n) break;
        mvs.pb({l, r});
        FL(i,l,r+1){
          sb[i] = !sb[i];
        }
        fpr();
      }


      l = -1, r = -1;
      fl = true;
      FL(i,2,n+1){
        if (tb[i] == tb[i-1]){
          fl = false;
          l = i - 1;
          r = i;
        }
      }
      
      if (fl){
        int x = n;
        if (n & 1){
          if (sb[n] != tb[n]){
            mvs.pb({1, n});
            FL(i,1,n+1){
              sb[i] = !sb[i];
            }
            fpr();
          }
          x--;
        }
        FL(i,1,x){
          if (sb[i] == tb[i]){
            mvs.pb({i, x});
            FL(j,i,x+1){
              sb[j] = !sb[j];
            }
            fpr();
          }
        }
        mvs.pb({1, x-1});
        FL(i,1,x){
          sb[i] = !sb[i];
        }
        fpr();
      } else {
        // from 1 to l
        FL(i,1,l){
          if (sb[i] != tb[i]){
            mvs.pb({i, n});
            FL(j,i,n+1){
              sb[j] = !sb[j];
            }
            fpr();
          }
        }

        // from r to n
        for (int i = n; i > r; i--){
          if (sb[i] != tb[i]){
            mvs.pb({l, i});
            FL(j,l,i+1){
              sb[j] = !sb[j];
            }
            fpr();
          }
        }

        // l, r
        if (sb[l] != tb[l]){
          mvs.pb({l, r});
          sb[l] = !sb[l];
          sb[r] = !sb[r];
          fpr();
        }
      }


      cout << mvs.size() << endl;
      for (auto mv: mvs){
        cout << mv.F << " " << mv.S << endl;
      }



    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

