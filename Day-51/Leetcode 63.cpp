class Solution {
public:

    int solve(vector<vector<int>> &obstacleGrid, int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i >= m || j >= n) return 0;
        if(obstacleGrid[i][j] == 1) return dp[i][j] = 0;
        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = solve(obstacleGrid, i+1, j, m, n, dp) + solve(obstacleGrid, i, j+1, m, n, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        
        if(obstacleGrid[n-1][m-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(obstacleGrid, 0, 0, n, m, dp);
    }
};