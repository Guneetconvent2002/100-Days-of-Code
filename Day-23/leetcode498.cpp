class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row=0, col=0, n=mat.size(), m = mat[0].size();
        
        vector<int> ans;

        bool goingUp = true;

        while(row<n && col<m){
            ans.push_back(mat[row][col]);
            
            int newRow = row + (goingUp == 1 ? -1 : 1);
            int newCol = col + (goingUp == 1 ? 1 : -1);

            if(newRow < 0 || newRow == n || newCol < 0 || newCol == m){
                if(goingUp == 1){
                    row += (col == m - 1 ? 1 : 0);
                    col += (col < m - 1 ? 1 : 0);
                }
                else{
                    col += (row == n-1 ? 1 : 0);
                    row += (row < n-1 ? 1 : 0);
                }

                goingUp = !goingUp;
            }

            else{
                row = newRow;
                col = newCol;
            }
        }

        return ans;
    }
};