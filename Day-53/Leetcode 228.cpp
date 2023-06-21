class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        if(n == 1) return {to_string(nums[0])};
        if(n == 2){
            if (nums[1] == nums[0] + 1) return {to_string(nums[0]) + "->" + to_string(nums[1])};
            else return {to_string(nums[0]), to_string(nums[1])};
        }

        vector<string> ans;

        int start = 0, end = 0;

        while(end < n){
            // traverse karte raho till the point you want to find a gap
            while(end < n-1 && nums[end+1] == nums[end] + 1){
                end++;
            }
            
            if(start == end){
                ans.push_back(to_string(nums[start]));
                start++;
                end++;
            }

            else{
                // print the current start as 
                ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
                end++;
                start = end;

            }
        }

        return ans;
    }
};