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


    map<string, string> mp;
    map<char, string> mpc;
    auto f = [&](char a, string b){
      FL(i, 1, 5){
        string s = "";
        s += a;
        s += '0';
        s += ('0' + i);
        mp[s] = b;
      }
      mpc[a] = b;
    };
    f('A', "Competitions");
    f('B', "Entertainment");
    f('C', "Social Gatherings");
    f('D', "Dinners");
    f('E', "Processions");
    f('F', "Training Workshops");
    f('G', "Exams");

    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      string s;
      cin >> s;
      int n = s.size();
      int x = 0;
      string inv = "";
      map<string, int> mp2;
      while (x < n){
        string ns="";
        FL(i, 0, 3){
          if (x < n){
            ns += s[x];
            x++;
          }
        }
        if (ns.size() < 3) break;
        if (mp.find(ns) == mp.end()){
          inv = ns;
          break;
        }
        dbg(ns);
        mp2[ns] = 1;
      }
      if (inv != ""){
        cout << -1 << " " << inv << endl;
        continue;
      }
      ll ans = 0;
      for (auto [ky, vl]: mp2){
        ans += vl;
      }
      map<char, int> bC;
      cout << ans << " ";
      for (auto [ky, vl]: mp2){
        cout << ky << " ";
        bC[ky[0]]++;
      }
      char lstky;
      for (auto [ky, vl]: bC){
        lstky = ky;
      }
      for (auto [ky, vl]: bC){
        cout << vl << " " << mpc[ky] << " \n"[lstky==ky];
      }
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

