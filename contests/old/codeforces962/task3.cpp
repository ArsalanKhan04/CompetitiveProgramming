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
#define dbg(v) \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

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
  cout << "here" << endl;
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

  cout << "main run " << endl;
  int t;
  cin >> t;
  cout << t << endl;
  dbg(t);
  FL(et, 0, t) {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    int l, r;
    vvi multcharA(26, vi(n * n));
    vvi multcharB(26, vi(n * n));
    build(1, 0, n-1, a, multcharA);
    build(1, 0, n-1, b, multcharB);

    vi result(26, 0);
    FL(i, 0, q){
      cin >> l >> r;
      cout << query(1, 0, n-1, l, r, multcharA, multcharB) << endl;
    }
  }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}
