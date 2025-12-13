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
      string s;
      cin >> s;
      int n = s.size();
      s = "$" + s;
      vi eq(n + 1, 0);
      FL(i, 1, n + 1){
        if (s[i] == s[n+1-i]){
          eq[i] = 1;
          eq[n+1-i] = 1;
        }
      }
      // prefix sum calculation
      vi peq(n + 1, 0);
      FL(i, 1, n + 1){
        peq[i] = peq[i-1] + eq[i];
      }
      vvi pref(26, vi(n + 1, 0));
      FL(i, 1, n + 1){
        pref[s[i] - 'a'][i]++;
      }
      FL(i, 0, 26){
        FL(j, 1, n + 1){
          pref[i][j] += pref[i][j-1];
        }
      }


      auto f = [&](int i, int j)->bool{
        if (peq[min(i-1, n - j)] != min(i - 1, n - j)){
          return false;
        }
        bool od = false;
        if (2*j >= n && !(min(2 * j - n, n - 2 * i + 2) & 1)){
          od = true;
        }
        dbg(od);
        FL(x, 0, 26){
          // check values (i to j)
          int mvm = pref[x][j] - pref[x][i-1];
          int cns;
          if (i > n - j + 1){
            cns = pref[x][i-1] - pref[x][n-j];
          } else{
            cns = pref[x][n - i + 1] - pref[x][max(j, n-j)];
          }
          dbg(mvm, cns);
          mvm -= cns;
          if (mvm < 0){
            return false;
          }
          if (mvm & 1){
            if (od){ 
              dbg("FALSE");
              return false;
            }
            od = true;
          }
        }
        if (2 * j <= n){
          if (peq[n-j] - peq[j] < n - j - j){
            return false;
          }
        }
        return true;
      };

      auto chck = [&](int x){
        if (peq[n] - peq[0] == n) return true;
        FL(i, 1, ((n + 1) / 2) + 1){
          if (f(i, min(n, i + x - 1))){
            return true;
          }
        }
        return false;
      };

      int lw = 0;
      int hg = n;
      int md;
      while (lw <= hg){
        md = lw + (hg - lw) / 2;
        if (chck(md)){
          hg = md - 1;
        } else {
          lw = md + 1;
        }
      }
      cout << lw << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

