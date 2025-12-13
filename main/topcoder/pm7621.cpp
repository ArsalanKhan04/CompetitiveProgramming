#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif



class ToolingUp {
  public:
    using ll = long long;

    const ll INF = (ll) 1e18; // 1e18, a safe INF

    // ----- Modular arithmetic helpers using __int128 -----
    ll modmul(ll a, ll b, ll mod) {
      __int128 A = a, B = b;
      return (long long)((A * B) % mod);
    }

    ll modexp(ll base, ll exp, ll mod) {
      ll result = 1 % mod;
      base %= mod;
      while(exp > 0) {
        if(exp & 1)
          result = modmul(result, base, mod);
        base = modmul(base, base, mod);
        exp >>= 1;
      }
      return result;
    }

    // ----- Miller–Rabin Primality Test -----
    bool isPrime(ll n) {
      if(n < 2) return false;
      int smallPrimes[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
      for (int p : smallPrimes) {
        if(n == p) return true;
        if(n % p == 0) return false;
      }
      ll d = n - 1;
      int s = 0;
      while((d & 1LL) == 0) {
        s++;
        d /= 2;
      }
      int testPrimes[5] = {2, 3, 5, 7, 11};
      for (int a : testPrimes) {
        if(a >= n) break;
        ll x = modexp(a, d, n);
        if(x == 1 || x == n - 1)
          continue;
        bool cont = false;
        for (int r = 0; r < s - 1; r++) {
          x = modmul(x, x, n);
          if(x == n - 1) {
            cont = true;
            break;
          }
        }
        if(!cont) return false;
      }
      return true;
    }

    // ----- Pollard–Rho Factorization -----
    ll pollard_rho(ll n) {
      if(n % 2 == 0)
        return 2;
      ll x = rand() % (n - 2) + 2;
      ll y = x;
      ll c = rand() % (n - 1) + 1;
      ll d = 1;
      while(d == 1) {
        x = (modmul(x, x, n) + c) % n;
        y = (modmul(y, y, n) + c) % n;
        y = (modmul(y, y, n) + c) % n;
        ll diff = (x > y ? x - y : y - x);
        d = std::gcd(diff, n);
        if(d == n)
          return pollard_rho(n);
      }
      return d;
    }

    // Factorize n into its prime factors (store in factors: prime -> exponent)
    void factorize(ll n, unordered_map<ll,int> &factors) {
      if(n == 1) return;
      if(isPrime(n)) {
        factors[n]++;
        return;
      }
      ll factor = pollard_rho(n);
      factorize(factor, factors);
      factorize(n / factor, factors);
    }

    // ----- Utility: integer power (for small exponents) -----
    ll ipow(ll a, int b) {
      ll res = 1;
      for (int i = 0; i < b; i++)
        res *= a;
      return res;
    }

    // ----- Candidate new part structure -----
    struct Candidate {
      vector<int> boost; // For each prime, the extra exponent (f) provided.
      ll cost;         // The candidate's size (and its cost)
    };

    // ----- Candidate Generation -----
    // For each prime in our list (of length k), choose an additional exponent f in [0, req[i]].
    // We build a candidate part as:
    //    s = ∏_{i=0}^{k-1} primes[i]^( base[i] + f[i] )
    // and its boost is the vector (f[0], f[1], …, f[k-1]).
    // We require that not all f[i] are 0.
    void genCandidates(int idx, const vector<ll>& primes, const vector<int>& base, const vector<int>& req,
        vector<int>& current, ll currentCost, vector<Candidate>& candidates) {
      int k = primes.size();
      if(idx == k) {
        bool nonzero = false;
        for (int x : current)
          if(x > 0) { nonzero = true; break; }
        if(nonzero) {
          candidates.push_back({ current, currentCost });
        }
        return;
      }
      for (int f = 0; f <= req[idx]; f++) {
        current.push_back(f);
        ll factor = ipow(primes[idx], base[idx] + f);
        genCandidates(idx + 1, primes, base, req, current, currentCost * factor, candidates);
        current.pop_back();
      }
    }

    // ----- DP State Encoding/Decoding -----
    // We have k primes; for each i the extra exponent is in [0, req[i]].
    // We encode a state as an integer using mixed radix.
    int encodeState(const vector<int>& state, const vector<int>& mult) {
      int code = 0;
      int k = state.size();
      for (int i = 0; i < k; i++)
        code += state[i] * mult[i];
      return code;
    }

    // Given an encoded state, combine it with candidate boost (component–wise max, capped by req).
    int combineState(int stateCode, const vector<int>& candidateBoost, const vector<int>& req, const vector<int>& mult) {
      int k = req.size();
      vector<int> st(k, 0);
      int temp = stateCode;
      for (int i = 0; i < k; i++) {
        st[i] = temp / mult[i];
        temp %= mult[i];
      }
      for (int i = 0; i < k; i++) {
        st[i] = max(st[i], candidateBoost[i]);
        if(st[i] > req[i])
          st[i] = req[i];
      }
      return encodeState(st, mult);
    }

    // ----- Main solution function -----
    // sizes: current sizes; targetLcmStr: target LCM (as a string)
    ll solve(const vector<int>& sizes, const string& targetLcmStr) {
      ll T = stoll(targetLcmStr);

      // Compute current LCM, L0.
      ll L0 = 1;
      for (int s : sizes) {
        ll g = gcd(L0, (ll)s);
        L0 = (L0 / g) * s;
      }
      if(L0 >= T)
        return 0;

      // Factorize T and L0.
      unordered_map<ll,int> factorsT, factorsL0;
      factorize(T, factorsT);
      factorize(L0, factorsL0);

      // We only care about primes that appear in T.
      // (Even if L0 has extra primes they don’t affect the condition LCM >= T.)
      vector<ll> primes;   // the primes of interest
      vector<int> req;     // for each such prime, let req[i] = max(0, exp_T - exp_L0)
      vector<int> base;    // base[i] = exponent of prime in L0 (could be 0)
      for (auto &pr : factorsT) {
        ll p = pr.first;
        int expT = pr.second;
        int expL0 = factorsL0.count(p) ? factorsL0[p] : 0;
        // Even if expT <= expL0, a new part might not need to include p.
        // We only “boost” with primes that could help.
        if(expT > expL0) {
          primes.push_back(p);
          req.push_back(expT - expL0);
          base.push_back(expL0);
        }
      }
      int k = primes.size();

      // Generate candidate new parts.
      vector<Candidate> candidates;
      vector<int> cur;
      genCandidates(0, primes, base, req, cur, 1LL, candidates);
      sort(candidates.begin(), candidates.end(), [](const Candidate &a, const Candidate &b) {
          return a.cost < b.cost;
          });

      // Prepare DP over boost vectors.
      // DP state: for each prime, the current extra exponent achieved.
      // We'll encode a state as an integer using mixed radix.
      vector<int> mult(k);
      mult[k-1] = 1;
      for (int i = k - 2; i >= 0; i--) {
        mult[i] = mult[i+1] * (req[i+1] + 1);
      }
      int totalStates = mult[0] * (req[0] + 1);
      vector<ll> dp(totalStates, INF);
      dp[0] = 0; // initial state: no extra boost.

      // 0-1 knapSack–style DP: each candidate can be used at most once.
      for (auto &cand : candidates) {
        vector<ll> dp_old = dp; // snapshot so that each candidate is used only once.
        for (int s = 0; s < totalStates; s++) {
          if(dp_old[s] == INF) continue;
          int ns = combineState(s, cand.boost, req, mult);
          dp[ns] = min(dp[ns], dp_old[s] + cand.cost);
        }
      }

      // Instead of requiring that the boost vector equals (req[0], ..., req[k-1]),
      // we now check the numerical condition:
      // Find the minimal extra cost among all states for which L0 * (∏_{i=0}^{k-1} primes[i]^(state[i])) >= T.
      ll ans = INF;
      for (int s = 0; s < totalStates; s++) {
        if(dp[s] == INF) continue;
        int temp = s;
        ll boostVal = 1;
        for (int i = 0; i < k; i++) {
          int exp_i = temp / mult[i];
          temp %= mult[i];
          boostVal *= ipow(primes[i], exp_i);
        }
        if(L0 * boostVal >= T)
          ans = min(ans, dp[s]);
      }
      return ans;
    }
    int cost(string targetLcm, vector<int> sizes) {
      ll ans = solve(sizes, targetLcm);
      return ans;
    }
};


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

  string arg0;
  getline(cin, arg0);
  int n1; cin >> n1;
  vector<int> arg1(n1);
  for (int i=0;i<n1;++i) { cin >> arg1[i]; }
  auto c = ToolingUp();
  int ret = c.cost(arg0, arg1);
  cout << ret;
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}
