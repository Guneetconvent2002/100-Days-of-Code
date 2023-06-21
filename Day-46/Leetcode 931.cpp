class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rowSize = matrix.size(), colSize = matrix[0].size();

        int dp[101][101];
        for(int i=0; i<rowSize; i++) dp[0][i] = matrix[0][i];

        for(int i=1; i<rowSize; i++){
            for(int j=0; j<colSize; j++){
                int mini = INT_MAX;
                if(i-1 >= 0) mini = min(mini, dp[i-1][j]);
                if(i-1 >= 0 && j-1 >= 0) mini = min(mini, dp[i-1][j-1]);
                if(i-1 >= 0 && j+1 < colSize) mini = min(mini, dp[i-1][j+1]);

                dp[i][j] = mini + matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<rowSize; i++){
            ans = min(ans, dp[rowSize-1][i]);
        }
        return ans;
    }
};