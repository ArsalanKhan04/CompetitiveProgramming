#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
   // int p10[10] =  {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
   // int min10[10] = {2,1,4,7,4,8,3,6,4,8};
   // int max10[10] = {2,1,4,7,4,8,3,6,4,7};
   // int get_digit(int num, int index, int numSize){
   //     return (num/p10[numSize-index-1]) % 10;
   // }
    int reverse (int x) {
        //int p10[10] =  {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
        //int min10[10] = {2,1,4,7,4,8,3,6,4,8};
        //int max10[10] = {2,1,4,7,4,8,3,6,4,7};
        int minAlmost = INT_MIN / 10;
        int maxAlmost = INT_MAX / 10;
        //bool big = false;
        int currNum;
        int answer = 0;
        while (x) {
            currNum = x%10;
            if (answer < minAlmost) {
                return 0;
            }
            if (answer > maxAlmost) {
                return 0;
            }
            answer = (answer * 10) + currNum;
            x = x/10;
        }
        return answer;
    }
};

int main() {
    Solution mySol;
    cout << -214 % 100 << endl;
    // cout << mySol.get_digit(325, 1, 3) << endl;
    cout << mySol.reverse(-2147483648) << endl;

}
