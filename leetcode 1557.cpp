class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> v(n, false);

        for(auto edge : edges){
            v[edge[1]] = true;
        }

        vector<int> ans;

        for(int i=0; i<n; i++){
            if(!v[i]) ans.push_back(i);
        }

        return ans;
    }
};