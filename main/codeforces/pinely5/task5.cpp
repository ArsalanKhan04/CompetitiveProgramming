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

/* Modular Arithmetic Classes Defined Below */

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}
 
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
 
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
 
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
 
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }
 
  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }
 
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
 
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
 
  friend const Type& abs(const Modular& x) { return x.value; }
 
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);
 
 private:
  Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
 
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
 
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
 
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
 
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
 
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
 
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
 
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}
 
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
 
// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}
 
// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
 
// using ModType = int;
 
// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;
// using Mint = Modular<VarMod>;
 
constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

vector<Mint> Inv(1, 1);
vector<Mint> Fac(1, 1);

Mint Comb(int n, int r){
  if (r < 0 || r > n)
    return 0;

  while ((int) Fac.size() < n + 1){
    Fac.pb(Fac.back() * (int) Fac.size());
    Inv.pb(1 / Fac.back());
  }
  return Fac[n] * Inv[r] * Inv[n-r];
}


/* Modular Arithmetic Completed */


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
      int n, k;
      cin >> n >> k;
      string s;
      cin >> s;

      int qs = 0;
      FL(i,0,n){
        if (s[i] == '?') qs++;
      }
      Mint ans = power((Mint)2, qs);
      dbg(ans);
      int l = 0;
      int r = 1;
      int cq = 0, c0 = 0, c1 = 0;
      while (r < k){
        if (s[r] == '0') c0++;
        else if (s[r] == '1') c1++;
        else cq++;
        r++;
      }
      if (k < sqrt(n)){
        // if less than make prefix sum
        vector<vector<Mint>> vk(k + 1, vector<Mint>(k + 1));
        FL(i,1,k+1){
          FL(j,0,i+1){
            vk[i][j] = Comb(i, j) * power((Mint)2, i-j);
          }
          FL(j, 1, i+1){
            vk[i][j] += vk[i][j-1];
          }
        }
        while (r <= n){
          Mint sl0 = 0;
          Mint sl1 = 0;

          // for sl1
          int mdp = c1 - c0;
          int lf = cq - abs(mdp);
          int vl1, vl2;
          if (mdp >= 0){
            vl1 = (cq - mdp + 1) / 2;
            vl2 = abs(mdp) + (cq - mdp + 1) / 2;
          } else {
            vl2 = (cq - abs(mdp) + 1) / 2;
            vl1 = abs(mdp) + (cq - abs(mdp) + 1) / 2;
          }
          vl1++; vl2++;
          sl1 = vk[cq][k] - vk[cq][vl1-1];
          sl0 = vk[cq][k] - vk[cq][vl2-1];

          if (s[l] == '0'){
            ans -= sl1 * power((Mint) 2, qs-cq);
          } else if (s[l] == '1'){
            ans -= sl0 * power((Mint) 2, qs-cq);
          } else {
            ans -= (sl0 + sl1) * power((Mint) 2, qs-cq-1);
          }
          if (r == n) break;
          //Move to next one
          if (s[r] == '0') c0++;
          else if (s[r] == '1') c1++;
          else cq++;
          r++;
          l++;
          if (s[l] == '0') c0--;
          else if (s[l] == '1') c1--;
          else cq--;
        }
      } else {
        while (r <= n){
          dbg(l, r);
          Mint sl0 = 0;
          Mint sl1 = 0;

          // for sl1
          int mdp = c1 - c0;
          dbg(c1, c0, cq);
          dbg(mdp);
          int lf = cq - abs(mdp);
          int vl1, vl2;
          if (mdp >= 0){
            vl1 = (cq - mdp + 1) / 2;
            vl2 = abs(mdp) + (cq - mdp + 1) / 2;
          } else {
            vl2 = (cq - abs(mdp) + 1) / 2;
            vl1 = abs(mdp) + (cq - abs(mdp) + 1) / 2;
          }
          vl1++; vl2++;
          dbg(vl1, vl2);

          for (int i = vl2; i <= cq; i++){
            sl0 += Comb(cq, i); 
          }
          for (int i = vl1; i <= cq; i++){
            sl1 += Comb(cq, i);
          }
          dbg(sl0, sl1);


          if (s[l] == '0'){
            ans -= sl1* power((Mint)2, qs-cq);
          } else if (s[l] == '1'){
            ans -= sl0* power((Mint)2, qs-cq);
          } else {
            ans -= (sl0 + sl1) * power((Mint)2, qs-cq-1);
          }

          if (r == n) break;
          //Move to next one
          if (s[r] == '0') c0++;
          else if (s[r] == '1') c1++;
          else cq++;
          r++;
          l++;
          if (s[l] == '0') c0--;
          else if (s[l] == '1') c1--;
          else cq--;
        }

      }


      cout << ans << endl;

    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

