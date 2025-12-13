#include <bits/stdc++.h>
using namespace std;

void print_vec(const vector<int>& vec, int n) {
  for (int i = 0; i < n; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}

class Solution {
public:
  int minimumOperations(vector<int>& nums) {
    int total = 0;
    for (int i = 0; i < nums.size(); i++){
      if (nums % 3 != 0){
        total++;
      }
    }
    return total;
  }

};


int main() {
  vector<int> arr1 = {1, 2, 3, 4, 5};


}
