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
    int maxsum;

    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int l=solve(root->left);
        int r=solve(root->right);

        int found_maxSum=l+r+root->val;
        int maxSum_in_one=max(l,r)+root->val;
        int maxsum_in_root=root->val;

        maxsum=max({maxsum,found_maxSum,maxSum_in_one,maxsum_in_root});

        return max(maxsum_in_root,maxSum_in_one);
    }

    int maxPathSum(TreeNode* root) {
        maxsum=INT_MIN;
        solve(root);
        return maxsum;
    }
};