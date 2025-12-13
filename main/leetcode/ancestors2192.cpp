#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    // I assume we will start with a queue
    // Or we might use a vector that sorts the incoming degrees
    vector<int> indegrees(n, 0);
    int m = edges.size();
    for (int i = 0; i < m; i++)
      indegrees[edges[i][1]]++;

    vector<bool> discovered(n, false);
    vector<vector<int>> answer (n);
    queue<int> todiscover;
    
  }
};
