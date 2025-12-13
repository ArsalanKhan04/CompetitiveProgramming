#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int heights_size = heights.size();
        vector<int> newheights(heights_size);

        for (int i = 0; i < heights_size; i++){
            newheights[i] = heights[i];
        }

        sort(heights.begin(), heights.end());

        int total = 0;
        for (int i = 0; i < heights_size; i++){
            if (heights[i] != newheights[i]){
                total++;
            }
        }
        return total;
        
    }
};
