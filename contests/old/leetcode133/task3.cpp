#include <bits/stdc++.h>
#include <functional>
#include <unordered_map>
#include <vector>
using namespace std;

void print_vec(const vector<int>& vec, int n) {
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
  int currPermutation(int i, int n, unordered_map<int, int>& cnts){
    if (i==0){
      if (cnts.find(0) != cnts.end() && cnts[0] != 0){
        return 0;
      }
    }
    int total = 0;
    for (int x = 0; x < i+1; x++){
      total += currPermutation(i+x, n, cnts);
    }
    return total;
  }
  int numberOfPermutations(int n, vector<vector<int>>& requirements) {
    unordered_map<int, int> cnts;
    for (int i = 0; i < requirements.size(); i++){
      cnts[requirements[i][0]] = requirements[i][1];
    }
    if (cnts.find(0) != cnts.end() && cnts[0] != 0){
      return 0;
    }
    int total_perms = 1;
    int cnt_start = 0;
    int cnt_end = 0;
    for (int i = 1; i < n; i++){
      if (cnts.find(i) == cnts.end()){
        total_perms *= (i + 1);
      } 
    };

  }
};

int main() {


}
