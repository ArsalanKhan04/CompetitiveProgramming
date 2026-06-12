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
      int n, q; cin>>n>>q;
      string s; cin>>s;
      int qs = count(ALL(s), '?');

      map<string, int> scrs;

      // three ones
      scrs["III"] = -2;
      scrs["IIL"] = 0;
      scrs["LII"] = 0;
      scrs["LIL"] = 2;

      // starts
      scrs["SII"] = 0;
      scrs["SIL"] = 2;

      // ends
      scrs["IIE"] = -2;
      scrs["LIE"] = 0;

      string t = s;
      int scr = 0;
      FL(i,0,n){
        if (t[i] == '?') t[i] = 'I';
        if (t[i] == 'I') scr++;
        if (i > 0 && t[i-1] == 'I' && t[i] != 'I'){
          scr -= 2;
        }
      }

      vi dp(n+1);
      dp[n] = scr;

      FL(i,0,n){
        string cr = "";
        if (i == 0) cr += "S";
      }


      FL(i,0,n){

      }


      int tf[4] = {0}; 
      tf[0] = count(ALL(s), 'X');
      tf[1] = count(ALL(s), 'V');
      tf[2] = count(ALL(s), 'I');

      FL(i,0,n-1){
        if (s[i] == 'I' && s[i+1]!='?'){
          tf[3]++;
        }
      }
      tf[2] -= tf[3];

      int ef[3] = {0};
      FL(i,0,n-1){
        if (s[i] == '?' && s[i+1] != '?' && s[i+1] != 'I'){
          ef[0]++;
          s[i] = 'x';
        }
      }
      FL(i,0,n-1){
        if (s[i] == '?' && s[i+1] == '?'){
          ef[1]++;
        }
      }

      int c[3];
      while(q--){
        cin >> c[0]>>c[1]>>c[2];
        int t[4] = {tf[0], tf[1], tf[2], tf[3]};
        int e[2] = {ef[0], ef[1]};
        int nq = qs;
        for (int i = 2; i >= 0; i--){
          c[i] -= max(0, c[i]-nq);
          nq -= c[i];
        }
        dbg(c[0], c[1], c[2]);
        dbg(e[0], e[1]);
        assert(accumulate(c, c+3, 0) == qs);

        int dn = min(e[0], c[2]);
        c[2] -= dn;
        t[3] += dn;

        dn = min(e[1], min(c[2], c[1]));
        e[1] -= dn;
        c[2] -= dn; c[1] -= dn;
        t[3] += dn; t[1] += dn;
        
        dn = min(e[1], min(c[2], c[0]));
        c[2] -= dn; c[0] -= dn;
        t[3] += dn; t[0] += dn;

        t[0] += c[0];
        t[1] += c[1];
        t[2] += c[2];
        dbg(t[0], t[1], t[2], t[3]);

        cout << t[0] * 10 + t[1] * 5 + t[2] * 1 + t[3] * -1 << endl;

      }
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

