#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bin_search_max(long long num){
        int start = 32;
        int diff = 16;
        long long curr_num;
        while (diff > 0) {
            curr_num = (1LL << start);
            // cout << "Num: " << num << endl;
            // cout << "Curr_Num: " << curr_num << endl;
            if (curr_num < num) {
                //cout << "Adding " << endl;
                start += diff;
            } else if (curr_num == num) {
                return start;
            } else {
                //cout << "subtracting" << endl;
                start -= diff;
            }
            diff /= 2;
            // cout << "Diff value is " << diff << endl;
        }
        curr_num = (1LL << start);
        if (curr_num < num){
            return start;
        }
        return start - 1;
        // if (1 <
    }
    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
               
    }
};


int main() {
    Solution mySol;

    cout << int (1 << 30) << endl;
    cout << mySol.bin_search_max(17) << endl;

}
