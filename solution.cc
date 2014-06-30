// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int maxH;
        return helper(root, maxH);
    }
    
    bool helper(TreeNode *root, int &maxH) {
        if(!root) {
            maxH = 0;
            return true;
        }
        int maxHL;
        if(!helper(root->left,maxHL)) return false;
        int maxHR;
        if(!helper(root->right, maxHR)) return false;
        if(abs(maxHL-maxHR) > 1) return false;
        maxH = max(maxHL, maxHR)+1;
        return true;
    }
};
