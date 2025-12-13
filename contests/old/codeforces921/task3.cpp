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
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
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

    int testcases = 1;
    cin >> testcases;
    while(testcases--){
      int n, k, m;
      cin >> n >> k >> m;
      string s;
      cin >> s;
      string t = "";
      int count = 0;
      int x = 0;
      int l_i = -1;
      FL(i, 0, n){
        count = 0;
        vb check(k, false);
        while (x < m && count < k){
          if (s[x] - 'a' >= k){
            x++;
            continue;
          }
          if(!check[s[x]-'a']){
            count++;
            check[s[x]-'a'] = true;
          }
          if (count == k){
            t += s[x];
            l_i = x;
          }
          x++;
        }
        if (x > m)
          break;
      }
      dbg(t);
      if (t.size() >= n){
        cout << "YES" << endl;
        continue;
      }
      vb check(k, false);
      FL(i, l_i + 1, m){
        if (s[i] - 'a' >= k)
          continue;
        check[s[i]-'a'] = true;
      }
      FL(i, 0, k){
        if (check[i] == 0){
          t += 'a' + i;
          break;
        }
      }
      while (t.size() < n)
        t += 'a';
      cout << "NO" << endl;
      cout << t << endl;


    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

