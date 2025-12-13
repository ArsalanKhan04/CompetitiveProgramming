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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct P { int r, c; };

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  P st, en, lz;
  vector<P> mrs;
  int im = 0;

  vvi mid(55, vi(55, -1));

  FL(i, 0, n) {
    cin >> g[i];
    FL(j, 0, m) {
      if (g[i][j] == 'S') st = {i, j};
      else if (g[i][j] == 'T') en = {i, j};
      else if (g[i][j] == 'L') lz = {i, j};
      else if (g[i][j] == '/' || g[i][j] == '\\') {
        if (g[i][j] == '\\') im |= (1 << mrs.size());
        mid[i][j] = mrs.size();
        mrs.pb({i, j});
      }
    }
  }

  int k = mrs.size();
  ll vc = 0;
  int mc = INT_MAX;

  FL(msk, 0, (1 << k)) {
    bool bad[55][55];
    bool v1[55][55][4]; 
    memset(bad, 0, sizeof(bad));
    memset(v1, 0, sizeof(v1));

    FL(sd, 0, 4) {
      int r = lz.r + dx[sd];
      int c = lz.c + dy[sd];
      int dir = sd;

      while (true) {
        if (r < 0 || r >= n || c < 0 || c >= m || g[r][c] == '#') break;
        
        if (v1[r][c][dir]) break;
        v1[r][c][dir] = true;

        bad[r][c] = true;

        if (mid[r][c] != -1) {
          int idx = mid[r][c];
          bool tb = (msk >> idx) & 1;
          if (tb) dir ^= 1; 
          else dir ^= 3;
        }
        r += dx[dir];
        c += dy[dir];
      }
    }

    if (bad[st.r][st.c] || bad[en.r][en.c]) continue;

    vector<vb> v2(55, vb(55, false));
    queue<P> q;
    
    q.push(st);
    v2[st.r][st.c] = true;
    bool ok = false;

    while (!q.empty()) {
      P curr = q.front(); q.pop();
      if (curr.r == en.r && curr.c == en.c) {
          ok = true;
          break;
      }

      FL(d, 0, 4) {
        int nr = curr.r + dx[d];
        int nc = curr.c + dy[d];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
          char c = g[nr][nc];
          bool obs = (c == '#' || c == 'L'); 
          
          if (!v2[nr][nc] && !bad[nr][nc] && !obs) {
            v2[nr][nc] = true;
            q.push({nr, nc});
          }
        }
      }
    }

    if (ok) {
      vc++;
      int cst = __builtin_popcount(msk ^ im);
      REMIN(mc, cst);
    }
  }

  if (mc == INT_MAX) mc = -1;
  cout << vc << " " << mc << endl;
  return 0;
}
