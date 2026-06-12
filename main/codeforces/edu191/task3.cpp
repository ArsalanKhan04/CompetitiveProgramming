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
      int n, k; cin >> n >> k; string s; cin >> s;
      string ans = "";
      FL(i,0,n) ans += "0";

      int st = 0; int sm = 0;
      FL(i,0,n){
        if (k == 0) break;

        dbg("prv", i, sm);
        if (sm < 0){
          if (s[i] == '('){
            FL(j,st,i){
              if (k == 0) break;
              if (s[j]=='('){
                ans[j]='1';
                k--;
              }
            }
            sm = 0;
            st = i;
          } else {
            sm--;
            continue;
          }
        }

        if (s[i] == '(') sm++;
        else sm--;
        dbg("nxt", i, sm);
      }
      dbg(sm, st);

      if (sm <= 0){
        FL(j,st,n){
          if (k == 0) break;
          if (s[j]=='('){
            ans[j]='1';
            k--;
          }
        }
      } else {
        FL(j,st,n){
          if (k == 0) break;
          if (s[j]==')'){
            ans[j]='1';
            k--;
          }
        }
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

