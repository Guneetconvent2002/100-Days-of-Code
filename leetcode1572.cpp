class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();

        int ans = 0;

        for(int i=0, j=0; i<n, j<n; i++, j++){
            ans += mat[i][j];
            ans += mat[i][n-1-j];
        }

        // if n is odd, subtract the mid element from the ans
        if(n%2 != 0) ans -= mat[n/2][n/2];

        return ans;
    }
};