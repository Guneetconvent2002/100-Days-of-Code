class Solution {
public:

    int solve(vector<int>& nums, int i, vector<int>& dp){
        if(i==0 || i==1) return nums[i];
        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];

        int incl = nums[i] + solve(nums, i-2, dp);
        int excl = solve(nums, i-1, dp);

        return dp[i] = max(incl, excl);
    }

    int solve(vector<int>& nums){
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; i++){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }

        return max(dp[n-1], dp[n-2]);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, -1);
        // return max(solve(nums, n-1, dp), solve(nums, n-2, dp));
        return solve(nums);
    }
};