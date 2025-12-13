#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//   int numberOfSubarrays(vector<int>& nums, int k) {
//     // I think this is a dp problem
//     // Or maybe this is a suffix problem as well?
//     int n = nums.size();
//     vector<int> cums(n + 1);
//     cums[0] = 0;
//     for (int i = 1; i < n + 1; i++)
//       cums[i] = nums[i - 1] % 2;
//     for (int i = 1; i < n + 1; i++)
//       cums[i] += cums[i-1];
//     int total = 0;
//     for (int i = 1; i < n+1; i++)
//       for (int j = 0; j < i; j++)
//         if (cums[i] - cums[j] == k)
//           total++;
//     return total;
//     // Time limit exceeded :((
//     // I assume we can solve this by using a hashmap as well
//     // I think I have done a similar problem before, but I cannot recall how
//     // If we have 5 odd numbers, we subtract from 2
//   }
// };
//
//


void print_vec(const vector<int>& vec, int n) {
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
  int numberOfSubarrays(vector<int>& nums, int k){
    int n = nums.size();
    vector<int> cums(n + 1);
    cums[0] = 0;
    for (int i = 1; i < n + 1; i++)
      cums[i] = nums[i - 1] % 2;
    for (int i = 1; i < n + 1; i++)
      cums[i] += cums[i-1];
    int total = 0;
    int low = 0;
    int high = k;
    int freq_count = 0;
    int curr_num = 0;
    // We will iterate through 0 to n freq count
    while (low < n && high < n+1) {
      while (low < n && cums[low] == curr_num){
        low++;
        freq_count++;
      }
      
      // cout << "Freq Count: " << freq_count << endl;
      // print_vec(cums, n);
      // cout << cums[high] << endl;
      while (cums[high] < k+curr_num){
        high++;
      }
      while (high < n+1 && cums[high] == k + curr_num){
        total+=freq_count;
        high++;
      }
      freq_count = 0;
      curr_num++;
    }
    return total;


  }
};




int main() {
  vector<int> arr1 = {1, 1, 2, 1, 1};
  int k = 3;
  Solution mysol;
  cout << mysol.numberOfSubarrays(arr1, k) << endl;


}
