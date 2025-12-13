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
  int maxHeightOfTriangle(int red, int blue) {
    int a[2];
    a[0] = max(red, blue);
    a[1] = min(red, blue);
    int answer1 = 1;
    bool flag = false;
    while (a[0] > 0 && a[1] > 0){
      a[flag] -= answer1;
      answer1++;
      flag = !flag;
    }
    a[0] = min(red, blue);
    a[1] = max(red, blue);
    int answer2 = 1;
    flag = false;
    while (a[0] > 0 && a[1] > 0){
      a[flag] -= answer2;
      answer2++;
      flag = !flag;
    }
    return max(answer1, answer2) - 1;
  }
};

int main() {


}
