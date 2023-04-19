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

    int ans = 0;

    void solve(TreeNode* root, bool left, int steps){
        if(!root) return;

        ans = max(ans, steps);

        if(left){ // this was root->left
            solve(root->left, false, steps + 1);
            solve(root->right, true, 1);
        }

        else{
            solve(root->left, false, 1);
            solve(root->right, true, steps + 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        solve(root, false, 0);
        solve(root, true, 0);

        return ans;
    }
};