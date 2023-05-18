class Solution {
public:

    int MOD = 1000000007;

    // Using recursion and memoization

    int solve(int low, int high, int zeros, int ones, int end, vector<int> &dp){
        if(end == 0) return 1;
        if(end < 0) return 0;

        if(dp[end] != -1) return dp[end];

        int count = 0;

        if(end >= ones) count += solve(low, high, zeros, ones, end - ones, dp);
        if(end >= zeros) count += solve(low, high, zeros, ones, end - zeros, dp);

        return dp[end] = count % MOD;
    }

    // Using Tabulation

    int solve(int low, int high, int zeros, int ones){
        vector<int> dp(high + 1, 0);
        dp[0] = 1;

        for(int i=low; i<=high; i++){
            e
        }
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;

        vector<int> dp(high + 1, -1);
        dp[0] = 1;
        
        for(int i=low; i<=high; i++){
            ans += solve(low, high, zero, one, i, dp);
            ans %= MOD;
        }

        return ans;
    }
};