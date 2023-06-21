class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool signChange = false;
        
        for(auto num : nums){
            if(num == 0) return 0;
            if(num < 0) signChange = !signChange;
        }

        if(signChange) return -1;
        return 1;
    }
};