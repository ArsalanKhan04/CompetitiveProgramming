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
      int a[3]; cin>>a[0]>>a[1]>>a[2]; // R, G, B
      vi so;
      auto f=[&](){
        vb sl={true, true, true};
        if (so.empty()) return sl;
        sl[so.back()]=false;
        if (so.size()>2){
          sl[so[so.size()-3]]=false;
        }
        return sl;
      };

      auto g=[&](){
        vb sl=f();
        vpii cnd;
        // cout << a[0] << a[1] << a[2] << endl;
        FL(i,0,3){
          if (sl[i] && a[i]>0)
            cnd.pb({a[i], i});
        }
        if (cnd.empty()) {
          return -1;
        }
        dbg(cnd.size());
        sort(RALL(cnd));
        return cnd[0].S;
      };

      while (true){
        int cr=g();
        dbg(cr);
        if (cr==-1) break;
        a[cr]--;
        so.pb(cr);
        if (a[0]==a[1] && a[1]==a[2]) break;
      }
      map<string, string> mp;
      mp["R"]="GRB";
      mp["B"]="GBR";
      mp["G"]="RGB";
      mp["GR"]="GRB";
      mp["GB"]="GBR";
      mp["RG"]="RGB";
      mp["RB"]="RBG";
      mp["BG"]="BGR";
      mp["BR"]="BRG";

      string an="RGB";
      string s="";
      for (auto cr: so){
        s+=an[cr];
      }
      while (a[0]>0 && a[1]>0 && a[2]>0){
        FL(i,0,3) a[i]--;
        // cout << a[0] << a[1] << a[2] << endl;
        if (s.size()==0) {
          s+="RGB";
        } else if (s.size()==1){
          s+=mp[s.substr(s.size()-1, 1)];
        } else{
          s+=mp[s.substr(s.size()-2, 2)];
        }
      }

      cout << s << endl;





    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

