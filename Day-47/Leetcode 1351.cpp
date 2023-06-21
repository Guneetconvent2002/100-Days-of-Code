class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, n = grid[0].size();
        int currRowNegativeIndex = n-1;
        for(auto arr : grid){
            while(currRowNegativeIndex >= 0 && arr[currRowNegativeIndex] < 0) currRowNegativeIndex--;

            ans += (n - (currRowNegativeIndex + 1));
        }
        return ans;
    }
};