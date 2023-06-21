class Solution {
private:
    string convert(vector<int> arr){
        string ans;
        for(auto ele : arr) ans += to_string(ele) + ",";
        ans.pop_back();
        return ans;
    }

public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> map;
        
        // find frequencies of every row
        for(auto arr : grid){
            map[convert(arr)]++;
        }

        // add the number of similar rows to ans
        int ans = 0, n = grid.size();

        for(int i=0; i<n; i++){
            string s = "";

            for(int j=0; j<n; j++){
                s += to_string(grid[j][i]) + ",";
            }
            s.pop_back();
            ans += map[s];
        }
        return ans;
    }
};