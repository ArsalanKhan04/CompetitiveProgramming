#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size();   

    int max_time = 0;
    int frus_time = 0;
    int total_time = 0;
    for (int i = 0; i < minutes; i++){
      frus_time += grumpy[i] * customers[i];
      total_time += !grumpy[i] * customers[i];
    
      frus_time -= grumpy[i - minutes] * customers[i - minutes];
      frus_time += grumpy[i] * customers[i];
      total_time += !grumpy[i] * customers[i];
      if (frus_time > max_time){
        max_time = frus_time;
      }
    }
    return total_time + max_time;
  }
};

int main() {
  Solution mysol;
  vector<int> arr1 = {1,0,1,2,1,1,7,5};
  vector<int> arr2 = {0,1,0,1,0,1,0,1};

  cout << mysol.maxSatisfied(arr1, arr2, 3) << endl;

}
