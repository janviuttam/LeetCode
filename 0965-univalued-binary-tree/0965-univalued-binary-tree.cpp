/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool solve(TreeNode* root, int value){
        if(root==nullptr){
            return true;
        }
        if(root->val!=value){
            return false;
        }
        bool left=solve(root->left,value);
        bool right=solve(root->right,value);

        return (left && right);
    }

    bool isUnivalTree(TreeNode* root) {
        int value=root->val;

        return solve(root,value);
    }
};