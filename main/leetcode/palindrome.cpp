class Solution {
public:
    bool isPalindrome(int x) {
        int y = 0;
        int z = x;
        while (z!=0){
            y = y*10 + z%10;
            z/=10;
        }
        return x==y;
    }
};
