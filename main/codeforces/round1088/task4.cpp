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
      int n, k;
      cin >> n >> k;
      vi a(n); vi b(n);
      FL(i, 0, n)
        cin >> a[i];
      FL(i, 0, n)
        cin >> b[i];
      
      // case 1
      vi c(k,-1);
      bool fl1 = true;
      FL(i,0,n){
        if (i-k >= 0 && a[i] != a[i-k]){
          c[i%k]=-2;
        } 
      }
      dbg(fl1);

      FL(i,0,n){
        if (b[i]!=-1 && c[i%k]!=-2){
          if (c[i%k]!=-1 && c[i%k]!=b[i]){
            fl1 = false;
          }
          c[i%k]=b[i];
        }
      }
      dbg(fl1);
      map<int, int> mp;
      FL(i,0,k) if (c[i] != -2) mp[a[i]]++;
      FL(i,0,k){
        if (c[i] != -1 && c[i] != -2){
          if (mp[c[i]] == 0) fl1 = false;
          mp[c[i]]--;
        }
      }
      FL(i,0,n){
        if(c[i%k]==-2 && b[i]!=-1 && a[i] != b[i]) fl1 = false;
      }
      dbg(fl1);

      // case 2
      bool fl2 = true;
      int md = max(2 * k - n, n&1);
      int lf=(n-md)/2; int rg=lf+md;

      mp.clear();
      FL(i,0,n){
        if (i >= lf && i < rg){
          mp[a[i]]++; continue;
        }
        if (b[i] != -1 && b[i] != a[i])fl2=false;
      }

      FL(i,lf,rg){
        if (b[i] != -1){
          if (mp[b[i]] == 0) fl2 = false;
          mp[b[i]]--;
        }
      }



      condprt(fl1||fl2);




    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

