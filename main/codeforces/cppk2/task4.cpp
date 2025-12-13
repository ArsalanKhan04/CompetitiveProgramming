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
#define vll vector<ll>
#define vvll vector<vll>

#define REMAX(a, b) a = max((a), (b))
#define REMIN(a, b) a = min((a), (b))

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

    int testcases = 1;
    // cin >> testcases;
    while(testcases--){
      int n;
      cin >> n;
      string s1, s2;
      vi a(n, 0);
      FL(i, 0, n){
        cin >> s1 >> s2;
        if (s1 == "set")
          a[i] = 2;
        if (s2 == "true")
          a[i] += 1;
      }
      int aa = -1, ba = -1;
      FL(i, 0, n){
        if (a[i] == 3)
          aa = i;
        else if (a[i] == 1)
          ba = i;
      }
      if (aa == -1 && ba!=-1){
        cout << -1 << endl;
        return 0;
      }

      vi ind(n, 0);
      vvi dag(n, vi());
      if (aa != -1){
        dag[aa].pb(ba);
        ind[ba]++;
      }
      FL(i, 0, n){
        if (a[i] == 2){
          if (aa == -1){
            cout << -1 << endl;
            return 0;
          } else {
            dag[aa].pb(i);
            ind[i]++;
          }
          if (ba != -1){
            dag[i].pb(ba);
            ind[ba]++;
          }
        }
      }
      int m;
      cin >> m;
      int X, Y;
      vb ed(n, false);
      while(m--){
        cin >> X >> Y;
        X--; Y--;
        dag[X].pb(Y);
        ind[Y]++;
        if ((a[X] & 2) && (a[Y]==0)){
          if (ba == -1){
            cout << -1 << endl;
            return 0;
          }
          ed[Y] = true;
          dag[ba].pb(Y);
          ind[Y]++;
        }
      }
      deque<int> qq;
      FL(i, 0, n){
        if (ind[i] == 0){
          if (a[i] & 2)
            qq.push_back(i);
          else 
            qq.push_front(i);
        }
      }
      int curr = 0;
      vi ans(n);
      while (!qq.empty()){
        int tmp = qq.front();
        qq.pop_front();
        for (int v: dag[tmp]){
          ind[v]--;
          if (ind[v] == 0){
            if (a[v] & 2)
              qq.push_back(v);
            else 
              qq.push_front(v);
          }
        }
        ans[curr++] = tmp;
      }
      if (curr != n){
        cout << -1 << endl;
        return 0;
      }
      FL(i, 0, n){
        cout << ans[i] + 1 << " \n"[i==n-1];
      }
    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

