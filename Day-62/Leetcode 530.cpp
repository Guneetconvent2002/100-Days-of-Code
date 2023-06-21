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

    int minDiff = INT_MAX;
    int val = -1;

    int getMinimumDifference(TreeNode* root) {
        if(root->left != nullptr) getMinimumDifference(root->left);
        if(val >= 0) minDiff = min(minDiff, root->val - val);

        val = root->val;

        if(root->right != nullptr) getMinimumDifference(root->right);

        return minDiff;
    }
};