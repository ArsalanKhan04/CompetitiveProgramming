#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void print_array(vector<int>& arr, int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " - ";
    }
    cout << endl;
}

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int nums_size = nums.size();
        if (nums_size < 2)
            return false;
        unordered_map<int, int> first_seen;
        first_seen[0] = 1;
        int sum = 0;
        for (int i = 0; i < nums_size; i++){
            sum = (sum + nums[i]) % k;
            if (first_seen[sum] != 0 && i - first_seen[sum] >= 0){
                cout << "sum = " << sum << endl;
                cout << first_seen[sum] << endl;
                return true;
            }
            if (first_seen[sum] == 0){
                first_seen[sum] = i + 2;
            }
        }
        return false;

    }
};



int main() {

    Solution mysol;
    vector<int> nums {5, 0, 0, 0};
    cout << mysol.checkSubarraySum(nums, 13) << endl;
    cout << mysol.checkSubarraySum(nums, 6) << endl;

}
