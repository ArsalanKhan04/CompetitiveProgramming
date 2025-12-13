#include <bits/stdc++.h>
#include <iomanip>
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
#define vd vector<double>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define vd vector<double>
#define vvd vector<vd>

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define INF int(1e9) + 9
 
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

    int testcases = 1;
    // cin >> testcases;
    while(testcases--){
      int n;
      cin >> n;
      vi b(4, 0);
      int x;
      FL(i, 1, n + 1){
        cin >> x;
        b[x]++;
      }

      vector<vvd> dp1(n + 1, vvd(n + 1, vd(n + 1, 0)));
      vector<vvd> dp2(n + 1, vvd(n + 1, vd(n + 1, 0)));

      dp2[b[1]][b[2]][b[3]] = 1;
      FL(j, 0, n + 1){
        FL(k, 0, n + 1 - j){
          FF(l, n + 1 - (k + j), 0){
            vd prob(4, 0);
            vd val(4, 0);
            double t_prob = 0;
            if (j != n){
              val[1] = dp1[j+1][k][l] + (n / (j + k + l + 1.0));
              prob[1] = dp2[j+1][k][l] * ((j + 1.0) / (k + j + l + 1.0));
              t_prob += prob[1];
            }
            if (j != 0 && k != n){
              val[2] = dp1[j-1][k+1][l] + ((double)n / (j + k + l));
              prob[2] = dp2[j-1][k+1][l] * ((k + 1.0) / (k + j + l));
              t_prob += prob[2];
            }
            if (k != 0 && l != n){
              val[3] = dp1[j][k - 1][l+1] + ((double)n / (j + k + l));
              prob[3] = dp2[j][k-1][l+1] * ((l + 1.0) / (k + j + l));
              t_prob += prob[3];
            }
            if (t_prob != 0){
              dp2[j][k][l] = t_prob;
              dp1[j][k][l] += val[1] * (prob[1] / t_prob);
              dp1[j][k][l] += val[2] * (prob[2] / t_prob);
              dp1[j][k][l] += val[3] * (prob[3] / t_prob);
            }
          }
        }
      }
      dbg(dp1[1][1][0]);
      dbg(dp2[1][1][0]);
      dbg(dp1[2][0][0]);
      dbg(dp2[2][0][0]);
      dbg(dp1[0][1][0]);
      dbg(dp2[0][1][0]);
      dbg(dp1[1][0][0]);
      dbg(dp2[1][0][0]);
      dbg(dp1[0][0][0]);
      dbg(dp2[0][0][0]);
      /*
      FL(i, 0, n + 1){
        FL(j, 0, n - i + 1){
          FL(k, 0, n - (i + j) + 1){
            int l = n - (i + j + k);
            if (l < 0)
              continue;
            dbg(l);
            vd prob(4, 0);
            vd val(4, 0);
            double t_prob = 0;
            if (i != 0 && j != n){
              val[1] = dp1[j+1][k][l] + (n / (n - i + 1.0));
              prob[1] = dp2[j+1][k][l] * ((j + 1.0) / (k + j + l + 1));
              t_prob += prob[1];
            }
            if (j != 0 && k != n){
              val[2] = dp1[j-1][k+1][l] + ((double)n / (n - i));
              prob[2] = dp2[j-1][k+1][l] * ((k + 1.0) / (k + j + l));
              t_prob += prob[2];
            }
            if (k != 0 && l != n){
              val[3] = dp1[j][k - 1][l+1] + ((double)n / (n - i));
              prob[3] = dp2[j][k-1][l+1] * ((l + 1.0) / (k + j + l));
              t_prob += prob[3];
            }
            if (t_prob != 0){
              dp2[j][k][l] = t_prob;
              dp1[j][k][l] += val[1] * (prob[1] / t_prob);
              dp1[j][k][l] += val[2] * (prob[2] / t_prob);
              dp1[j][k][l] += val[3] * (prob[3] / t_prob);
            }
          }
        }
      }
      */
      cout << setprecision(15) << dp1[0][0][0] << endl;

      

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

