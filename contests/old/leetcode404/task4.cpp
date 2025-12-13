#include <bits/stdc++.h>
#include <queue>
using namespace std;

void print_vec(const vector<int>& vec, int n) {
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
  int calcSize(vector<vector<int>>& edges, int n, int &size2){
    if (n == 0){
      return 0;
    }
    int size = 0;
    int j = 1;
    int i = 0;
    queue<int> tobe;
    tobe.push(0);
    tobe.push(-1);
    int relax;
    int count = 0;
    size2 = 0;
    while (true){
      relax = tobe.front();
      if (relax == -1){
        tobe.push(-1);
        size++;
        tobe.pop();
        if (count > 1){
          size2 = size;
        }
        if (tobe.front() == -1){
          break;
        }
        count = 0;
        continue;
      }
      count++;
      while (i<n && edges[i][0] == relax){
        tobe.push(edges[i][1]);
        i++;
      }
      tobe.pop();
    }
    cout << "Size" << size << endl;
    cout << "Size 2" << size2 << endl;
    return size;
      
  }
  int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    sort(edges1.begin(), edges1.end(), [](vector<int>& a, vector<int>& b){
        return a[1] < b[1];
        });
    sort(edges1.begin(), edges1.end());
    int n = edges1.size();
    sort(edges2.begin(), edges2.end(), [](vector<int>& a, vector<int>& b){
        return a[1] < b[1];
        });
    sort(edges2.begin(), edges2.end());
    int m = edges2.size();
    int a1, a2, b1, b2;
    a1 = calcSize(edges1, n, a2);
    b1 = calcSize(edges2, n, b2);
    int big, small;
    if (a1 > b1){
      big = a1;
      if (a2 > b1){
        small = a2;
      } else {
        small = b1;
      }
    } else {
      big = b2;
      if (b2 > a1){
        small = b2;
      } else {
        small = a1;
      }
    }
    small = max(small, 1);
    return big + small - 1;
  }
};


int main() {


}
