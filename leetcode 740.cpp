class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto num : nums) m[num]++;

        vector<int> v(m.size());
        for(auto val : m) v.push_back(val.first);
        sort(v.begin(), v.end());

        vector<int> dp(v.size() + 1, 0);

        int n = v.size();

        for(int i=n-1; i>=0; i--) {
            int notpick = 0 + dp[i + 1];
            int pick = m[v[i]] * v[i];
            if(i + 1 < n && v[i] + 1 == v[i + 1]) pick += dp[i + 2];
            else if(i + 1 < n && v[i] + 1 != v[i + 1]) pick += dp[i + 1];
            dp[i] = max(pick, notpick);
        }

        return dp[0];        
    }
};