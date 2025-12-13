#include <bits/stdc++.h>
using namespace std;

constexpr int inf = (1e9) + 30;

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

    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int mn1, mn2;
    mn1 = inf;
    mn2 = inf;
    bool flag = false;
    for (int i = 0; i < n; i++){
      if (nums[i] < mn1) mn1 = nums[i];
      if (nums[i] > mn1 && nums[i] < mn2) mn2 = nums[i];
      if (nums[i] > mn2) {
        flag = true;
        break;
      }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}
