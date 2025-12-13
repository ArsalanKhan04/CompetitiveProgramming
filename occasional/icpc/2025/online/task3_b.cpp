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

struct E { int u, v, t; };
vi et[5005][5005];

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
        int n, m, d;
        if(!(cin >> n >> m >> d)) break;
        vector<E> a(m);
        FL(i,0,n) FL(j,0,n) et[i][j].clear();

        FL(i,0,m) {
            cin >> a[i].u >> a[i].v >> a[i].t;
            et[a[i].u][a[i].v].pb(a[i].t);
        }

        sort(ALL(a), [](const E& x, const E& y){ return x.t < y.t; });
        FL(i,0,n) FL(j,0,n) sort(ALL(et[i][j]));

        ll t1 = 0, t2 = 0, t3 = 0;
        
        auto qc = [&](int u, int v, int mn, int mx) {
            if(mn >= mx) return 0;
            const vi& vec = et[u][v];
            return (int)(upper_bound(ALL(vec), mx) - upper_bound(ALL(vec), mn));
        };

        FL(i,0,m) {
            FL(j,i+1,m) {
                if(a[j].t - a[i].t > d) break;
                if(a[i].t >= a[j].t) continue;

                int u1 = a[i].u, v1 = a[i].v;
                int u2 = a[j].u, v2 = a[j].v;
                int mn = a[j].t;
                int mx = a[i].t + d;

                // T1: AB, BC, CA
                if(v1 == u2 && u1 != v2) t1 += qc(v2, u1, mn, mx);
                
                // T2: AB, AC, BC
                if(u1 == u2 && v1 != v2) t2 += qc(v1, v2, mn, mx);

                // T3: AB, CB, BA
                if(v1 == v2 && u1 != u2) t3 += qc(v1, u1, mn, mx);
            }
        }
        cout << t1 << " " << t2 << " " << t3 << endl;
    }

#ifdef KRAKAR
    cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
        chrono::high_resolution_clock::now()
        - _clock_start).count() << "ms." << endl;
#endif
    return 0;
}
