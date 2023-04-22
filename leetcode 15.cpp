class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        if(nums[0] > 0) return ans;

        for(int i=0; i<n; i++){
            if(nums[i] > 0) break;

            if( i>0 && nums[i] == nums[i-1]) continue;

            int low = i+1, high = n-1;
            int sum = 0;
            while(low < high){
                sum = nums[i] + nums[low] + nums[high];
                
                if(sum > 0) high--;
                
                else if(sum < 0) low++;
                
                else{
                    ans.push_back({nums[i], nums[low], nums[high]});
                    int last_low_occurence = nums[low], last_high_occurence = nums[high];

                    while(low < high && nums[high] == last_high_occurence) high--;
                    while(low < high &&nums[low] == last_low_occurence) low++;
                }
            }
        }

        return ans;
    }
};