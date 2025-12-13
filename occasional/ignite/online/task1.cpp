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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vvi a(n, vi(n, (int)1e9 + 5));
    FL(i, 0, n) a[i][i] = 0;

    FL(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = min(a[u][v], w);
        a[v][u] = min(a[v][u], w);
    }

    FL(kk, 0, n) {
        FL(i, 0, n) {
            FL(j, 0, n) {
                if (a[i][kk] < (int)1e9 + 5 && a[kk][j] < (int)1e9 + 5)
                    REMIN(a[i][j], a[i][kk] + a[kk][j]);
            }
        }
    }

    vi t(n), mask(n, 0);
    iota(ALL(t), 0);
    int ans = (int)1e9 + 5;

    function<void(int, int, int)> dfs = [&](int idx, int cnt, int rem) {
        if (rem == 0) {
            int res = 0;
            FL(i, 0, n) {
                int mn = (int)1e9 + 5;
                FL(j, 0, n) if (mask[j]) REMIN(mn, a[i][j]);
                REMAX(res, mn);
            }
            REMIN(ans, res);
            return;
        }
        if (cnt == n) return;
        mask[t[cnt]] = 1;
        dfs(idx + 1, cnt + 1, rem - 1);
        mask[t[cnt]] = 0;
        dfs(idx, cnt + 1, rem);
    };

    dfs(0, 0, k);
    cout << ans << endl;
}

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
    while (TCS--) {
        solve();
    }

#ifdef KRAKAR
    cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
        chrono::high_resolution_clock::now() - _clock_start).count() << "ms." << endl;
#endif

    return 0;
}

