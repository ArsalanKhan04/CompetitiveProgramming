
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
      dbg(n,k);
      vi a(n); vi b(k);
      FL(i, 0, n)
        cin >> a[i];
      FL(i,0,k) {
        cin >> b[i];
        b[i]--;
      }
      sort(ALL(b));
      int bind=0;

      dbg("HERE");
      vi c;
      int pr = -1;
      FL(i,0,n){
        if (a[i]!=pr){
          c.pb(a[i]);
        }
        if (bind<k && i==b[bind]){
          c.back()=2; bind++;
        }
        pr=a[i];
      }


      pr=a[b.back()];
      dbg(pr, c.size());
      if (c.front()==pr) c.erase(c.begin(),c.begin()+1);
      dbg(c.front(), pr, c.size());
      int cnt = 0; int an = 0;
      bool dec = false;
      while (c.size()){
        if (c.back()==2) b.pop_back();
        if (dec && cnt > 0){
          cnt--;
          c.pop_back();
          if (!cnt) dec=false;
          continue;
        }
        if (c.back() == pr && b.size() && !cnt) {
          dbg("POPPED");
          c.pop_back();
          continue;
        }
        if (c.back() == 2){
          if (cnt){ 
            cnt |= 1;
            dec=true;
            an+=cnt+1;
          }
          c.pop_back();
          continue;
        }
        cnt++;
        c.pop_back();
      }
      if (!dec)
        an+=cnt;
      cout << an << endl;


        
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

