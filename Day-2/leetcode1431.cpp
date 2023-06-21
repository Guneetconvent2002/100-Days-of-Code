class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0;
        for(auto candy : candies){
            mx = max(mx, candy);
        }

        vector<bool> ans;
        for(auto candy : candies){
            if(candy + extraCandies >= mx) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};