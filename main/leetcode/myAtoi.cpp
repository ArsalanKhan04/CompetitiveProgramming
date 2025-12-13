#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        int s_size = s.size();
        int count = 0;
        int answer = 0;
        // ignore any leading whitespace
        while (count < s_size && s[count]==' ') {
            count++;
        }
        if (count == s_size){
            return 0;
        }
        // Check the sign now
        bool positive = true;
        if (s[count]=='-'){
            positive = false;
            count++;
        }
        else if (s[count]=='+'){
            count++;
        }
        while (count < s_size && s[count] <= '9' && s[count] >= '0'){
            if (answer > 214748364) {
                if (positive) {
                    return 2147483647;
                }
                return -2147483648;
            } else if (answer == 214748364) {
                if (positive){
                    if (s[count] >= '7'){
                        return 2147483647;
                    }
                } else {
                    if (s[count] >= '8'){
                        return -2147483648;
                    }
                }
            }

            answer = answer*10 + (s[count]-'0');
            count++;
        }
        answer = positive ? answer : answer * -1;
        return answer;

    }
};


int main() {
    Solution mysol;
    cout << mysol.myAtoi("3203") << endl;
}
