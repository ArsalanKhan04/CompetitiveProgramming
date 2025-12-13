#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows-1; i++){
            for (int j = 0; j < cols; j++){
                if(grid[i][j] != grid[i+1][j]){
                    return false;
                }
            }
        }
        for (int j = 0; j < cols - 1; j++){
            for (int i = 0; i < rows; i++){
                if(grid[i][j] == grid[i][j+1]){
                    return false;
                }
            }
        }
        return true;
        
    }
};



