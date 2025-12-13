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
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

// For debugging purposes
#ifdef KRAKAR
#define dbg(v) \
	cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#else
#define dbg(v) // nothing
#endif

void print_vec(const vector<int>& vec, int n) {
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}



int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef KRAKAR
    cout << "krakar execution" << endl;
    // Opening the input file stream and associate it with 
    // "input.txt" 
    ifstream fileIn("input.txt"); 
  
    // Redirecting cin to read from "input.txt" 
    cin.rdbuf(fileIn.rdbuf()); 
  
    // Opening the output file stream and associate it with 
    // "output.txt" 
    ofstream fileOut("output.txt"); 
  
    // Redirecting cout to write to "output.txt" 
    cout.rdbuf(fileOut.rdbuf()); 
    auto _clock_start = chrono::high_resolution_clock::now();
#endif

  int t;
  cin >> t;
  FL(et, 0, t) {
    int n;
    cin >> n;
    // a - b <= 6
    // for all values of a, b must be smaller as well hence
    // b < a
    // b >= a - 6
    // hence b can go from a - 6 to a - 1
    int a_b;
    int nd;
    if (n == 100)
      nd = 3;
    else if (n > 9)
      nd = 2;
    else
      nd = 1;

    int count = 0;
    vector<pair<int, int>> res;
    int iii;
    int ii1;
    int ii2;
    int ii3;
    if (nd == 1) {
      FE(a, 1, 10000) {
        FE(b, max(a-6, 1), a - 1){
          a_b = a - b;
          iii = 0;
          FL(i, 0, a - b){
            iii = iii * 10 + 1;
          }
          if (b == n * (a - iii)) {
            count++;
            res.pb(mp(a, b));
          }
        }
      }
    } else if (nd == 2) {
      FE (a, 1, 10000){
        FE (b, max(2*a - 6, 1), 2 * a - 1){
          ii1 = 0;
          ii2 = 0;
          FL(i, 0, 2*a - b){
            ii1 = ii1 * 10 + !(i % 2);
            ii2 = ii2 * 10 + (i % 2);
          }
          if((n/10) * ii1 + (n%10) * ii2 == (n * a - b)) {
            count++;
            res.pb(mp(a, b));
          }
        }
      }
    } else {
      FE (a, 1, 10000){
        FE (b, max(3*a - 6, 1), 3 * a - 1){
          ii1 = 0;
          ii2 = 0;
          ii3 = 0;
          FL(i, 0, 3*a - b){
            ii1 = ii1 * 10 + (i % 3 == 0);
            ii2 = ii2 * 10 + (i % 3 == 1);
            ii3 = ii3 * 10 + (i % 3 == 2);
          }
          if((n/100) * ii1 + ((n/10)%10) * ii2 + (n%10) * ii3 == (n * a - b)) {
            count++;
            res.pb(mp(a, b));
          }
        }
      }
    }
    cout << count << endl;
    FL(i, 0, count) 
      cout << res[i].first << " " << res[i].second << endl;


  }
        

#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}
