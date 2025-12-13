#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int total_nums[26] = {0};
        int s_size = s.size();
        for (int i = 0; i < s_size; i++){
            total_nums[i-97]++;
        }

    }
};
