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
    bool helper(TreeNode* node1,TreeNode* node2){
        if(node1==NULL && node2==NULL){
            return true;
        }
        if(node1==NULL || node2==NULL){
            return false;
        }
        if(node1->val!=node2->val){
            return false;
        }
        bool leftMirror=helper(node1->left,node2->right);
        bool rightMirror=helper(node1->right,node2->left);

        return leftMirror && rightMirror;
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        return helper(root->left,root->right);
    }
};