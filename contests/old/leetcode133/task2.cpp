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
  int minOperations(vector<int>& nums) {
    int n = nums.size();
    int total = 0;
    total = 0;
    int i = 0;
    int currzero = 0;
    while (i<n && nums[i] == 1){
      i++;
    }
    while (i < n) {
      total++;
      while (i < n && nums[i] == currzero){
        i++;
      }
      currzero = !currzero;
    }
    return total;
  }
};

int main() {
  vector<int> arr1 = {1, 0, 0, 0};
  Solution mysol;

  cout << mysol.minOperations(arr1) << endl;

}
