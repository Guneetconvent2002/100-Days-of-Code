class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int left = 0, top = 0, right = matrix[0].size()-1, bottom = matrix.size()-1;

        while(left <= right && top <= bottom)
        {
            for(int i = left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            
            top++;

            for(int i=top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }

            right--;

            for(int i=right; i >= left && top <= bottom; i--){
                ans.push_back(matrix[bottom][i]);
            }

            bottom--;

            for(int i=bottom; i >= top && left <= right; i--){
                ans.push_back(matrix[i][left]);
            }

            left++;
        }
        return ans;
    }
};