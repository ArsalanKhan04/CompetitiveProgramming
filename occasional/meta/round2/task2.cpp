#include <bits/stdc++.h>
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
#define vll vector<ll>
#define vvll vector<vll>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

#define REMAX(a, b) a = max((a), (b))
#define REMIN(a, b) a = min((a), (b))

#define pm(x)  cout << "Case #" << x << ": ";

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

    int mx = 1e6;
    int testcases = 1;
    cin >> testcases;
    FL(et, 1, testcases + 1) {
      int n, m; cin >> n >> m;
      vi a(n); vi b(m);
      FL(i,0,n) cin >> a[i];
      FL(i,0,m) cin >> b[i];

      vi scr(mx + 1, 0);
      FL(i,0,n) scr[a[i]]++;
      vi sc;
      FL(i,0,mx + 1) if (scr[i] > 0) sc.push_back(scr[i]);
      reverse(ALL(sc));

      vi b2(mx + 2, 0);
      FL(i, 0, m){
        b[0]++;
        b[b[i]+1]--;
      }
      FL(i,1,mx+2){
        b2[i] += b2[i-1];
      }


      auto f = [&](int x){
        priority_queue<pair<int, int>> pq;
        FL(i,0,m) if (b[i] > 0) pq.push({b[i], i});

        int ind = 0;
        pii cbi = {0, 0};
        FL(i,0,x){ // each prize category
          int cr = x - i; // prize to give to each ind
          FL(j, 0, sc[i]){ // for each person in that prize categ
            
          }



        }



        ll tvl = 0;
        ll sm = 0;
        FL(i,0,x){
          tvl += sc[ind];
          sm += (ll) sc[ind] * (x-i);
        }
        ll csm = 0;
        FL(i,0,m){
          csm += min((ll)b[i], tvl);
        }
        if (csm < sm){
          return false;
        }
        return true;
      };

      // sc made
      //
      int lw = 1;
      int hg = sc.size();
      while (lw <= hg){
        int md = lw + (hg-lw)/2;
        if (f(md)) lw = md + 1;
        else hg = md - 1;
      };
      ll an = 0;
      FL(i,0,hg) an += sc[i];


      pm(et);
      cout << an << endl;
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}


