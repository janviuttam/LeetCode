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
    int maxSumBST(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        vector<TreeNode*> bfsOrder;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            bfsOrder.push_back(node);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        reverse(bfsOrder.begin(), bfsOrder.end());

        unordered_map<TreeNode*, tuple<bool,int,int,int>> info;
        int maxSum = 0;

        for (auto node : bfsOrder) {
            bool leftBST = true, rightBST = true;
            int leftMin = node->val, rightMax = node->val;
            int leftSum = 0, rightSum = 0;

            if (node->left) {
                auto [isBST, lmin, lmax, lsum] = info[node->left];
                leftBST = isBST && lmax < node->val;
                leftMin = lmin;
                leftSum = lsum;
            }

            if (node->right) {
                auto [isBST, rmin, rmax, rsum] = info[node->right];
                rightBST = isBST && rmin > node->val;
                rightMax = rmax;
                rightSum = rsum;
            }

            if (leftBST && rightBST) {
                int sum = node->val + leftSum + rightSum;
                int minVal = node->left ? leftMin : node->val;
                int maxVal = node->right ? rightMax : node->val;
                info[node] = {true, minVal, maxVal, sum};
                maxSum = max(maxSum, sum);
            } else {
                info[node] = {false, 0, 0, 0};
            }
        }

        return maxSum;
    }
};