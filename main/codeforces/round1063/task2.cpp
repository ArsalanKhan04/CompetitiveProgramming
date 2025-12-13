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
      int n;
      cin >> n;
      vi a(n);
      FL(i, 0, n)
        cin >> a[i];
      string x;
      cin >> x;
      string s = "";
      FL(i,0,n) s+='0';
      int mx, on;
      FL(i,0,n){
        if (a[i] == n) mx = i;
        if (a[i] == 1) on = i;
      }
      set<pii> ans;
      int l = 0;
      int r = n-1;
      while (l < n-1 && a[l+1] > a[l]) l++;
      while (r > 0 && a[r-1] > a[r]) r--;
      dbg(l, r);
      if (l < on){
        ans.insert({l+1, on+1});
        FL(i, l+1, on){
          if (a[i] <= max(a[on], a[l]) && a[i] >= min(a[on], a[l]))
            s[i] = '1';
        }
      }
      if (r > on){
        ans.insert({on+1, r+1});
        FL(i, on+1, r){
          if (a[i] <= max(a[on], a[r]) && a[i] >= min(a[on], a[r]))
            s[i] = '1';
        }
      }
      dbg(l, r);
      l = 0;
      r = n - 1;
      while (l < n-1 && a[l+1] < a[l]) l++;
      while (r > 0 && a[r-1] < a[r]) r--;
      dbg(l, r);
      if (l < mx){
        ans.insert({l+1, mx+1});
        FL(i, l+1, mx){
          if (a[i] <= max(a[mx], a[l]) && a[i] >= min(a[mx], a[l]))
            s[i] = '1';
        }
      }
      if (r > mx){
        ans.insert({mx+1, r+1});
        FL(i, mx+1, r){
          if (a[i] <= max(a[mx], a[r]) && a[i] >= min(a[mx], a[r]))
            s[i] = '1';
        }
      }
      if (mx < on) swap(on, mx);
      ans.insert({on+1, mx+1});
      FL(i,on+1, mx){
        if (a[i] <= max(a[mx], a[on]) && a[i] >= min(a[mx], a[on]))
          s[i] = '1';
      }
      bool fl = true;
      FL(i,0,n){
        if (x[i] == '1' && s[i] != '1') fl = false;
      }
      dbg(x, s);
      if (fl){
        cout << ans.size() << endl;
        for (auto [xa, ya]: ans){
          cout << xa << " " << ya << endl;
        }
      } else {
        cout << -1 << endl;
      }


    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

