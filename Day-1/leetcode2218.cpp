class Solution {
public:

    int solve(vector<vector<int>>& piles, int k, int endPileIdx){
        // endPileIdx = piles.size() - 1

        // base cases
        if(endPileIdx < 0 || k == 0) return 0;

        // how many coins can I pick in this single stack??
        int currPileSize = piles[endPileIdx].size();
        int maxCanPick = min(k, currPileSize);

        // Didn't pick this coin
        int maxSum = solve(piles, k, endPileIdx - 1);

        // picking as many coins as I can
        int pickedSum = 0;
        for(int i=0; i<maxCanPick; i++){
            pickedSum += piles[endPileIdx][i];
            int netSum = solve(piles, k-i-1, endPileIdx-1);
            maxSum = max(pickedSum + netSum, maxSum);
        }

        return maxSum;
    }

    int solveMem(vector<vector<int>>& piles, int k, int endPileIdx, vector<vector<int>> &dp){
        // endPileIdx = piles.size() - 1

        // base cases
        if(endPileIdx < 0 || k == 0) return 0;

        if(dp[endPileIdx][k] != -1) return dp[endPileIdx][k];

        // how many coins can I pick in this single stack??
        int currPileSize = piles[endPileIdx].size();
        int maxCanPick = min(k, currPileSize);

        // Didn't pick this coin
        int maxSum = solveMem(piles, k, endPileIdx - 1, dp);
        int pickedSum = 0;

        // picking as many coins as I can
        for(int i=0; i<maxCanPick; i++){
            pickedSum += piles[endPileIdx][i];
            int netSum = solveMem(piles, k-i-1, endPileIdx-1, dp);
            maxSum = max(pickedSum + netSum, maxSum);
        }

        return dp[endPileIdx][k] = maxSum;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
        return solveMem(piles, k, n-1, dp);
    }
};