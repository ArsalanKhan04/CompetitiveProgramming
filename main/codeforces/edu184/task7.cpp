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
#ifdef KRAKAR
  ifstream fileIn("input.txt"); 
  cin.rdbuf(fileIn.rdbuf()); 
  ofstream fileOut("output.txt"); 
  cout.rdbuf(fileOut.rdbuf()); 
  auto _clock_start = chrono::high_resolution_clock::now();
#else
  cin.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  P st, en, lz;
  vector<P> mrs;
  int im = 0;

  FL(i, 0, n) {
    cin >> g[i];
    FL(j, 0, m) {
      if (g[i][j] == 'S') st = {i, j};
      else if (g[i][j] == 'T') en = {i, j};
      else if (g[i][j] == 'L') lz = {i, j};
      else if (g[i][j] == '/' || g[i][j] == '\\') {
        if (g[i][j] == '\\') im |= (1 << mrs.size());
        mrs.pb({i, j});
      }
    }
  }

  int k = mrs.size();
  ll vc = 0;
  int mc = INT_MAX;

  FL(msk, 0, (1 << k)) {
    vvb bad(55, vb(55, false));
    vector<vvb> v1(55, vvb(55, vb(4, false)));

    FL(sd, 0, 4) {
      int r = lz.r;
      int c = lz.c;
      int dir = sd;
      
      r += dx[dir];
      c += dy[dir];

      while (true) {
        if (r < 0 || r >= n || c < 0 || c >= m || g[r][c] == '#') break;
        
        if (v1[r][c][dir]) break;
        v1[r][c][dir] = true;

        bad[r][c] = true;

        char cell = g[r][c];
        bool ism = (cell == '/' || cell == '\\');
        
        if (ism) {
          int idx = -1;
          FL(z,0,k) if(mrs[z].r == r && mrs[z].c == c) { idx = z; break; }
          
          bool tb = (msk >> idx) & 1;

          if (tb) dir ^= 1; 
          else dir ^= 3;
        }

        r += dx[dir];
        c += dy[dir];
      }
    }

    if (bad[st.r][st.c] || bad[en.r][en.c]) continue;

    vvb v2(55, vb(55, false));
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
          char cell = g[nr][nc];
          bool obs = (cell == '#' || cell == 'L' || cell == '/' || cell == '\\');
          
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

#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}
