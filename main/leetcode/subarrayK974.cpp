#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // we will first make the cum sum array
        int nums_size = nums.size();
        unordered_map<int, int> cum_loc;
        for (int i = 1; i < nums_size; i++){
            nums[i] += nums[i-1];
        }

        cum_loc[0] = 1;
        int curr_val;
        int total = 0;
        for (int i = 0; i < nums_size; i++){
            curr_val = nums[i] % k;
            if (curr_val < 0)
                curr_val += k;
            total += cum_loc[curr_val];
            cum_loc[curr_val]++;
        }

        return total;
    }
};


int main() {
    cout << -3 % 5 << endl;
}
