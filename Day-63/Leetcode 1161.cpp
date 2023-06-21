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
    int maxLevelSum(TreeNode* root) {
        int mx = root->val;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        int sum = 0, maxSum = INT_MIN, mxLevel = 0, level = 1;

        while(q.size() > 1){
            TreeNode* front = q.front();
            q.pop();
            
            if(front == NULL){
                q.push(NULL);
                if(sum > maxSum){
                    maxSum = sum;
                    mxLevel = level;
                } 
                sum  = 0;
                level++;
                cout << maxSum << " ";
            }

            else{
                sum += front->val;
                cout << sum << " ";
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            front == NULL ? cout << "NULL" << " -> " : cout <<  front->val << " -> ";
        }

        if(sum > maxSum){
            maxSum = sum;
            mxLevel = level;
        } 

        return mxLevel;
    }
};