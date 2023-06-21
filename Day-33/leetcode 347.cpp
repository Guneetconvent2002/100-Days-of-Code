class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(auto num : nums) freq[num]++;

        priority_queue<pair<int, int>> pq; // freq, key

        for(auto f : freq) pq.push({f.second, f.first});

        vector<int> ans;

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};