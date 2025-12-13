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

const int MAXN = 1e5+1;
const int K = log(MAXN);

// need to get mn and mx both

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

    vvi stmn(K + 1, vi(MAXN,0));
    vvi stmx(K + 1, vi(MAXN,0));

    int lg[MAXN]; lg[1]=0;
    FL(i,2,MAXN) lg[i]=lg[i/2]+1;

    int n; cin >> n;
    vi a(n);
    FL(i,0,n) cin>>a[i];
  
    stmn[0] = a;
    stmx[0] = a;
    FL(i,1,K+1){
      FL(j,0,n-(1<<i)+1){
        stmn[i][j]=min(stmn[i-1][j],stmn[i-1][j+(1<<(i-1))]);
        stmx[i][j]=max(stmx[i-1][j],stmx[i-1][j+(1<<(i-1))]);
      }
    }

    int q; cin>>q;
    while(q--){
      int l,r; cin>>l>>r;
      double mnq, mxq=0;
      int lgn = lg[r-l+1];
      mnq = min(stmn[lgn][l], stmn[lgn][r-(1<<lgn)+1]);
      dbg(mnq);
      if (l-1 > 0){
        lgn = lg[l];
        mxq = max(stmx[lgn][0], stmx[lgn][l-(1<<lgn)]);
      }
      if (r + 1 < n){
        lgn = lg[n-1-r];
        mxq = max(mxq, max(stmx[lgn][r+1], stmx[lgn][n-(1<<lgn)])/1.0);
      }
      lgn = lg[r-l+1];
      mxq = max(mxq, (max(stmx[lgn][l], stmx[lgn][r-(1<<lgn)+1]) - mnq)/2.0);
      cout << setprecision(9) <<  mnq + mxq << endl;
    }

#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

