class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left=0, right = letters.size()-1;

        int diff = INT_MAX;
        char ans = target;
        
        while(left <= right){
            int mid = left + (right - left) / 2;

            if(letters[mid] > target){
                if(letters[mid] - target < diff){
                    diff = letters[mid] - target;
                    ans = letters[mid];
                }
                right = mid - 1;
            }

            else left = mid + 1;
        }

        return ans == target ? letters[0] : ans;
    }
};