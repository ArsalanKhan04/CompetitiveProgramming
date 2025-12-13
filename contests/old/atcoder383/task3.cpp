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
    int h, w, d;
    cin>>h>>w>>d;
    vvi a(h, vi(w, false));
    string s;
    FL(i, 0, h){
      cin >> s;
      FL(j, 0, w){
        if (s[j] == 'H') a[i][j] = 2; else if (s[j] == '.') a[i][j] = 1;
        else a[i][j] = 0;
      }
    }

    vvb visit(h, vb(w, false));
    vvi val(h, vi(w, 0));
    auto dfs1 = [&](auto &&self, int x, int y){
      if (x < 0 || x >= h || y < 0 || y>=w)
        return 0;
      if (!a[x][y] || visit[x][y]){
        return val[x][y] - 1;
      }
      if (a[x][y] == 2){
        val[x][y] = d + 1;
      }
      visit[x][y] = true;
      REMAX(val[x][y],self(self, x-1, y));
      REMAX(val[x][y],self(self, x, y - 1));
      REMAX(val[x][y],self(self, x + 1, y));
      REMAX(val[x][y],self(self, x, y + 1));
      return val[x][y] - 1;
    };

    vvb visit2(h, vb(w, false));
    auto dfs2 = [&](auto &&self, int x, int y, int prev){
      if (x < 0 || x >= h || y < 0 || y>=w)
        return;
      if (!a[x][y]) return;
      REMAX(val[x][y], prev);
      if (visit2[x][y]){
        return;
      }
      visit2[x][y] = true;
      self(self, x - 1, y, val[x][y] - 1);
      self(self, x, y - 1, val[x][y] - 1);
      self(self, x + 1, y, val[x][y] - 1);
      self(self, x, y + 1, val[x][y] - 1);
    };
    FL(i, 0, h){
      FL(j, 0, w){
        dfs1(dfs1, i, j);
      }
    }
    FL(i, 0, h){
      FL(j, 0, w){
        dfs2(dfs2, i, j, 0);
      }
    }
    FL(i, 0, h){
      FL(j, 0, w){
        cerr << val[i][j] << " \n"[j==w-1];
      }
    }
    int tot = 0;
    FL(i, 0, h){
      FL(j, 0, w){
        if (val[i][j] > 0) tot++;
      }
    }
    cout << tot << endl;

#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

