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
  int maximumLength(vector<int>& nums) {
    if (nums.size()==2){
      return 2;
    }
    int len = 1;
    bool prev;
    prev = nums[0] % 2;
    for (int i = 1; i < nums.size(); i++){
      if (nums[i] % 2 != prev){
        len++;
        prev = !prev;
      } 
    }
    return len;
  }
};


int main() {


}
