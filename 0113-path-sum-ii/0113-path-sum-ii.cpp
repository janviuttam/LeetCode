/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int targetSum, vector<vector<int>>&answer, vector<int>&path){
        if(root==nullptr){
            return;
        }
        path.push_back(root->val);

        if(root->left==nullptr && root->right==nullptr && targetSum-root->val==0){
            answer.push_back(path);
        }

        dfs(root->left,targetSum-root->val,answer,path);
        dfs(root->right,targetSum-root->val,answer,path);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>answer;
        vector<int>path;

        dfs(root,targetSum,answer,path);

        return answer;
    }
};