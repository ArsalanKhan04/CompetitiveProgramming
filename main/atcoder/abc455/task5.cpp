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
      string s; cin >> s;
      s="$"+s;
      // ab, bc, ac, abc
      map<ll, ll> mp;
      ll ab=0; ll cr=0; mp.clear();
      mp[0]=1;
      FL(i,1,n+1){
        if (s[i]=='A'){
          cr++;
        } else if (s[i]=='B'){
          cr--;
        }
        if (mp.find(cr)!=mp.end()) ab+=mp[cr];
        mp[cr]++;
      }
      ll bc=0; cr=0; mp.clear();
      mp[0]=1;
      FL(i,1,n+1){
        if (s[i]=='B'){
          cr++;
        } else if (s[i]=='C'){
          cr--;
        }
        if (mp.find(cr)!=mp.end()) bc+=mp[cr];
        mp[cr]++;
      }
      ll ac=0; cr=0; mp.clear();
      mp[0]=1;
      FL(i,1,n+1){
        if (s[i]=='A'){
          cr++;
        } else if (s[i]=='C'){
          cr--;
        }
        if (mp.find(cr)!=mp.end()) ac+=mp[cr];
        mp[cr]++;
      }


      map<pair<ll,ll>, ll> mp2;
      ll abc=0; ll cr1=0; ll cr2=0;
      mp2[{0,0}]=1;
      FL(i,1,n+1){
        if (s[i]=='A'){
          cr1++;
        } else if (s[i]=='C'){
          cr1--;
        }
        if (s[i]=='B'){
          cr2++;
        } else if (s[i]=='C'){
          cr2--;
        }
        if (mp2.find({cr1, cr2})!=mp2.end()) abc+=mp2[{cr1, cr2}];
        mp2[{cr1, cr2}]++;
      }
      dbg(ab, bc, ac, abc);
      cout << ((ll)((ll)n * (n+1)) / 2)-(ab+bc+ac-2*abc) << endl;



    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

