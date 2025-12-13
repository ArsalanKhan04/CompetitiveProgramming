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
      vvi a(n + 1, vi(n + 1));
      FL(i, 1, n + 1){
        FL(j, 1, n + 1){
          a[i][j] = i + j;
        }
      }
      vvi b(n + 1, vi(n + 1));
      FL(i, 1, n + 1){
        FL(j, 1, n + 1){
          cin >> b[i][j];
        }
      }
      vi cnta(2 * n + 1, 0);
      FL(i, 1, n + 1){
        FL(j, 1, n + 1){
          cnta[a[i][j]]++;
        }
      }
      vi mpF(n + 1, 0); vi mpS(n + 1, 0);
      FL(i, 1, n + 2){ mpF[cnta[i]] = i; }
      FL(i, n + 1, 2 * n + 1){ mpS[cnta[i]] = i; }
      vi cntb(2 * n + 1, 0);
      FL(i, 1, n + 1){
        FL(j, 1, n + 1){
          cntb[b[i][j]]++;
        }
      }
      int rw_2 = -1;
      FL(i, 1, n + 1){
        FL(j, 1, n + 1){
          if (cntb[b[i][j]] == 1){
            rw_2 = i;
            break;
          }
        }
        if (rw_2 != -1) break;
      }

      vi cnvt1(2 * n + 1, -1);
      vi cnvt2(2 * n + 1, -1);
      vi vis(2 * n + 1, false);
      FL(j, 1, n + 1){
        cnvt1[b[rw_2][j]] = mpF[cntb[b[rw_2][j]]];
        cnvt2[b[rw_2][j]] = mpS[cntb[b[rw_2][j]]];
        vis[b[rw_2][j]] = true;
      }
      FL(i, 1, 2 * n + 1){
        if (vis[i]) continue;
        cnvt1[i] = mpS[cntb[i]];
        cnvt2[i] = mpF[cntb[i]];
      }
      bool flag = false;
      FL(j, 1, n + 1){
        if (cnvt1[b[1][j]] < cnvt2[b[1][j]]){
          flag = true;
          break;
        } else if (cnvt1[b[1][j]] > cnvt2[b[1][j]]){
          flag = false;
          break;
        }
      }
      FL(i, 1, n + 1){
        FL(j, 1, n + 1){
          if(flag)
            cout << cnvt1[b[i][j]] << " \n"[j==n];
          else
            cout << cnvt2[b[i][j]] << " \n"[j==n];
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

