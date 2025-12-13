#ifndef LOCAL
#define NDEBUG
#endif

/*#pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wsign-compare"
*/

#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n"
#define ve vector
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define ll long long
#define pq priority_queue
#define gi greater<int>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define tcs      \
    int tttt;    \
    cin >> tttt; \
    for (int TTTT = 1; TTTT <= tttt; TTTT++)
#define sp << " " <<
#define rep(l, r, i) for (int i = l; i < r; ++i)
#define per(l, r, i) for (int i = r; i >= l; --i)
#define repp(l, r, i) for (int i = l; i <= r; ++i)
#define all(a) begin(a), end(a)
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define MOD 1000000007


#ifdef LOCAL
#include "templates/debug.cpp"
#else
#define dbb(...) 11
#define db(n) 22
#define DB(n) 33
#endif

void solve() {
    int n;
    cin >> n;
    if (n == 1) { cout << 0; return; }

    vi a(n);
    int mx = 0;
    rep(0, n, i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    set<int> st;
    rep(0, n - 1, i) {
        st.insert(a[i + 1] - a[i]);
    }

    if (st.size() == 1) {
        cout << 0;
        return;
    }

    if (st.size() > 2) {
        cout << -1;
        return;
    }

    int tc1 = *st.begin();
    st.erase(tc1);
    int tc2 = *st.begin();

    int c1 = max(tc1, tc2);
    int c2 = min(tc1, tc2);

    int m = c1 - c2;
    if (m <= mx) {
        cout << -1;
        return;
    }

    cout << m << " " << c1;
}

/*
3 0 4 1 5

3 + c = 0 mod m
0 + c = 4 mod m
4 + c = 1 mod m
1 + c = 5 mod m

-> c = -3 mod m
-> c = 4 mod m
-> c = -3 mod m
-> c = 4 mod m

-3 + x = 4 > -3 + 7 = 4

s = 3

lower limit of m is max + 1 = 6
s + c=3 = 6 = 0
0 + 3 = 3
6 can't be

1 + 3 = 4 + 3 = 7

*/

int32_t main() {

    // fastio;
    tcs {
        // cout<<"Case #"<<TTTT<<": ";
        solve();
        nl;
    }
    return 0;
}

/*

*/
