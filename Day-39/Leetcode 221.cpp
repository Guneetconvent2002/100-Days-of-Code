class Solution {
private:
    int solve(vector<vector<char>> &matrix, int i, int j, int &maxi){
        if(i >= matrix.size() || j >= matrix[0].size()) return 0;

        int right = solve(matrix, i, j+1, maxi);
        int bottom = solve(matrix, i+1, j, maxi);
        int diagonal = solve(matrix, i+1, j+1, maxi);

        if(matrix[i][j] == '1'){
            int ans = 1 + min(right, min(diagonal, bottom));
            maxi = max(maxi, ans);
            return ans;
        }

        else return 0;
    }

    int solveMem(vector<vector<char>> &matrix, int i, int j, int &maxi, vector<vector<int>> &dp){
        if(i >= matrix.size() || j >= matrix[0].size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solveMem(matrix, i, j+1, maxi, dp);
        int bottom = solveMem(matrix, i+1, j, maxi, dp);
        int diagonal = solveMem(matrix, i+1, j+1, maxi, dp);

        if(matrix[i][j] == '1'){
            dp[i][j] = 1 + min(right, min(diagonal, bottom));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }

        else return 0;
    }

    int solveTab(vector<vector<char>> &matrix, int i, int j, int &maxi){
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row+1, vector<int> (col+1, 0));

        for(int i=row-1; i >= 0; i--){
            for(int j=col-1; j >= 0; j--){
                int right = dp[i][j+1];
                int bottom = dp[i+1][j];
                int diagonal = dp[i+1][j+1];

                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min(right, min(diagonal, bottom));
                    maxi = max(maxi, dp[i][j]);
                }

                else dp[i][j] = 0;
            }
        }
        return maxi;
    }

    int solveSpace(vector<vector<char>> &matrix, int i, int j, int &maxi){
        int row = matrix.size(), col = matrix[0].size();
        vector<int> curr(col+1, 0), next(col+1, 0);

        for(int i=row-1; i >= 0; i--){
            for(int j=col-1; j >= 0; j--){
                int right = curr[j+1];
                int bottom = next[j];
                int diagonal = next[j+1];

                if(matrix[i][j] == '1'){
                    curr[j] = 1 + min(right, min(diagonal, bottom));
                    maxi = max(maxi, curr[j]);
                }

                else curr[j] = 0;
            }
            next = curr;
        }
        return maxi;
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // int maxi = 0;
        // solve(matrix, 0, 0, maxi);
        // return maxi*maxi;

        // int maxi = 0;
        // vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(), -1));
        // solveMem(matrix, 0, 0, maxi, dp);
        // return maxi*maxi;
        
        // int maxi = 0;
        // solveTab(matrix, 0, 0, maxi);
        // return maxi*maxi;

        int maxi = 0;
        solveSpace(matrix, 0, 0, maxi);
        return maxi*maxi;
    }
};