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
#define sz(a) a.size()
#define rep(i, j, k) for(int i = j; i < k; i++)

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define condprt(x) cout << ((x) ? "YES" : "NO") << endl


vi Z(const vi& S) {
	vi z(sz(S));
	int l = -1, r = -1;
	rep(i,1,sz(S)) {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
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
    cin >> TCS;
    while(TCS--){
      int n, m;
      cin >> n >> m;
      vvi a(n, vi(m));
      vvi b(n, vi(m));
      FL(i, 0, n){
        FL(j, 0, m) cin >> a[i][j];
      }
      FL(i, 0, n) FL(j, 0, m) cin >> b[i][j];
      vi aa(n * m);
      FL(i, 0, n) FL(j, 0, m) aa[i * m + j] = (a[i][j]);
      int mvs = 0;
      // always divide into two parts
      int a_i = 0;
      int b_r = 0;


      // first part
      auto f1 = [&](){
        int cur_a = 0;
        int cur_b = 0;
        int prv_b = 0;
        int k = 0;
        while (cur_b < m && cur_a < mvs){
          while (cur_b < m && aa[a_i + cur_a] != b[b_r][cur_b]){
            cur_b++;
          }
          k += cur_b - prv_b;
          while (cur_a < mvs && cur_b < m && aa[a_i+cur_a] ==  b[b_r][cur_b]){
            cur_a++;
            cur_b++;
          }
          prv_b = cur_b;
        }
        if (cur_a < mvs || cur_b == m){
          mvs += m - cur_b;
          cur_b=m;
          b_r++;
        }
        a_i += cur_a;
        mvs += k;
        return cur_b;
      };

      // scd part
      auto f2 = [&](int k, int cur_b){
        vi s1, s2;
        FL(i, cur_b, m){
          s2.push_back(b[b_r][i]);
        }
        FL(i, 0, m - cur_b){
          s1.push_back(aa[a_i + i]);
        }
        reverse(ALL(s1));
        reverse(ALL(s2));
        s2.insert(s2.end(), ALL(s1));
        vi zs = Z(s2);
        zs.erase(zs.begin(), zs.begin() + m - cur_b);
        FL(i, 0, zs.size()){
          if (zs[i] + i >= m - cur_b){
            a_i += zs[i];
            break; 
          }
          mvs++;
        }
        b_r++;
      };

      while (b_r < n){
        int k = max(m - mvs, 0);
        int rem_i = f1();
        if (rem_i < m){
          f2(k, rem_i);
        }
      }
      cout << mvs << endl;


    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

