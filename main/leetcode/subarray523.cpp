#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // We will start by taking the mod of each number
        int nums_size = nums.size();
        for (int i = 0; i < nums_size; i++){
            nums[i] = nums[i] % k;
        }
        // We will make 1 more array
        int* cum = new int[nums_size];
        // We will start by 2
        for (int i = 0; i < nums_size; i++){
            cum[i] = nums[i];
        }
        for (int i = 1; i < nums_size; i++){
            for (int j = nums_size - 1; j >= i; j--){
                cum[j] = (cum[j] + nums[j-i]) % k;
                cout << cum[j] << " - ";
                if (cum[j] == 0){
                    return true;
                }
            }
            cout << endl;
        }
        return false;
        // We will keep two pointers now to have a sliding window
        
    }
};

int main() {
    Solution mysol;

    vector<int> nums = {1, 0, 1, 0, 1};
    int k = 4;

    cout << mysol.checkSubarraySum(nums, k) << endl;


}
