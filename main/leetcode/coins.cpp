
#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int currmoves;
    Solution() {
        currmoves = 0;
    }
    int recurCoins(TreeNode* root) {
        int difference;
        int leftdiff;
        int rightdiff;
        if (root == nullptr){
            return 0;
        }
        leftdiff = distributeCoins(root->left);
        rightdiff = distributeCoins(root->right);

        currmoves += abs(leftdiff) + abs(rightdiff);
        
        difference = root->val - 1;
        cout << "difference is: " << difference << endl;
        return difference + leftdiff + rightdiff;
    }
    int distributeCoins(TreeNode* root) {
        recurCoins(root);
        return currmoves;
    }
};

