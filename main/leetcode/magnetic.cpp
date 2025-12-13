#include <bits/stdc++.h>
#include <vector>
using namespace std;

void print_vec(const vector<int>& vec, int n) {
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    bool possible(vector<int>& position, int n, int m, int mid){
        int x = mid;
        m--;
        for (int i = 1; i < n; i++){
            if (m==0){
                return true;
            }
            x -= (position[i] - position[i-1]);
            if (x <= 0){
                m--;
                x = mid;
            } 
        }
        if (m==0){
            return true;
        }
        return false;

    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();   
        sort(position.begin(), position.begin() + n);
        int low = 1;
        int high = (position[n - 1] - position[0])/ (m-1);
        int mid;
        while (low <= high){
            mid = (low + high) / 2;
            if (possible(position, n, m, mid))
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return high;
    }
};

int main() {
    Solution mysol;
    vector<int> position = {22, 57, 74, 79};
    int n = 4;
    int m = 4;
    int mid = 5;
    cout << mysol.possible(position, n, m, mid) << endl;

    cout << mysol.maxDistance(position, m) << endl;


}
