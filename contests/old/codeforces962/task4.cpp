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
    int n, x;
    cin >> n >> x;
    int diff = x - 3;
    if (diff < 0){
      cout << 0 << endl;
      continue;
    }
    ull total = 0;
    int aM = min(1000, x - 2);
    ull c;
    FE(i, 1, aM){
      FE(j, 1, min(x-i-1, n/i)){
        c = max(min((n - i * j) / (i + j), (x-(i+j))), 0);
        total += c; // == 0 ? 0 : 2 * c - 1;
      }
    }
    cout << total << endl;
        

      


    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}
