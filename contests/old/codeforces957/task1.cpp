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
#ifndef KRAKAR
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
    int n, k;
    cin >> n >> k;
    vi a(k);
    FL(i, 0, k) 
      cin >> a[i];

    sort(ALL(a));

    if (a[k-1] == 1)
      cout << n - 1 << endl;
    else {

      int x = 0;

      while (a[x] == 1)
        x++;


      int total = x;
      while (x < k - 1) {
        total += 2 * a[x] - 1;
        x++;
      }

      cout << total << endl;
    }
    


  }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}
